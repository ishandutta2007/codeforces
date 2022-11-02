#include <stdio.h>

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    if (n < m) {
        printf("%d\n", n + 1);
        
        for (i = 0; i <= n; i++) printf("%d %d\n", i, n - i);
    } else {
        printf("%d\n", m + 1);
        
        for (i = 0; i <= m; i++) printf("%d %d\n", i, m - i);
    }
    
    return 0;
}