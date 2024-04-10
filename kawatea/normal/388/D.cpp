#include <cstdio>

using namespace std;

int a[50];
long long c[50][50];
long long dp[50][50][2];

int main()
{
    int x = 0, m = 1000000007, i, j, l, r;
    long long k, ans = 0;
    
    for (i = 0; i < 50; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    
    scanf("%I64d", &k);
    
    while (k) {
        a[x++] = k & 1;
        k >>= 1;
    }
    
    dp[0][0][0] = 1;
    
    for (i = 0; i < x; i++) {
        for (j = 0; j <= i; j++) {
            for (l = 0; l < 2; l++) {
                if (dp[i][j][l] == 0) continue;
                
                if (l == 0 && a[x - i - 1] == 0) {
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][l]) % m;
                } else {
                    dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][l]) % m;
                    dp[i + 1][j + 1][l] = (dp[i + 1][j + 1][l] + dp[i][j][l]) % m;
                    if (j > 0) dp[i + 1][j][l] = (dp[i + 1][j][l] + dp[i][j][l] * j) % m;
                }
                
                for (r = 2; r <= j; r++) {
                    if (r & 1) {
                        if (l == 1 || a[x - i - 1] == 1) dp[i + 1][j][l] = (dp[i + 1][j][l] + dp[i][j][l] * c[j][r]) % m;
                    } else {
                        if (a[x - i - 1] == 1) {
                            dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][l] * c[j][r]) % m;
                        } else {
                            dp[i + 1][j][l] = (dp[i + 1][j][l] + dp[i][j][l] * c[j][r]) % m;
                        }
                    }
                }
            }
        }
    }
    
    for (i = 0; i <= x; i++) {
        for (j = 0; j < 2; j++) {
            ans += dp[x][i][j];
        }
    }
    
    printf("%I64d\n", ans % m);
    
    return 0;
}