#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int i, int j) { return b[i] < b[j]; });
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, -1e9));
        std::vector<std::vector<bool>> g(n + 1, std::vector<bool>(k + 1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 0; --j) {
                if (j < k && dp[i][j] + a[p[i]] + b[p[i]] * j > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j] + a[p[i]] + b[p[i]] * j;
                    g[i + 1][j + 1] = 1;
                }
                dp[i + 1][j] = dp[i][j] + (k - 1) * b[p[i]];
            }
        }
        std::vector<int> o;
        int x = k;
        std::vector<bool> used(n);
        for (int i = n - 1; i >= 0; --i) {
            if (g[i + 1][x]) {
                --x;
                o.push_back(p[i] + 1);
                used[p[i]] = true;
            }
        }
        std::reverse(o.begin(), o.end());
        x = o.back();
        o.pop_back();
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                o.push_back(i + 1);
                o.push_back(-i - 1);
            }
        }
        o.push_back(x);
        int m = o.size();
        std::cout << m << "\n";
        for (int i = 0; i < m; ++i) std::cout << o[i] << " \n"[i == m - 1];
    }
    return 0;
}