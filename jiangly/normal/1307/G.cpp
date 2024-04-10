#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
constexpr int X = 100'000;
double ans[X + 1];
struct MinCostFlow {
    struct Edge {
        int v, f, c;
        Edge(int v, int f, int c) : v(v), f(f), c(c) {}
    };
    const int n;
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<long long> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<long long>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] != d)
                continue;
            for (int i : g[u]) {
                auto [v, f, c] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<long long>::max();
    }
    MinCostFlow(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int f, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, f, c);
        g[v].push_back(e.size());
        e.emplace_back(u, -f, 0);
    }
    void minCostFlow(int s, int t) {
        int flow = 0;
        long long cost = 0;
        h.assign(n, 0);
        std::vector<std::pair<int, int>> x;
        int last = 0;
        while (last < X && dijkstra(s, t)) {
            for (int i = 0; i < n; ++i)
                h[i] += dis[i];
            int aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].v)
                aug = std::min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            if (flow == 0)
                ans[0] = h[t];
            flow += aug;
            cost += 1LL * aug * h[t];
            int r = flow * h[t] - cost;
            for (int i = last + 1; i <= X && i <= r; ++i)
                ans[i] = ans[i - 1] + 1.0 / (flow - aug);
            last = r;
        }
        for (int i = last + 1; i <= X; ++i)
            ans[i] = ans[i - 1] + 1.0 / flow;
    }
};
int n, m;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    MinCostFlow f(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        f.addEdge(u, v, w, 1);
    }
    f.minCostFlow(0, n - 1);
    int q;
    std::cin >> q;
    std::cout << std::fixed << std::setprecision(10);
    for (int i = 0; i < q; ++i) {
        int x;
        std::cin >> x;
        std::cout << ans[x] << "\n";
    }
    return 0;
}