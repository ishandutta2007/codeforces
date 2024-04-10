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
    int N = n * m;
    int n1, n2;
    std::cin >> n1 >> n2;
    if (std::abs(n1 - n2) != 1) {
        std::cout << "-1\n";
        return 0;
    }
    std::vector<std::string> map(n);
    for (int i = 0; i < n; i++) {
        std::cin >> map[i];
    }
    std::vector dis(N, std::vector<int>(N, -1));
    for (int s = 0; s < N; s++) {
        if (map[s / m][s % m] == '#') {
            continue;
        }
        dis[s][s] = 0;
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto move : {std::make_pair(0, -1), {0, 1}, {-1, 0}, {1, 0}}) {
                int x = u / m + move.first;
                int y = u % m + move.second;
                if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#') {
                    continue;
                }
                int v = x * m + y;
                if (dis[s][v] == -1) {
                    que.push(v);
                    dis[s][v] = dis[s][u] + 1;
                }
            }
        }
    }
    std::vector<std::pair<int, int>> A, B;
    int r0, c0, t0;
    std::cin >> r0 >> c0 >> t0;
    r0--;
    c0--;
    if (n1 < n2) {
        A.emplace_back(r0 * m + c0, t0);
    } else {
        B.emplace_back(r0 * m + c0, t0);
    }
    for (int i = 0; i < n1; i++) {
        int r, c, t;
        std::cin >> r >> c >> t;
        r--;
        c--;
        A.emplace_back(r * m + c, t);
    }
    for (int i = 0; i < n2; i++) {
        int r, c, t;
        std::cin >> r >> c >> t;
        r--;
        c--;
        B.emplace_back(r * m + c, t);
    }
    int M = A.size();
    i64 lo = 0, hi = 1e12;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        Flow g(2 * (N + M + 1));
        const int S = 2 * (N + M), T = S + 1;
        for (int i = 0; i < M; i++) {
            g.addEdge(S, i, 1);
            g.addEdge(i + M, T, 1);
            for (int j = 0; j < N; j++) {
                if (dis[j][A[i].first] != -1 && i64(dis[j][A[i].first]) * A[i].second <= mid) {
                    g.addEdge(i, j + 2 * M, 1);
                }
                if (dis[j][B[i].first] != -1 && i64(dis[j][B[i].first]) * B[i].second <= mid) {
                    g.addEdge(j + 2 * M + N, i + M, 1);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            g.addEdge(i + 2 * M, i + 2 * M + N, 1);
        }
        if (g.maxFlow(S, T) == M) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    i64 ans = lo;
    if (ans == 1e12) {
        ans = -1;
    }
    std::cout << ans << "\n";
    return 0;
}