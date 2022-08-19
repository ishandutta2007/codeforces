#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <bitset>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> color(n, -1);
    std::vector<std::vector<int>> cp;
    std::vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1)
            continue;
        color[i] = 0;
        std::queue<int> que;
        que.push(i);
        cp.emplace_back();
        int c0 = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            cp.back().push_back(u);
            c0 += color[u];
            for (auto v : e[u]) {
                if (color[v] == -1) {
                    que.push(v);
                    color[v] = color[u] ^ 1;
                } else if (color[u] == color[v]) {
                    std::cout << "NO\n";
                    return 0;
                }
            }
        }
        cnt.push_back(c0);
    }
    const int c = cp.size();
    std::vector<std::bitset<5001>> dp(c + 1);
    dp[0][0] = 1;
    for (int i = 0; i < c; ++i)
        dp[i + 1] = dp[i] << cnt[i] | dp[i] << (cp[i].size() - cnt[i]);
    if (!dp[c][n2]) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    std::string ans(n, '1');
    for (int i = c - 1; i >= 0; --i) {
        int x;
        if (n2 >= cnt[i] && dp[i][n2 - cnt[i]]) {
            x = 1;
        } else {
            x = 0;
        }
        for (auto u : cp[i]) {
            if (color[u] == x) {
                ans[u] = '2';
                --n2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == '1' && n3 > 0) {
            --n3;
            ans[i] = '3';
        }
    }
    std::cout << ans << "\n";
    return 0;
}