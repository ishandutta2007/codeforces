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


const int INF = (int)1.01e9;

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

ll solve(vector<pair<pair<int, int>, pair<int, int>>> vct) {

    vector<int> vx, vy;
    vx.push_back(1); vy.push_back(1);
    for (auto o : vct) {
        vx.push_back(o.first.first);
        vx.push_back(o.first.second);
        vy.push_back(o.second.first);
        vy.push_back(o.second.second);
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    int xx = (int)vx.size() - 1;

    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    int yy = (int)vy.size() - 1;

    for (auto &o : vct) {
        o.first.first = lower_bound(vx.begin(), vx.end(), o.first.first) - vx.begin();
        o.first.second = lower_bound(vx.begin(), vx.end(), o.first.second) - vx.begin();
        o.second.first = lower_bound(vy.begin(), vy.end(), o.second.first) - vy.begin();
        o.second.second = lower_bound(vy.begin(), vy.end(), o.second.second) - vy.begin();
    }


    Graph gr(1 + xx + yy + 1);
    for (int i = 0; i < xx; i++) {
        gr.addEdge(0, 1 + i, vx[i + 1] - vx[i]);
    }
    for (int i = 0; i < yy; i++) {
        gr.addEdge(1 + xx + i, 1 + xx + yy, vy[i + 1] - vy[i]);
    }

    for (auto o : vct) {
        for (int i = o.first.first; i < o.first.second; i++) {
            for (int j = o.second.first; j < o.second.second; j++) {
                gr.addEdge(1 + i, 1 + xx + j, INF);
            }
        }
    }
    return gr.flow();
}

void test() {
    int n = 50;
    vector<pair<pair<int, int>, pair<int, int>>> vct(n);
    for (int i = 0; i < n; i++) {
        vct[i].first.first = i;
        vct[i].first.second = 1e9 - i;
        vct[i].second = vct[i].first;
    }
    cout << solve(vct) << endl;
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<pair<int, int>, pair<int, int>>> vct(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d%d", &vct[i].first.first, &vct[i].second.first, &vct[i].first.second, &vct[i].second.second);
            vct[i].first.second++;
            vct[i].second.second++;
        }

        printf("%lld\n", solve(vct));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}