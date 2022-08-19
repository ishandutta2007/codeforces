#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int64_t> c;
        std::vector<int> siz(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            siz[u] = 1;
            for (auto v : e[u]) {
                if (v == p)
                    continue;
                dfs(v, u);
                siz[u] += siz[v];
                c.push_back(1ll * siz[v] * (n - siz[v]));
            }
        };
        dfs(0, -1);
        std::sort(c.begin(), c.end());
        int m;
        std::cin >> m;
        std::vector<int> p(m);
        for (int i = 0; i < m; ++i)
            std::cin >> p[i];
        std::sort(p.begin(), p.end());
        int ans = 0;
        if (m <= n - 1) {
            for (int i = 0; i < n - 1; ++i) {
                if (i + m < n - 1) {
                    ans = (ans + c[i]) % P;
                } else {
                    ans = (ans + c[i] % P * p[i - (n - 1 - m)]) % P;
                }
            }
        } else {
            for (int i = 0; i < n - 2; ++i)
                ans = (ans + c[i] % P * p[i]) % P;
            int res = 1;
            for (int i = n - 2; i < m; ++i)
                res = 1ll * res * p[i] % P;
            ans = (ans + c[n - 2] % P * res) % P;
        }
        std::cout << ans << "\n";
    }
    return 0;
}