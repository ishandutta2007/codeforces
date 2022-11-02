#include <bits/stdc++.h>
const int B = 4;
const int K = 250;
const int N = 40000;
int n, m;
int a[N];
int dp[N][K][B];
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    memset(dp, 213, sizeof(dp));
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) dp[i][0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, x; j <= m; ++j) {
            if ((x = 1 + (j ^ 1 && j ^ m)) == 2) {
                dp[i][j][1] = dp[i - 1][j - 1][1];
                dp[i][j][3] = dp[i - 1][j - 1][3];
            }
            dp[i][j][1] = std::max(
                std::max(dp[i][j][1], dp[i - 1][j][1]),
                dp[i][j][0] =
                    std::max(dp[i - 1][j][0], dp[i - 1][j - 1][3]) - x * a[i]);
            dp[i][j][3] = std::max(
                std::max(dp[i][j][3], dp[i - 1][j][3]),
                dp[i][j][2] =
                    std::max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + x * a[i]);
        }
    }
    std::cout << std::max(dp[n][m][1], dp[n][m][3]) << std::endl;
    return 0;
}