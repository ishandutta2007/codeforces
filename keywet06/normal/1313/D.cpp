#include <bits/stdc++.h>

int n, m, k;

std::vector<int> l, r, x, pos, mx;

std::vector<std::vector<int>> dp, f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    l.resize(n);
    r.resize(n);
    x.reserve(2 * n);
    pos.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
        --l[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    f.resize(x.size());
    for (int i = 0; i < n; ++i) {
        l[i] = std::lower_bound(x.begin(), x.end(), l[i]) - x.begin();
        r[i] = std::lower_bound(x.begin(), x.end(), r[i]) - x.begin();
        for (int j = l[i]; j < r[i]; ++j) f[j].push_back(i);
    }
    dp.assign(2, std::vector<int>(1 << k));
    int cur = 0;
    for (int i = 0; i < (1 << f[0].size()); ++i) {
        dp[cur][i] = (x[1] - x[0]) * __builtin_parity(i);
    }
    for (int i = 1; i < int(x.size()); ++i) {
        cur ^= 1;
        std::fill(dp[cur].begin(), dp[cur].end(), 0);
        int t = 0;
        for (int j = 0; j < int(f[i].size()); ++j) pos[f[i][j]] = j;
        mx.assign(1 << k, 0);
        std::function<void(int, int, int)> dfs = [&](int x, int m1, int m2) {
            if (x == int(f[i - 1].size())) {
                mx[m2] = std::max(mx[m2], dp[cur ^ 1][m1]);
                return;
            }
            if (pos[f[i - 1][x]] == -1) {
                dfs(x + 1, m1 | 1 << x, m2);
            } else {
                t |= 1 << pos[f[i - 1][x]];
                dfs(x + 1, m1 | 1 << x, m2 | 1 << pos[f[i - 1][x]]);
            }
            dfs(x + 1, m1, m2);
        };
        dfs(0, 0, 0);
        for (int j = 0; j < (1 << f[i].size()); ++j) {
            dp[cur][j] = mx[j & t] + (x[i + 1] - x[i]) * __builtin_parity(j);
        }
        for (int j = 0; j < int(f[i].size()); ++j) pos[f[i][j]] = -1;
    }
    std::cout << *std::max_element(dp[cur].begin(), dp[cur].end()) << "\n";
    return 0;
}