#include <stdio.h>

int main()
{
    int n, m, k, i, j;
    
    scanf("%d %d %d", &n, &m, &k);
    
    printf("%d\n", m * (m - 1) / 2);
    
    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            if (k == 0) {
                printf("%d %d\n", i + 1, j + 1);
            } else {
                printf("%d %d\n", j + 1, i + 1);
            }
        }
    }
    
    return 0;
}