#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *length);
void output(int *a, int length);
int sorted(int *a, int n);

int main() {
    int n, result;
    int *data = NULL;
    if (scanf("%d", &n) == 1 && n > 0) {
        data = malloc(sizeof(int) * n);
        if (data != NULL) {
            result = input(data, &n);
            if (result) {
                sorted(data, n);
                output(data, n);
            } else {
                printf("n/a");
            }
            free(data);
            *data = NUL;
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *length) {
    int rtn = 0;
    for (int *p = a; p - a < *length; p++) {
        char ch;
        if (scanf("%d", p) != 1) break;
        ch = getchar();
        if (ch != ' ') {
            if (ch == '\n' && p - a + 1 == *length) {
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}

void output(int *a, int length) {
    for (int *p = a; p - a < length; p++) {
        printf("%d", *p);
        if (p - a + 1 != length)
            printf(" ");
    }
}

int sorted(int *a, int n) {
    int temporary;
    for (int *p = a; p - a < n - 1; p++) {
        for (int *i = a; i - a < n - 1; i++) {
            if (*i > *(i + 1)) {
                temporary = *i;
                *i = *(i + 1);
                *(i + 1) = temporary;
            }
        }
    }
    return 0;
}
