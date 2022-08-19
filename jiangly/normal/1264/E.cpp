#include <bits/stdc++.h>
using namespace std;
class MinCostFlow {
public:
    const int n;
    vector<tuple<int, int, int>> e;
    vector<vector<int>> g;
    vector<int> h, dis, pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, 1E9);
        pre.assign(n, -1);
        priority_queue<pair<int, int>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            int u, d;
            tie(d, u) = que.top();
            d = -d;
            que.pop();
            if (dis[u] != d)
                continue;
            for (int i : g[u]) {
                int v, f, c;
                tie(v, f, c) = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(-dis[v], v);
                }
            }
        }
        return dis[t] != 1E9;
    }
    MinCostFlow(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int f, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, f, c);
        g[v].push_back(e.size());
        e.emplace_back(u, -f, 0);
    }
    pair<int, int> minCostMaxFlow(const int s, const int t) {
        int flow = 0, cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i)
                h[i] += dis[i];
            for (int i = t; i != s; i = get<0>(e[pre[i] ^ 1])) {
                --get<2>(e[pre[i]]);
                ++get<2>(e[pre[i] ^ 1]);
            }
            ++flow;
            cost += h[t];
        }
        return {flow, cost};
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> in(n), out(n);
    vector<vector<int>> res(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        res[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        res[u][v] = 1;
        res[v][u] = 0;
        ++out[u];
        ++in[v];
    }
    const int s = n, t = n + 1;
    int edgeId = n + 2;
    MinCostFlow flow(n + 2 + n * (n - 1) / 2 - m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (res[i][j] == -1) {
                int u = edgeId++;
                flow.addEdge(s, u, 0, 1);
                flow.addEdge(u, i, 0, 1);
                flow.addEdge(u, j, 0, 1);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = in[i]; j < n - 1 - out[i]; ++j)
            flow.addEdge(i, t, j, 1);
    flow.minCostMaxFlow(s, t);
    edgeId = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (res[i][j] == -1) {
                int u = edgeId++;
                int result = get<2>(flow.e[6 * u + 2]);
                res[i][j] = result;
                res[j][i] = result ^ 1;
            }
        }
    }
    for (int i = 0; i < n; ++i, cout << "\n")
        for (int j = 0; j < n; ++j)
            cout << res[i][j];
    return 0;
}