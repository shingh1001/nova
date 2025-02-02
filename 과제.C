#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char fname[100];
    char *buffer;
    int start, end, current_line = 1;
    size_t buffer_size = 100;

    printf("파일의 이름을 입력하시오.\n");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;  
    } else {
        printf("파일 열기 성공\n");
    }

    printf("출력할 시작 줄 번호를 입력하시오.\n");
    scanf("%d", &start);
    printf("출력할 끝 줄 번호를 입력하시오.\n");
    scanf("%d", &end);

    buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        printf("메모리 할당 실패\n");
        fclose(fp);
        return 1;  
    }

    while (fgets(buffer, buffer_size, fp) != NULL) {
        if (current_line >= start && current_line <= end) {
            printf("%s", buffer); 
        }
        current_line++;

        if (current_line > end) {
            break;
        }
    }

    free(buffer);
    fclose(fp);

    return 0;
}