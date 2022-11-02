#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }
        std::vector<int> mx(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) mx[i] = std::max(mx[i], a[j][i]);
        }
        std::vector<int> p(m);
        for (int i = 0; i < m; ++i) p[i] = i;
        std::sort(p.begin(), p.end(),
                  [&](int a, int b) { return mx[a] > mx[b]; });
        std::vector<std::vector<int>> dp(2, std::vector<int>(1 << n));
        for (int i = 0; i < std::min(n, m); ++i) {
            swap(dp[0], dp[1]);
            dp[1].assign(1 << n, 0);
            for (int mask = 0; mask < (1 << n); ++mask) {
                int tmp = 0;
                for (int x = 0; x < n; ++x) {
                    int res = 0;
                    for (int j = 0; j < n; ++j) {
                        if (mask >> j & 1) {
                            res += a[(x + j) % n][p[i]];
                        }
                    }
                    tmp = std::max(tmp, res);
                }
                int other = ((1 << n) - 1) ^ mask;
                for (int s = other; s > 0; s = (s - 1) & other) {
                    dp[1][s | mask] = std::max(dp[1][s | mask], dp[0][s] + tmp);
                }
                dp[1][mask] = std::max(dp[1][mask], tmp);
            }
        }
        std::cout << dp[1][(1 << n) - 1] << std::endl;
    }
    return 0;
}