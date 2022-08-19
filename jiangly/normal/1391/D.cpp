#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    if (n >= 4) {
        std::cout << -1 << "\n";
        return 0;
    }
    if (n == 1) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            a[i] = 2 * a[i] + s[j][i] - '0';
    std::vector<std::vector<int>> dp(m, std::vector<int>(1 << n, 1e9));
    for (int i = 0; i < (1 << n); ++i)
        dp[0][i] = __builtin_popcount(a[0] ^ i);
    for (int i = 1; i < m; ++i) {
        for (int s = 0; s < (1 << n); ++s) {
            for (int x = 0; x < 2; ++x) {
                int t = x;
                t |= (x ^ (s & 1) ^ (s >> 1 & 1) ^ 1) << 1;
                if (n == 3)
                    t |= ((t >> 1) ^ (s >> 1 & 1) ^ (s >> 2) ^ 1) << 2;
                dp[i][t] = std::min(dp[i][t], dp[i - 1][s] + __builtin_popcount(a[i] ^ t));
            }
        }
    }
    std::cout << *std::min_element(dp[m - 1].begin(), dp[m - 1].end()) << "\n";
    return 0;
}