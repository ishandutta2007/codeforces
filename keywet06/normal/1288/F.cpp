#include <bits/stdc++.h>

class MinCostFlow {
   public:
    const int INF = 1000000000;
    const int n;
    std::vector<std::tuple<int, int, int>> e;
    std::vector<std::vector<int>> g;
    std::vector<int> h, dis, pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, INF);
        pre.assign(n, -1);
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, std::greater<>>
            que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] != d) continue;
            for (int i : g[u]) {
                auto [v, f, c] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != INF;
    }
    MinCostFlow(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int f, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, f, c);
        g[v].push_back(e.size());
        e.emplace_back(u, -f, 0);
    }
    auto minCostMaxFlow(const int s, const int t) {
        int flow = 0, cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            for (int i = t; i != s; i = std::get<0>(e[pre[i] ^ 1])) {
                --std::get<2>(e[pre[i]]);
                ++std::get<2>(e[pre[i] ^ 1]);
            }
            ++flow;
            cost += h[t];
        }
        return std::make_pair(flow, cost);
    }
};

const int N = 200;

int n1, n2, m, r, b;
int d1[N], d2[N], out[2 * N + 2];

std::string s1, s2;

void gg() {
    std::cout << -1 << "\n";
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;
    MinCostFlow flow(n1 + n2 + 4);
    int s = n1 + n2, t = s + 1;
    int s0 = s + 2, t0 = s + 3;
    int tot = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        ++d1[u], ++d2[v], ++out[u], --out[n1 + v];
        flow.addEdge(n1 + v, u, b, 1);
        flow.addEdge(u, n1 + v, r, 1);
    }
    for (int i = 0; i < n1; ++i) {
        if (s1[i] == 'B') {
            if (d1[i] == 0) gg();
            flow.addEdge(s, i, 0, d1[i] - 1);
        } else if (s1[i] == 'R') {
            if (d1[i] == 0) gg();
            flow.addEdge(s, i, 0, d1[i] - 1);
            out[i] -= d1[i] + 1;
            out[s] += d1[i] + 1;
        } else {
            flow.addEdge(s, i, 0, 2 * d1[i]);
        }
    }
    for (int i = 0; i < n2; ++i) {
        if (s2[i] == 'B') {
            if (d2[i] == 0) gg();
            flow.addEdge(n1 + i, t, 0, d2[i] - 1);
        } else if (s2[i] == 'R') {
            if (d2[i] == 0) gg();
            flow.addEdge(n1 + i, t, 0, d2[i] - 1);
            out[n1 + i] += d2[i] + 1;
            out[t] -= d2[i] + 1;
        } else {
            flow.addEdge(n1 + i, t, 0, 2 * d2[i]);
        }
    }
    for (int i = 0; i < n1 + n2 + 2; ++i) {
        if (out[i] > 0) {
            tot += out[i];
            flow.addEdge(i, t0, 0, out[i]);
        }
        if (out[i] < 0) flow.addEdge(s0, i, 0, -out[i]);
    }
    flow.addEdge(t, s, 0, 1000000000);
    auto [x, cost] = flow.minCostMaxFlow(s0, t0);
    if (x != tot) gg();
    std::cout << cost << "\n";
    for (int i = 0; i < m; ++i) {
        int x = std::get<2>(flow.e[4 * i + 0]) + std::get<2>(flow.e[4 * i + 3]);
        std::cout << "BUR"[x];
    }
    std::cout << "\n";
    return 0;
}