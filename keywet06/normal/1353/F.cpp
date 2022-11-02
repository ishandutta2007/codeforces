#include <bits/stdc++.h>

using int64 = long long;

const int64 INF = 1e18;
const int N = 105;

int T, n, m;

int64 ans, ze;
int64 a[N][N], dp[N][N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        ze = a[0][0], ans = INF;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                int64 need = a[x][y] - x - y;
                if (need > ze) continue;
                a[0][0] = need;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) dp[i][j] = INF;
                }
                dp[0][0] = ze - need;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        int64 need = a[0][0] + i + j;
                        if (need > a[i][j]) continue;
                        if (i > 0) {
                            dp[i][j] = std::min(dp[i][j],
                                                dp[i - 1][j] + a[i][j] - need);
                        }
                        if (j > 0) {
                            dp[i][j] = std::min(dp[i][j],
                                                dp[i][j - 1] + a[i][j] - need);
                        }
                    }
                }
                ans = std::min(ans, dp[n - 1][m - 1]);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}