#include <bits/stdc++.h>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].emplace_back(v, 0);
        e[v].emplace_back(u, 1);
    }
    
    std::vector<int> t(n, 1e9);
    std::deque<std::pair<int, int>> que;
    que.emplace_back(0, 0);
    t[0] = 0;
    while (!que.empty()) {
        auto [u, d] = que.front();
        que.pop_front();
        if (d != t[u]) continue;
        for (auto [v, x] : e[u]) {
            if (x == d % 2) {
                if (d < t[v]) {
                    t[v] = d;
                    que.emplace_front(v, d);
                }
            } else {
                if (d + 1 < t[v]) {
                    t[v] = d + 1;
                    que.emplace_back(v, d + 1);
                }
            }
        }
    }
    
    std::vector<int> dis(20 * n, -1);
    std::queue<int> q;
    q.push(0);
    dis[0] = 0;
    while (!q.empty()) {
        int u0 = q.front();
        q.pop();
        int u = u0 / 20, tu = t[u] + u0 % 20;
        for (auto [v, x] : e[u]) {
            int res = tu + (x != tu % 2);
            int y = res - t[v];
            int v0 = 20 * v + y;
            if (0 <= y && y < 20 && dis[v0] == -1) {
                dis[v0] = dis[u0] + 1;
                q.push(v0);
            }
        }
    }
    
    int pw = t[n - 1], a = dis[20 * (n - 1)];
    for (int i = 1; i < 20; ++i) {
        int u0 = 20 * (n - 1) + i;
        if (dis[u0] == -1) continue;
        if (t[n - 1] < 30 && (1ll << pw) + a > (1ll << (t[n - 1] + i)) + dis[u0]) {
            pw = t[n - 1] + i;
            a = dis[u0];
        }
    }
    
    int ans = 1;
    for (int i = 0; i < pw; ++i) ans = 2 * ans % P;
    ans = (ans + a) % P;
    
    std::cout << ans - 1 << "\n";
    
    return 0;
}