#include <stdio.h>

int main()
{
    int n, m, i;
    long long sum = 0;
    long long a[100000];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            int y;
            long long z;
            
            scanf("%d %I64d", &y, &z);
            
            a[y - 1] = z - sum;
        } else if (x == 2) {
            long long y;
            
            scanf("%I64d", &y);
            
            sum += y;
        } else {
            int y;
            
            scanf("%d", &y);
            
            printf("%I64d\n", a[y - 1] + sum);
        }
    }
    
    return 0;
}