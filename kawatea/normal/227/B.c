#include <stdio.h>

int main()
{
    int n, m, i;
    long long x = 0, y = 0;
    int a[100001];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int p;
        
        scanf("%d", &p);
        
        a[p] = i + 1;
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int p;
        
        scanf("%d", &p);
        
        x += a[p];
        y += n - a[p] + 1;
    }
    
    printf("%I64d %I64d\n", x, y);
    
    return 0;
}