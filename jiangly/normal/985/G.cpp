#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    unsigned long long A, B, C;
    unsigned long long ans = 0;
    std::cin >> A >> B >> C;
    std::vector<int> deg(n);
    std::vector<std::vector<int>> e(n);
    std::vector<std::pair<int, int>> edges;
    auto get = [&](int a, int b, int c) {
        int v[3] = {a, b, c};
        std::sort(v, v + 3);
        return v[0] * A + v[1] * B + v[2] * C;
    };
    for (int i = 0; i < n; ++i)
        ans += (1ull * (n - i - 1) * (n - i - 2) / 2 * A + 1ull * i * (n - i - 1) * B + 1ull * i * (i - 1) / 2 * C) * i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u > v)
            std::swap(u, v);
        ans -= 1ull * u * (u - 1) / 2 * A + u * (B * u + C * v);
        ans -= 1ull * (u + v) * (v - u - 1) / 2 * B + (v - u - 1) * (A * u + C * v);
        ans -= 1ull * (n + v) * (n - v - 1) / 2 * C + (n - v - 1) * (A * u + B * v);
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u];
        ++deg[v];
        edges.emplace_back(u, v);
    }
    for (int u = 0; u < n; ++u) {
        std::sort(e[u].begin(), e[u].end());
        int s = std::lower_bound(e[u].begin(), e[u].end(), u) - e[u].begin(), g = deg[u] - s;
        ans += (1ull * g * (g - 1) / 2 * A + 1ull * s * g * B + 1ull * s * (s - 1) / 2 * C) * u;
        for (int i = 0; i < deg[u]; ++i) {
            int v = e[u][i];
            if (v < u) {
                ans += ((deg[u] - i - 1) * A + i * B) * v;
            } else {
                ans += ((deg[u] - i - 1) * B + i * C) * v;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        e[i].clear();
    for (auto edge : edges) {
        int u, v;
        std::tie(u, v) = edge;
        if (deg[u] > deg[v] || (deg[u] == deg[v] && u < v)) {
            e[u].push_back(v);
        } else {
            e[v].push_back(u);
        }
    }
    std::vector<bool> vis(n);
    for (int u = 0; u < n; ++u) {
        for (int v : e[u])
            vis[v] = true;
        for (int v : e[u])
            for (int w : e[v])
                if (vis[w])
                    ans -= get(u, v, w);
        for (int v : e[u])
            vis[v] = false;
    }
    std::cout << ans << "\n";
    return 0;
}