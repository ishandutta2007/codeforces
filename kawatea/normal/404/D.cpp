#include <cstdio>
#include <cstring>

using namespace std;

char s[1000001];
long long dp[1000000][3];

int main()
{
    int n, m = 1000000007, i, j;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n == 1) {
        if (s[0] == '1' || s[0] == '2') {
            puts("0");
        } else if (s[0] == '*' || s[0] == '0') {
            puts("1");
        } else {
            puts("2");
        }
        
        return 0;
    }
    
    if (s[0] == '*') {
        dp[0][2] = 1;
    } else if (s[0] == '0') {
        dp[0][0] = 1;
    } else if (s[0] == '1') {
        dp[0][1] = 1;
    } else if (s[0] == '2') {
        puts("0");
        
        return 0;
    } else {
        dp[0][0] = dp[0][1] = dp[0][2] = 1;
    }
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (dp[i - 1][j] == 0) continue;
            
            if (s[i] == '*') {
                if (j != 0) {
                    dp[i][2] += dp[i - 1][j];
                    if (dp[i][2] >= m) dp[i][2] -= m;
                }
            } else if (s[i] == '0') {
                if (j == 0) {
                    dp[i][0] += dp[i - 1][j];
                    if (dp[i][0] >= m) dp[i][0] -= m;
                }
            } else if (s[i] == '1') {
                if (j == 0) {
                    dp[i][1] += dp[i - 1][j];
                    if (dp[i][1] >= m) dp[i][1] -= m;
                } else if (j == 2) {
                    dp[i][0] += dp[i - 1][j];
                    if (dp[i][0] >= m) dp[i][0] -= m;
                }
            } else if (s[i] == '2') {
                if (j == 2) {
                    dp[i][1] += dp[i - 1][j];
                    if (dp[i][1] >= m) dp[i][1] -= m;
                }
            } else {
                if (j == 0) {
                    dp[i][0] += dp[i - 1][j];
                    if (dp[i][0] >= m) dp[i][0] -= m;
                    dp[i][1] += dp[i - 1][j];
                    if (dp[i][1] >= m) dp[i][1] -= m;
                } else if (j == 1) {
                    dp[i][2] += dp[i - 1][j];
                    if (dp[i][2] >= m) dp[i][2] -= m;
                } else {
                    dp[i][0] += dp[i - 1][j];
                    if (dp[i][0] >= m) dp[i][0] -= m;
                    dp[i][1] += dp[i - 1][j];
                    if (dp[i][1] >= m) dp[i][1] -= m;
                    dp[i][2] += dp[i - 1][j];
                    if (dp[i][2] >= m) dp[i][2] -= m;
                }
            }
        }
    }
    
    printf("%I64d\n", (dp[n - 1][0] + dp[n - 1][2]) % m);
    
    return 0;
}