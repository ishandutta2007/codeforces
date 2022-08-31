#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<std::vector<int>> dis(n), p(n), q(n);
    auto bfs = [&](int s) {
        std::vector<int> dis0(n, -1), p0(n, -1);
        dis0[s] = 0;
        std::vector<int> que;
        que.push_back(s);
        for (int i = 0; i < n; i++) {
            int u = que[i];
            for (auto v : e[u]) {
                if (dis0[v] == -1) {
                    p0[v] = u;
                    dis0[v] = dis0[u] + 1;
                    que.push_back(v);
                }
            }
        }
        dis[s] = dis0;
        p[s] = p0;
        q[s] = que;
    };
    for (int s = 0; s < n; s++) {
        bfs(s);
    }
    auto solve = [&](int s, int t) {
        std::vector<int> belong(n, -1);
        for (int i = t; i != -1; i = p[s][i]) {
            belong[i] = i;
        }
        for (auto u : q[s]) {
            if (belong[u] == -1) {
                for (auto v : e[u]) {
                    if (dis[s][v] == dis[s][u] - 1 && (belong[u] == -1 || dis[s][belong[u]] < dis[s][belong[v]])) {
                        belong[u] = belong[v];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dis[t][i] != dis[s][i] + dis[s][t] - 2 * dis[s][belong[i]]) {
                return 0;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (belong[i] != i) {
                int cnt = 0;
                for (auto v : e[i]) {
                    if (dis[s][v] == dis[s][i] - 1 && belong[i] == belong[v]) {
                        cnt++;
                    }
                }
                ans = i64(ans) * cnt % P;
            }
        }
        return ans;
    };
    for (int s = 0; s < n; s++) {
        for (int t = 0; t < n; t++) {
            std::cout << solve(s, t) << " \n"[t == n - 1];
        }
    }
    return 0;
}