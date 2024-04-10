#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

const int INF = 1e9;

struct Edge {
    int to, cap, flow;
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

    void addEdge(int from, int to, int cap) {
        e[from].push_back(edges.size());
        edges.push_back(Edge({to, cap, 0}));
        e[to].push_back(edges.size());
        edges.push_back(Edge({from, 0, 0}));
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
    assert(freopen("in", "r", stdin));
#endif

    int n, m, h;
    while (cin >> n >> h >> m) {
        vector<int> l(m), r(m), x(m), c(m);
        for (int i = 0; i < m; i++) {
            cin >> l[i] >> r[i] >> x[i] >> c[i];
            x[i]++;
            l[i]--;
            r[i]--;
        }

        Graph gr(1 + n * (h + 1) + m + 1);
        int sz = gr.n;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= h; j++) {
                gr.addEdge(1 + i * (h + 1) + (j - 1), 1 + i * (h + 1) + j, INF);
                gr.addEdge(1 + i * (h + 1) + j, sz - 1, 2 * j - 1);
                sum += 2 * j - 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (x[i] > h) continue;
            for (int t = l[i]; t <= r[i]; t++) {
                gr.addEdge(1 + n * (h + 1) + i, 1 + t * (h + 1) + x[i], INF);
//                gr.addEdge(0, 1 + t * (h + 1) + x[i], c[i]);
            }
            gr.addEdge(0, 1 + n * (h + 1) + i, c[i]);
        }
        cout << sum - gr.flow() << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}