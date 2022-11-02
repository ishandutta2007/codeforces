#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    int b = std::sqrt(n), bl = (n + b - 1) / b;
    std::vector<std::vector<int>> a(n);
    std::vector<int64_t> sum(n);
    std::vector<std::vector<int64_t>> pre(bl + 1, std::vector<int64_t>(k + 1)),
        suf(pre);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        if (m > k) a[i].resize(m = k);
        sum[i] = std::accumulate(a[i].begin(), a[i].end(), 0ll);
    }

    for (int i = 0; i < bl; ++i) {
        pre[i + 1] = pre[i];
        for (int j = i * b; j < std::min((i + 1) * b, n); ++j) {
            for (int x = k; x >= int(a[j].size()); --x) {
                pre[i + 1][x] = std::max(pre[i + 1][x],
                                         pre[i + 1][x - a[j].size()] + sum[j]);
            }
        }
    }
    for (int i = bl - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        for (int j = i * b; j < std::min((i + 1) * b, n); ++j) {
            for (int x = k; x >= int(a[j].size()); --x) {
                suf[i][x] =
                    std::max(suf[i][x], suf[i][x - a[j].size()] + sum[j]);
            }
        }
    }
    int64_t ans = pre[bl][k];
    for (int i = 0; i < bl; ++i) {
        std::vector<int64_t> dp(k + 1);
        for (int x = 0; x <= k; ++x) {
            for (int y = 0; x + y <= k; ++y) {
                dp[x + y] = std::max(dp[x + y], pre[i][x] + suf[i + 1][y]);
            }
        }
        for (int j = i * b; j < std::min((i + 1) * b, n); ++j) {
            auto f(dp);
            for (int x = i * b; x < std::min((i + 1) * b, n); ++x) {
                if (x != j) {
                    for (int y = k; y >= int(a[x].size()); --y) {
                        f[y] = std::max(f[y], f[y - a[x].size()] + sum[x]);
                    }
                }
            }
            int64_t s = 0;
            for (int x = 0; x < int(a[j].size()); ++x) {
                s += a[j][x];
                ans = std::max(ans, s + f[k - 1 - x]);
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}