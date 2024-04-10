#include <stdio.h>

char f[1 << 24];
long long sum[1 << 24];
int dp[1 << 24];

int main()
{
    int n, k, m = 1000000007, i, j;
    int a[24];
    int b[2];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < (1 << i); j++) {
            sum[(1 << i) + j] = sum[j] + a[i];
        }
    }
    
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < k; j++) {
            if (sum[i] == b[j]) {
                f[i] = 1;
                
                break;
            }
        }
    }
    
    dp[0] = 1;
    
    for (i = 0; i < (1 << n); i++) {
        if (dp[i] == 0) continue;
        
        for (j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            
            if (f[i | (1 << j)] == 1) continue;
            
            dp[i | (1 << j)] += dp[i];
            
            if (dp[i | (1 << j)] >= m) dp[i | (1 << j)] -= m;
        }
    }
    
    printf("%d\n", dp[(1 << n) - 1]);
    
    return 0;
}