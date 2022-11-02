#include <stdio.h>

int main()
{
    long long a, b, w, x, c, t = 0, i;
    long long dp[1001][2];
    
    scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &w, &x, &c);
    
    for (i = 0; i <= w; i++) dp[i][0] = -1;
    
    dp[b][0] = 0;
    dp[b][1] = a;
    
    while (1) {
        if (c <= a) break;
        
        if (b >= x) {
            b -= x;
        } else {
            a--;
            b = w - (x - b);
        }
        
        t++;
        c--;
        
        if (dp[b][0] >= 0) {
            long long p = t - dp[b][0];
            long long q = dp[b][1] - a;
            long long l = 0, r = 2e9, m = (l + r) / 2;
            
            while (r - l > 1) {
                if (c - m * p <= a - m * q) {
                    r = m;
                    m = (l + r) / 2;
                } else {
                    l = m;
                    m = (l + r) / 2;
                }
            }
            
            t += l * p;
            a -= l * q;
            c -= l * p;
            
            while (1) {
                if (c <= a) break;
                
                if (b >= x) {
                    b -= x;
                } else {
                    a--;
                    b = w - (x - b);
                }
                
                t++;
                c--;
            }
        } else {
            dp[b][0] = t;
            dp[b][1] = a;
        }
    }
    
    printf("%I64d\n", t);
    
    return 0;
}