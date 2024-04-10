#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int q;
    std::cin >> q;
    std::vector<int> a(q), b(q);
    for (int i = 0; i < q; ++i) std::cin >> a[i] >> b[i], --a[i], --b[i];
    if (n > m) {
        std::swap(n, m);
        for (int i = 0; i < q; ++i) std::swap(a[i], b[i]);
    }
    std::set<std::pair<int, int>> st;
    for (int i = 0; i < q; ++i) st.emplace(a[i], b[i]);
    std::vector<int> f(n, -1);
    f[0] = 0;
    int ans = 0;
    while (true) {
        ++ans;
        std::vector<int> g(n, -1);
        for (int i = 0; i < n; ++i) {
            if (f[i] != -1) {
                if (st.count(std::make_pair(i, f[i])) == 0) {
                    int x = std::min(i + f[i] + 1, m - 1);
                    g[i] = std::max(g[i], x);
                    int y = std::min(i + f[i] + 1, n - 1);
                    g[y] = std::max(g[y], f[i]);
                } else {
                    int x = std::min(i + f[i] + 2, m - 1);
                    g[i] = std::max(g[i], x);
                    int y = std::min(i + f[i] + 2, n - 1);
                    g[y] = std::max(g[y], f[i]);
                }
            }
        }
        if (g[n - 1] == m - 1) {
            std::cout << ans << std::endl;
            break;
        }
        std::swap(f, g);
    }
}