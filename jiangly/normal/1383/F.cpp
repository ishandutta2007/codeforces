#include <bits/stdc++.h>
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
    int n, m, k, q;
    std::cin >> n >> m >> k >> q;
    Flow flow(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        flow.addEdge(u, v, w);
        if (i < k)
            edges.emplace_back(u, v);
    }
    std::vector<int> cut(1 << k);
    int f = flow.maxFlow(0, n - 1);
    std::function<void(int, Flow, int, int)> dfs = [&](int x, Flow flow, int s, int ans) {
        if (x == k) {
            cut[s] = ans;
        } else {
            dfs(x + 1, flow, s, ans);
            auto [u, v] = edges[x];
            flow.addEdge(u, v, 25);
            ans += flow.maxFlow(0, n - 1);
            dfs(x + 1, flow, s | 1 << x, ans);
        }
    };
    dfs(0, flow, 0, f);
    while (q--) {
        std::vector<int> w(k);
        for (int i = 0; i < k; ++i)
            std::cin >> w[i];
        std::vector<int> sum(1 << k);
        for (int i = 1; i < (1 << k); ++i)
            sum[i] = sum[i & (i - 1)] + w[__builtin_ctz(i)];
        int ans = 1e9;
        for (int i = 0; i < (1 << k); ++i)
            ans = std::min(ans, sum[i] + cut[((1 << k) - 1) ^ i]);
        std::cout << ans << "\n";
    }
    return 0;
}