#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> l(n, std::vector<int>(m)),
        r(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int a, b;
            std::cin >> a >> b;
            --a;
            for (int x = a; x < b; ++x) {
                l[i][x] = a;
                r[i][x] = b;
            }
        }
    }
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(m + 1));
    for (int len = 1; len <= m; ++len) {
        for (int a = 0; a + len <= m; ++a) {
            int b = a + len;
            for (int i = a; i < b; ++i) {
                int res = 0;
                for (int j = 0; j < n; ++j) {
                    res += (l[j][i] >= a) && (r[j][i] <= b);
                }
                dp[a][b] =
                    std::max(dp[a][b], dp[a][i] + dp[i + 1][b] + res * res);
            }
        }
    }
    std::cout << dp[0][m] << "\n";
    return 0;
}