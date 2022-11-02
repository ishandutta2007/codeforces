#include <stdio.h>
#include <string.h>

int main()
{
    int k, n, m = 1000000007, i, j;
    long long ans = 0;
    int a[1000] = {0};
    long long dp[100001][2];
    char s1[1001], s2[1001];
    
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &k);
    
    n = strlen(s1);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s1[j] != s2[(i + j) % n]) break;
        }
        
        if (j == n) a[i] = 1;
    }
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for (i = 0; i < k; i++) {
        dp[i + 1][0] = dp[i][1] * (n - 1) % m;
        dp[i + 1][1] = (dp[i][0] + dp[i][1] * (n - 2)) % m;
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (i == 0) {
                ans = (ans + dp[k][0]) % m;
            } else {
                ans = (ans + dp[k][1]) % m;
            }
        }
    }
    
    printf("%d\n", (int)ans);
    
    return 0;
}