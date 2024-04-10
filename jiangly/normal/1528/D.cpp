#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int inf = 1e9 + 1000;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector c(n, std::vector(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b, x;
        std::cin >> a >> b >> x;
        c[a][b] = x;
    }
    for (int s = 0; s < n; s++) {
        std::vector<int> dis(n, inf);
        dis[s] = 0;
        std::vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && (u == -1 || dis[u] > dis[j])) {
                    u = j;
                }
            }
            vis[u] = 1;
            std::rotate(c[u].begin(), c[u].begin() - dis[u] % n + n, c[u].end());
            int last = -inf;
            for (int v = 0; v < n; v++) {
                if (c[u][v] != -1) {
                    last = std::max(last, v - c[u][v]);
                }
                dis[v] = std::min(dis[v], dis[u] + v - last);
            }
            last -= n;
            for (int v = 0; v < n; v++) {
                if (c[u][v] != -1) {
                    last = std::max(last, v - c[u][v]);
                }
                dis[v] = std::min(dis[v], dis[u] + v - last);
            }
            std::rotate(c[u].begin(), c[u].begin() + dis[u] % n, c[u].end());
        }
        for (int i = 0; i < n; i++) {
            std::cout << dis[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}