#include <stdio.h>
#include <string.h>

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    if (m < n - 1 || m > (n + 1) * 2) {
        printf("-1\n");
        return 0;
    }
    if (m - (n - 1) * 2 == 1)
        printf("1");
    if (m - (n - 1) * 2 >= 2)
        printf("11");
    int mm;
    if (m > (n - 1) * 2) mm = (n - 1) * 2;
    else mm = m;
    int m2 = mm - (n - 1);
    int m1 = (n - 1) - m2;
    int nn = n;
    while (m2--) {
        if (nn--) printf("0");
        printf("11");
    }
    while (m1--) {
        if (nn--) printf("0");
        printf("1");
    }
    if (nn--)printf("0");
    if (m - (n - 1) * 2 == 3)
        printf("1");
    if (m - (n - 1) * 2 == 4)
        printf("11");
    printf("\n");
    return 0;
}