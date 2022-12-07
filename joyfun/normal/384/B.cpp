#include <stdio.h>
#include <string.h>

int n, m, k;


int main () {
    int i, j;
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%*d");
    printf("%d\n", m * (m - 1) / 2);
    
    if (k == 0) {
        for (i = m - 1; i >= 1; i--)
            for (j = 1; j <= i; j++) {
                printf("%d %d\n", j, j + 1);
            }
    }
    else {
        for (i = m; i > 1; i--)
            for (j = m; j > 1 + m - i; j--) {
                printf("%d %d\n", j, j - 1);
            }
    }
    return 0;
}