#include <stdio.h>

char dp[23][1 << 23];

int main()
{
    int n, ans = 1e9, i, j, k;
    int a[23];
    int b[23][23] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 1; i < n; i++) {
        int f = 0;
        
        for (j = 0; j < i; j++) {
            for (k = j; k < i; k++) {
                if (a[j] + a[k] == a[i]) {
                    b[i][j] = 1 << k;
                    
                    f = 1;
                }
            }
        }
        
        if (f == 0) {
            puts("-1");
            
            return 0;
        }
    }
    
    dp[0][1] = 1;
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < (1 << i); j++) {
            int f = 0;
            
            if (dp[i - 1][j] == 0) continue;
            
            for (k = 0; k < i; k++) {
                if ((j >> k) & 1) {
                    if (j & b[i][k]) {
                        f = 1;
                        
                        break;
                    }
                }
            }
            
            if (f == 1) {
                for (k = 0; k < i; k++) {
                    if ((j >> k) & 1) dp[i][j ^ (1 << k) ^ (1 << i)] = 1;
                }
                
                dp[i][j ^ (1 << i)] = 1;
            }
        }
    }
    
    for (i = 0; i < (1 << n); i++) {
        if (dp[n - 1][i] == 1) {
            int c = 0;
            
            for (j = 0; j < n; j++) {
                if ((i >> j) & 1) c++;
            }
            
            if (c < ans) ans = c;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}