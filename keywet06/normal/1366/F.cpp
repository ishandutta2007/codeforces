#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i] >> w[i];
        --u[i], --v[i];
    }
    std::vector<long long> dp(n, -1e18), b(m, -1e18);
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i) {
        std::vector<long long> newDp(n, -1e18);
        for (int j = 0; j < m; ++j) {
            newDp[v[j]] = std::max(newDp[v[j]], dp[u[j]] + w[j]);
            newDp[u[j]] = std::max(newDp[u[j]], dp[v[j]] + w[j]);
        }
        dp = std::move(newDp);
        for (int j = 0; j < m; ++j) {
            b[j] = std::max(b[j], std::max(dp[u[j]], dp[v[j]]) - i * w[j]);
        }
        ans = (ans + *std::max_element(dp.begin(), dp.end())) % P;
    }
    for (int i = 0; i < m; ++i) {
        long long l = n, r = q;
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            long long k = w[i] - w[j];
            long long a = b[j] - b[i] + (j < i);
            if (!k) {
                if (a > 0) r = 0;
            } else if (k > 0) {
                l = std::max(l, (a + k - 1) / k);
            } else {
                r = std::min(r, a / k);
            }
        }
        if (l <= r) {
            ans = (ans + (l + r) * (r - l + 1) / 2 % P * w[i] +
                   (b[i] % P + P) * (r - l + 1)) %
                  P;
        }
    }
    std::cout << ans << "\n";
    return 0;
}