#include <stdio.h>

int main()
{
    int n, m, i, j;
    int a[100] = {0};
    int b[100] = {0};
    
    scanf("%d %d", &n, &m);
    
    printf("%d\n", n + m - 1);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == 0 || b[j] == 0) printf("%d %d\n", i + 1, j + 1);
            
            a[i] = b[j] = 1;
        }
    }
    
    return 0;
}