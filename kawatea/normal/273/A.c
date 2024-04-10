#include <stdio.h>

int main()
{
    int n, m, i, j;
    long long p = 0;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        if (a[x] > p) {
            printf("%d\n", a[x]);
            
            p = a[x] + y;
        } else {
            printf("%I64d\n", p);
            
            p += y;
        }
    }
    
    return 0;
}