#include <bits/stdc++.h>

using int64 = long long;
static const int64 INF = 1E18;

struct Flow {
    int n;
    struct Edge {
        int to;
        int64 Flo;
        Edge(int to, int64 Flo) : to(to), Flo(Flo) {}
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
                int v = e[i].to, c = e[i].Flo;
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int64 dfs(int u, int t, int64 f) {
        if (u == t) return f;
        int64 r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            int v = e[j].to;
            int64 c = e[j].Flo;
            if (c > 0 && h[v] == h[u] + 1) {
                int64 a = dfs(v, t, std::min(r, c));
                e[j].Flo -= a;
                e[j ^ 1].Flo += a;
                r -= a;
                if (r == 0) return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, int64 c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int64 maxFlow(int s, int t) {
        int64 ans = 0;
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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    auto v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::vector<std::pair<int, int>> edges;
    for (int i = 0, u, v; i < m; ++i) std::cin >> u >> v, edges.emplace_back(--u, --v);
    std::vector<int> ans(n, v[0]);
    std::function<void(int, int, std::vector<int>)> solve = [&](int l, int r, std::vector<int> u) {
        if (l == r || u.empty()) {
            for (auto x : u) ans[x] = v[l];
            return;
        }
        std::vector<int> pos(n, -1);
        const int N = u.size();
        Flow NowFlow(N + 2);
        const int source = N, sink = N + 1;
        const int mid = (l + r) / 2;
        for (int i = 0; i < N; ++i) {
            pos[u[i]] = i;
            if (a[u[i]] <= v[mid]) {
                NowFlow.addEdge(source, i, 1);
            } else {
                NowFlow.addEdge(i, sink, 1);
            }
        }
        for (auto [a, b] : edges) {
            if (pos[a] == -1 || pos[b] == -1) continue;
            NowFlow.addEdge(pos[b], pos[a], 1E9);
        }
        NowFlow.maxFlow(source, sink);
        std::vector<int> lu, ru;
        for (int i = 0; i < N; ++i) {
            if (NowFlow.h[i] != -1) {
                lu.push_back(u[i]);
            } else {
                ru.push_back(u[i]);
            }
        }
        solve(l, mid, lu);
        solve(mid + 1, r, ru);
    };
    std::vector<int> us(n);
    std::iota(us.begin(), us.end(), 0);
    solve(0, n - 1, us);
    for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}