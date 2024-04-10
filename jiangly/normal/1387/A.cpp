#include <bits/stdc++.h>
void gg() {
    std::cout << "NO\n";
    std::exit(0);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vis(n), val(n), k(n), b(n);
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        std::cin >> u >> v >> x;
        --u;
        --v;
        e[u].emplace_back(v, 2 * x);
        e[v].emplace_back(u, 2 * x);
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        std::vector<int> que;
        que.push_back(i);
        vis[i] = 1;
        int x = 0, nx = 0;
        k[i] = 1;
        for (int t = 0; t < int(que.size()); ++t) {
            int u = que[t];
            for (auto [v, w] : e[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    k[v] = -k[u];
                    b[v] = w - b[u];
                    vis[v] = 1;
                    que.push_back(v);
                } else if (nx) {
                    if (k[u] * x + b[u] + k[v] * x + b[v] != w)
                        gg();
                } else {
                    if (-k[u] == k[v]) {
                        if (w - b[u] == b[v]) {
                            continue;
                        } else {
                            gg();
                        }
                    }
                    nx = 1;
                    x = (w - b[u] - b[v]) / (k[u] + k[v]);
                }
            }
        }
        if (!nx) {
            std::vector<int> p;
            for (auto u : que)
                p.push_back(-k[u] * b[u]);
            std::sort(p.begin(), p.end());
            x = p[p.size() / 2];
        }
        for (auto u : que)
            val[u] = k[u] * x + b[u];
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i)
        std::cout << 0.5 * val[i] << " \n"[i == n - 1];
    return 0;
}