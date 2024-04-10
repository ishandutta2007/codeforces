#include <bits/stdc++.h>
struct Flow {
    static constexpr int INF = 1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<int> u(m), v(m), d(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i] >> d[i];
        --u[i], --v[i];
    }
    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        Flow f(2 * n + 2);
        for (int i = 0; i < n; ++i) {
            f.addEdge(2 * n, i, 1);
            f.addEdge(n + i, 2 * n + 1, 1);
        }
        for (int i = 0; i < m; ++i)
            if (d[i] <= mid) f.addEdge(u[i], n + v[i], 1);
        if (f.maxFlow(2 * n, 2 * n + 1) == n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (r == 1e9 + 1) r = -1;
    std::cout << r << "\n";
    return 0;
}