#include <stdio.h>

int main()
{
    int n, m, mod = 1000000000, i, j;
    int a[100];
    long long fib[100];
    
    fib[0] = fib[1] = 1;
    
    for (i = 2; i < 100; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            int y, z;
            
            scanf("%d %d", &y, &z);
            
            a[y - 1] = z;
        } else if (x == 2) {
            int y, z;
            long long sum = 0;
            
            scanf("%d %d", &y, &z);
            
            y--;
            z--;
            
            for (j = 0; j <= z - y; j++) {
                sum = (sum + a[y + j] * fib[j] % mod) % mod;
            }
            
            printf("%d\n", (int)sum);
        }
    }
    
    return 0;
}