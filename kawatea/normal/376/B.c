#include <stdio.h>

int main()
{
    int n, m, ans = 0, i;
    int a[100] = {0};
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        a[x - 1] += z;
        a[y - 1] -= z;
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] > 0) ans += a[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}