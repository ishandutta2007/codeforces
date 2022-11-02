#include <stdio.h>

int main()
{
    int n, x, p = 1e9 + 1, q = -1, i;
    long long a[100000];
    
    scanf("%d %d", &n, &x);
    
    for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
    
    x--;
    
    for (i = x; i >= 0; i--) {
        if (a[i] < p) {
            p = a[i];
            q = i;
        }
    }
    
    for (i = n - 1; i > x; i--) {
        if (a[i] < p) {
            p = a[i];
            q = i;
        }
    }
    
    if (q <= x) {
        long long y = (long long)p * n + x - q;
        long long z = p;
        
        for (i = 0; i < q; i++) a[i] -= z;
        for (i = q + 1; i <= x; i++) a[i] -= z + 1;
        for (i = x + 1; i < n; i++) a[i] -= z;
        
        a[q] = y;
    } else {
        long long y = (long long)p * n + n - q + x;
        long long z = p;
        
        for (i = 0; i <= x; i++) a[i] -= z + 1;
        for (i = x + 1; i < q; i++) a[i] -= z;
        for (i = q + 1; i < n; i++) a[i] -= z + 1;
        
        a[q] = y;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", a[i]);
    }
    
    puts("");
    
    return 0;
}