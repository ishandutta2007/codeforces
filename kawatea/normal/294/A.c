#include <stdio.h>

int main()
{
    int n, m, i, j;
    int a[100];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        if (x != 0) a[x - 1] += y - 1;
        if (x != n - 1) a[x + 1] += a[x] - y;
        
        a[x] = 0;
    }
    
    for (i = 0; i < n; i++) printf("%d\n", a[i]);
    
    return 0;
}