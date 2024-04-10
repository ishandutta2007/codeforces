#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr i64 inf = 1e18;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    std::vector<i64> dis(4 * n, inf);
    std::priority_queue<std::pair<i64, int>> h;
    dis[0] = 0;
    h.emplace(0, 0);
    while (!h.empty()) {
        i64 d = -h.top().first;
        int x = h.top().second;
        h.pop();
        if (d > dis[x]) {
            continue;
        }
        int u = x / 4;
        int p = x / 2 % 2;
        int q = x % 2;
        for (auto [v, w] : e[u]) {
            int y = v * 4 + p * 2 + q;
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                h.emplace(-dis[y], y);
            }
            if (p == 0 && dis[y + 2] > dis[x]) {
                dis[y + 2] = dis[x];
                h.emplace(-dis[y + 2], y + 2);
            }
            if (q == 0 && dis[y + 1] > dis[x] + 2 * w) {
                dis[y + 1] = dis[x] + 2 * w;
                h.emplace(-dis[y + 1], y + 1);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        std::cout << std::min(dis[i * 4], dis[i * 4 + 3]) << " \n"[i == n - 1];
    }
    return 0;
}