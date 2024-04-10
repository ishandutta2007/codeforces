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
                    if (v == t) return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t) return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) return f;
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
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    Flow flow(2 * n * m + 2);
    int S = 2 * n * m, T = S + 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') continue;
            ++ans;
            std::vector<int> v, h;
            if (i < n - 1 && s[i + 1][j] == '#') v.push_back(i * m + j), --ans;
            if (j < m - 1 && s[i][j + 1] == '#') h.push_back(i * m + j), --ans;
            if (i && s[i - 1][j] == '#') v.push_back((i - 1) * m + j);
            if (j && s[i][j - 1] == '#') h.push_back(i * m + j - 1);
            for (auto x : v) {
                for (auto y : h) flow.addEdge(x, y + n * m, 1);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        flow.addEdge(S, i, 1);
        flow.addEdge(i + n * m, T, 1);
    }
    std::cout << ans + flow.maxFlow(S, T) << "\n";
    return 0;
}