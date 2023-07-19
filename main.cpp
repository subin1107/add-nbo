#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <arpa/inet.h>

void add_nbo(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "rb");
    FILE* f2 = fopen(file2, "rb");

    if (f1 == NULL || f2 == NULL) {
        printf("파일이 없습니다.\n");
        return;
    }

    uint32_t num1;
    uint32_t num2;

    fread(&num1, sizeof(num1), 1, f1);
    fread(&num2, sizeof(num2), 1, f2);

    fclose(f1);
    fclose(f2);

    uint32_t sum = ntohl(num1) + ntohl(num2);

    printf("%u(0x%X) + %u(0x%X) = %u(0x%X)\n", ntohl(num1), ntohl(num1), ntohl(num2), ntohl(num2), sum, sum);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Syntax: add-nbo <file1> <file2>\n");
        return 1;
    }

    add_nbo(argv[1], argv[2]);

    return 0;
}

