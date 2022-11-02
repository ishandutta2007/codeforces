#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        std::cin >> u >> v >> t, --u, --v;
        e[v].push_back(u + t * n);
    }
    std::vector<int> dis(2 * n, 1e9), vis(n);
    std::queue<int> que;
    dis[n - 1] = dis[2 * n - 1] = 0;
    que.push(n - 1);
    que.push(2 * n - 1);
    std::vector<int> color(n);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        int u = x % n;
        if (!vis[u]) {
            vis[u] = 1;
            color[u] = x < n;
            continue;
        }
        for (auto v : e[u]) {
            if (dis[v] == 1e9) {
                dis[v] = dis[x] + 1;
                que.push(v);
            }
        }
    }
    int ans = std::max(dis[0], dis[n]);
    if (ans == 1e9) ans = -1;
    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i) std::cout << color[i];
    std::cout << "\n";
    return 0;
}