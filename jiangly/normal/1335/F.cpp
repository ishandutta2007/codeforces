#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> c(n), s(n);
        for (int i = 0; i < n; ++i)
            std::cin >> c[i];
        for (int i = 0; i < n; ++i)
            std::cin >> s[i];
        std::vector<int> f(n * m);
        int ans = 0, black = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = i, y = j;
                if (s[i][j] == 'L') {
                    --y;
                } else if (s[i][j] == 'R') {
                    ++y;
                } else if (s[i][j] == 'U') {
                    --x;
                } else {
                    ++x;
                }
                f[i * m + j] = x * m + y;
            }
        }
        std::vector<int> din(n * m);
        for (int i = 0; i < n * m; ++i)
            ++din[f[i]];
        std::vector<std::vector<int>> e(n * m);
        std::function<void(int)> g = [&](int x) {
            e[f[x]].push_back(x);
            --din[x];
            if (--din[f[x]] == 0)
                g(f[x]);
        };
        for (int i = 0; i < n * m; ++i)
            if (din[i] == 0)
                g(i);
        for (int i = 0; i < n * m; ++i) {
            if (din[i] == 1) {
                int l = 1;
                for (int j = f[i]; j != i; j = f[j], ++l)
                    e[f[j]].push_back(j);
                std::vector<bool> ok(l);
                ans += l;
                std::function<void(int, int)> dfs = [&](int u, int d) {
                    din[u] = -1;
                    if (c[u / m][u % m] == '0')
                        ok[d % l] = true;
                    for (auto v : e[u])
                        dfs(v, d + 1);
                };
                dfs(i, 0);
                black += std::count(ok.begin(), ok.end(), true);
            }
        }
        std::cout << ans << " " << black << "\n";
    }
    return 0;
}