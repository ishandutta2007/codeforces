#include <stdio.h>
#include <string.h>

const int N = 305;

int n, a[N], v = -1;

int main() {
    scanf("%d", &n); int i;
    for (i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] != 0)
            v = i;
    }
    if (v == -1) {
        printf("\n");
        return 0;
    }
    for (i = 0; i <= v; i ++) {
        if (a[i] == 0) {
            if (i != v)
                printf("R");
        }
        else {
            while (a[i] --) {
                if (a[i] == 0) {
                    if (i != v)
                        printf("PR");
                    else
                        printf("P");
                }
                else {
                    if (i == 0) printf("PRL");
                    else printf("PLR");
                }
            }
        }
    }
    printf("\n");
    return 0;
}