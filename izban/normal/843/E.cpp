#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e4;
const int N = 1 << 18;

struct Edge {
    int to, cap, flow;
    int id;
};

struct Graph {
    int n;
    vector<vector<int> > e;
    vector<Edge> edges;
    vector<int> d, c;

    Graph() {}
    Graph(int _n) {
        n = _n;
        e.resize(n);
    }

    void addEdge(int from, int to, int cap, int id) {
        e[from].push_back(edges.size());
        edges.push_back(Edge({to, cap, 0, id}));
        e[to].push_back(edges.size());
        edges.push_back(Edge({from, 0, 0, -1}));
    }

    bool bfs() {
        d.assign(n, INF);
        c.assign(n, 0);
        vector<int> q(n);
        int qL = 0, qR = 0;
        d[0] = 0;
        q[qR++] = 0;
        while (qL < qR) {
            int v = q[qL++];
            for (int i = 0; i < (int)e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + 1 && cur.flow < cur.cap) {
                    d[cur.to] = d[v] + 1;
                    q[qR++] = cur.to;
                }
            }
        }
        return d[n - 1] != INF;
    }

    int dfs(int v, int flow) {
        if (v == n - 1) return flow;
        if (flow == 0) return 0;
        for (int &i = c[v]; i < (int)e[v].size(); i++) {
            Edge cur = edges[e[v][i]];
            if (d[cur.to] != d[v] + 1) continue;
            int pushed = dfs(cur.to, min(flow, cur.cap - cur.flow));
            if (pushed > 0) {
                edges[e[v][i]].flow += pushed;
                edges[e[v][i] ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll flow() {
        ll flow = 0;
        while (bfs()) {
            while (int pushed = dfs(0, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m, s, t;
    while (cin >> n >> m >> s >> t) {
        vector<int> u(m), v(m), g(m);
        for (int i = 0; i < m; i++) {
            cin >> u[i] >> v[i] >> g[i];
        }

        Graph g1(n + 2);
        for (int i = 0; i < m; i++) {
            if (g[i] == 0) {
                g1.addEdge(u[i], v[i], INF, i);
            } else {
                g1.addEdge(u[i], v[i], 1, i);
                g1.addEdge(v[i], u[i], INF, -1);
            }
        }
        g1.addEdge(0, s, INF, -1);
        g1.addEdge(t, n + 1, INF, -1);

        ll fl1 = g1.flow();
        assert(fl1 < INF);

        queue<int> q;
        q.push(0);
        vector<char> vis(n + 2);
        vis[0] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < (int)g1.e[v].size(); i++) {
                Edge cur = g1.edges[g1.e[v][i]];
                if (!vis[cur.to] && cur.flow < cur.cap) {
                    vis[cur.to] = 1;
                    q.push(cur.to);
                }
            }
        }

        vector<int> c(m, 0);

        for (int v = 0; v <= n + 1; v++) {
            if (!vis[v]) continue;
            for (int i = 0; i < (int)g1.e[v].size(); i++) {
                Edge cur = g1.edges[g1.e[v][i]];
                if (!vis[cur.to] && cur.id >= 0) {
                    assert(cur.flow == cur.cap);
                    c[cur.id] = 1;
                }
            }
        }


        Graph g2(n + 2);
        int need = 0;
        for (int i = 0; i < m; i++) {
            if (g[i] == 0) {
                c[i] = 1;
            } else {
                g2.addEdge(0, v[i], 1, -1);
                g2.addEdge(u[i], n + 1, 1, -1);
                g2.addEdge(u[i], v[i], (int)1e9, i);
                need++;
            }
        }
        g2.addEdge(t, s, (int)1e9, -1);


        vector<int> f(m);
        ll o = g2.flow();
        assert(o == need);
        ll ans = 0;
        for (auto cur : g2.edges) {
            if (cur.id >= 0) {
                if (c[cur.id] == 1) {
                    f[cur.id] = cur.flow + 1;
                    c[cur.id] = cur.flow + 1;
                } else {
                    f[cur.id] = cur.flow + 1;
                    c[cur.id] = cur.flow + 2;
                }
            }
        }


        int k = 0;
        cout << fl1 << endl;
        for (int i = 0; i < m; i++) {
            assert(f[i] != -1);
            assert((f[i] > 0) == g[i]);
            k += f[i] == c[i];
            cout << f[i] << " " << c[i] << endl;
        }
        assert(k == fl1);
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}