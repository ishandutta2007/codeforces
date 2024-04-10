#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[10001][3][1 << 3][2];

int main()
{
    int n, m = 1000000007, i, j, k, l;
    char s[3][10001];
    
    scanf("%d", &n);
    
    for (i = 0; i < 3; i++) scanf("%s", s[i]);
    
    dp[0][0][0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < (1 << 3); k++) {
                for (l = 0; l < 2; l++) {
                    if (dp[i][j][k][l] == 0) continue;
                    
                    if ((k >> j) & 1) {
                        if (j == 2) {
                            dp[i + 1][0][k ^ (1 << j)][l] = (dp[i + 1][0][k ^ (1 << j)][l] + dp[i][j][k][l]) % m;
                        } else {
                            dp[i][j + 1][k ^ (1 << j)][l] = (dp[i][j + 1][k ^ (1 << j)][l] + dp[i][j][k][l]) % m;
                        }
                    } else if (s[j][i] != '.') {
                        if (j == 2) {
                            dp[i + 1][0][k][l] = (dp[i + 1][0][k][l] + dp[i][j][k][l]) % m;
                        } else {
                            dp[i][j + 1][k][l] = (dp[i][j + 1][k][l] + dp[i][j][k][l]) % m;
                        }
                    } else {
                        if (j < 2 && ((k >> (j + 1)) & 1) == 0 && s[j + 1][i] == '.') {
                            if ((j == 0 && s[j + 2][i] == 'O') || (j == 1 && s[j - 1][i] == 'O')) {
                                dp[i][j + 1][k ^ (1 << (j + 1))][1] = (dp[i][j + 1][k ^ (1 << (j + 1))][1] + dp[i][j][k][l]) % m;
                            } else {
                                dp[i][j + 1][k ^ (1 << (j + 1))][l] = (dp[i][j + 1][k ^ (1 << (j + 1))][l] + dp[i][j][k][l]) % m;
                            }
                        }
                        
                        if (i < n - 1 && s[j][i + 1] == '.') {
                            if ((i > 0 && s[j][i - 1] == 'O') || (i < n - 2 && s[j][i + 2] == 'O')) {
                                if (j == 2) {
                                    dp[i + 1][0][k ^ (1 << j)][1] = (dp[i + 1][0][k ^ (1 << j)][1] + dp[i][j][k][l]) % m;
                                } else {
                                    dp[i][j + 1][k ^ (1 << j)][1] = (dp[i][j + 1][k ^ (1 << j)][1] + dp[i][j][k][l]) % m;
                                }
                            } else {
                                if (j == 2) {
                                    dp[i + 1][0][k ^ (1 << j)][l] = (dp[i + 1][0][k ^ (1 << j)][l] + dp[i][j][k][l]) % m;
                                } else {
                                    dp[i][j + 1][k ^ (1 << j)][l] = (dp[i][j + 1][k ^ (1 << j)][l] + dp[i][j][k][l]) % m;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", (int)dp[n][0][0][1]);
    
    return 0;
}