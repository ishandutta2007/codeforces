#include <stdio.h>

int main()
{
    long long n, k;
    
    scanf("%I64d %I64d", &n, &k);
    
    if (k * (k - 1) / 2 + 1 < n) {
        puts("-1");
    } else {
        long long l, r, m;
        
        l = -1, r = k, m = (l + r) / 2;
        
        while (r - l > 1) {
            long long x = k * (k - 1) / 2 - (k - m) * (k - m - 1) / 2 + 1;
            
            if (x >= n) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        printf("%I64d\n", r);
    }
    
    return 0;
}