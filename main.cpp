#include <stdio.h>
#include "add.h"
#include <stdint.h>
#include <arpa/inet.h>
 
int main(int argc, char* argv[]) {

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (!file1 || !file2) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    uint32_t value1, value2;
    if (fread(&value1, sizeof(uint32_t), 1, file1) != 1 ||
        fread(&value2, sizeof(uint32_t), 1, file2) != 1) {
        fprintf(stderr, "Error reading files.\n");
        return 1;
    }

    fclose(file1);
    fclose(file2);

    value1 = htonl(value1);
    value2 = htonl(value2);

    uint32_t sum = add(value1, value2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", value1, value1, value2, value2, sum, sum);

    return 0;
}
