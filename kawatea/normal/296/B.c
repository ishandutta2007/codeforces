#include <stdio.h>

long long dp[100001][4];

int main()
{
    int n, m = 1000000007, i, j;
    char s1[100001], s2[100001];
    
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    
    dp[0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            if (dp[i][j] == 0) continue;
            
            if (s1[i] == '?') {
                if (s2[i] == '?') {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 10) % m;
                    dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j] * 45) % m;
                    dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j] * 45) % m;
                } else {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % m;
                    dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j] * (9 - s2[i] + '0')) % m;
                    dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j] * (s2[i] - '0')) % m;
                }
            } else {
                if (s2[i] == '?') {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % m;
                    dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j] * (s1[i] - '0')) % m;
                    dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j] * (9 - s1[i] + '0')) % m;
                } else {
                    if (s1[i] == s2[i]) {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % m;
                    } else if (s1[i] > s2[i]) {
                        dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % m;
                    } else {
                        dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % m;
                    }
                }
            }
        }
    }
    
    printf("%d\n", (int)dp[n][3]);
    
    return 0;
}