#include <bits/stdc++.h>

using i64 = long long;

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
                int v = e[i].to;
                int c = e[i].cap;
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
            int v = e[j].to;
            int c = e[j].cap;
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

constexpr int N = 5E4;

int pos[N + 1];

std::vector<int> divs[N + 1];

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }
    
    Flow flow(4 * n + 2);
    const int source = 4 * n, sink = 4 * n + 1;
    for (int i = 0; i < n; i++) {
        flow.addEdge(source, 4 * i, 1);
        flow.addEdge(4 * i + 1, 4 * i + 2, 1);
        flow.addEdge(4 * i + 3, sink, 1);
    }
    
    std::vector<std::vector<int>> e(n);
    
    for (int i = 0; i < n; i++) {
        for (auto x : divs[a[i]]) {
            if (pos[x] != -1) {
                int j = pos[x];
                flow.addEdge(4 * i, 4 * j + 1, 1);
                flow.addEdge(4 * i + 2, 4 * j + 3, 1);
            }
        }
    }
    
    std::cout << flow.maxFlow(source, sink) << "\n";
    
    for (int i = 0; i < n; i++) {
        pos[a[i]] = -1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 1; i <= N; i++) {
        pos[i] = -1;
        for (int j = 2 * i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}