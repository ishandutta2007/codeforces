#include <bits/stdc++.h>
#define NDEBUG
using namespace std;
class MinCostFlow {
private:
    static constexpr int INF = 1E9;
    const int n;
    vector<tuple<int, int, int>> e;
    vector<vector<int>> g;
    vector<int> h, dis, pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, INF);
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
        return dis[t] != INF;
    }
public:
    MinCostFlow(int n) : n(n) {g.resize(n);}
    void addEdge(int u, int v, int f, int c) {
        g[u].push_back((int)e.size());
        e.emplace_back(v, f, c);
        g[v].push_back((int)e.size());
        e.emplace_back(u, -f, 0);
    }
    pair<int, int> minCostMaxFlow(const int s, const int t) {
        int flow = 0, cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i)
                h[i] += dis[i];
            int augmentFlow = INF;
            for (int i = t; i != s; i = get<0>(e[pre[i] ^ 1]))
                augmentFlow = min(augmentFlow, get<2>(e[pre[i]]));
            for (int i = t; i != s; i = get<0>(e[pre[i] ^ 1])) {
                get<2>(e[pre[i]]) -= augmentFlow;
                get<2>(e[pre[i] ^ 1]) += augmentFlow;
            }
            flow += augmentFlow;
            cost += augmentFlow * h[t];
        }
        return {flow, cost};
    }
};
constexpr int MinCostFlow::INF;
class IncorrectFlow {
private:
    static constexpr int INF = 1E9;
    int n, m;
    vector<int> outFlow;
public:
    void solve() {
        assert(cin >> n >> m);
        assert(2 <= n && n <= 100);
        assert(0 <= m && m <= 100);
        outFlow.assign(n, 0);
        MinCostFlow flow(n + 2);
        int initialAns = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, c, f;
            assert(cin >> u >> v >> c >> f);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            assert(u != v);
            assert(0 <= c && c <= 1000000);
            assert(0 <= f && f <= 1000000);
            --u;
            --v;
            outFlow[u] += f;
            outFlow[v] -= f;
            if (f <= c) {
                flow.addEdge(v, u, 1, f);
                flow.addEdge(u, v, 1, c - f);
                flow.addEdge(u, v, 2, INF);
            } else {
                initialAns += f - c;
                flow.addEdge(v, u, 1, c);
                flow.addEdge(v, u, 0, f - c);
                flow.addEdge(u, v, 2, INF);
            }
        }
        flow.addEdge(n - 1, 0, 0, INF);
        const int s = n, t = n + 1;
        for (int i = 0; i < n; ++i) {
            if (outFlow[i] < 0)
                flow.addEdge(s, i, 0, -outFlow[i]);
            if (outFlow[i] > 0)
                flow.addEdge(i, t, 0, outFlow[i]);
        }
        cout << initialAns + flow.minCostMaxFlow(s, t).second << endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IncorrectFlow().solve();
    return 0;
}