#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 105;
const int P = 1000000007;

int n, x;
int pw[N];
int dp[N][N][N][2][2];

string s;

int main() {
    cin >> n >> x;
    cin >> s;
    for (int i = 0; i < n; ++i) dp[s[i] != '0'][i][i][1][1] = 1;
    pw[0] = pw[1] = 2;
    for (int i = 2; i <= x; ++i) {
        int a = i - 1, b = i - 2;
        pw[i] = int64(pw[a]) * pw[b] % P;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                for (int fl = 0; fl < 2; ++fl) {
                    for (int fr = 0; fr < 2; ++fr) {
                        dp[i][l][r][fl][fr] =
                            (dp[i][l][r][fl][fr] + int64(dp[a][l][r][fl][fr])) %
                            P;
                        dp[i][l][r][fl][0] =
                            (dp[i][l][r][fl][0] +
                             int64(dp[a][l][r][fl][fr]) * (pw[b] - 1)) %
                            P;
                        dp[i][l][r][fl][fr] =
                            (dp[i][l][r][fl][fr] + int64(dp[b][l][r][fl][fr])) %
                            P;
                        dp[i][l][r][0][fr] =
                            (dp[i][l][r][0][fr] +
                             int64(dp[b][l][r][fl][fr]) * (pw[a] - 1)) %
                            P;
                        for (int m = l; m < r; ++m) {
                            dp[i][l][r][fl][fr] = (dp[i][l][r][fl][fr] +
                                                   int64(dp[a][l][m][fl][1]) *
                                                       dp[b][m + 1][r][1][fr]) %
                                                  P;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int fl = 0; fl < 2; ++fl) {
        for (int fr = 0; fr < 2; ++fr) {
            res = (res + dp[x][0][n - 1][fl][fr]) % P;
        }
    }
    printf("%d\n", res);
    return 0;
}