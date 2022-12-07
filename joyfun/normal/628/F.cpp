#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXNODE = 11111;
const int MAXEDGE = 1000005;

typedef int Type;
const Type INF = 0x3f3f3f3f;

struct Edge {
    int u, v;
    Type cap, flow;
    Edge() {}
    Edge(int u, int v, Type cap, Type flow) {
        this->u = u;
        this->v = v;
        this->cap = cap;
        this->flow = flow;
    }
};

struct Dinic {
    int n, m, s, t;
    Edge edges[MAXEDGE];
    int first[MAXNODE];
    int next[MAXEDGE];
    bool vis[MAXNODE];
    Type d[MAXNODE];
    int cur[MAXNODE];
    vector<int> cut;

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        m = 0;
    }
    void add_Edge(int u, int v, Type cap) {
        edges[m] = Edge(u, v, cap, 0);
        next[m] = first[u];
        first[u] = m++;
        edges[m] = Edge(v, u, 0, 0);
        next[m] = first[v];
        first[v] = m++;
    }

    bool bfs() {
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = first[u]; i != -1; i = next[i]) {
                Edge& e = edges[i];
                if (!vis[e.v] && e.cap > e.flow) {
                    vis[e.v] = true;
                    d[e.v] = d[u] + 1;
                    Q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    Type dfs(int u, Type a) {
        if (u == t || a == 0) return a;
        Type flow = 0, f;
        for (int &i = cur[u]; i != -1; i = next[i]) {
            Edge& e = edges[i];
            if (d[u] + 1 == d[e.v] && (f = dfs(e.v, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[i^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    Type Maxflow(int s, int t) {
        this->s = s; this->t = t;
        Type flow = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++)
                cur[i] = first[i];
            flow += dfs(s, INF);
        }
        return flow;
    }

    void MinCut() {
        cut.clear();
        for (int i = 0; i < m; i += 2) {
            if (vis[edges[i].u] && !vis[edges[i].v])
                cut.push_back(i);
        }
    }
} gao;

const int N = 10005;

struct Q {
    int v, cnt;
    Q() {}
    Q(int v, int cnt):v(v), cnt(cnt) {}
    void read() {
        scanf("%d%d", &v, &cnt);
    }
    bool operator < (const Q& c) const {
        return v < c.v;
    }
} q[N];

int n, b, qn;

int get(int v, int yu) {
    if (yu == 0) yu = 5;
    yu--;
    return (v + 4 - yu) / 5;
}

bool judge() {
    sort(q + 1, q + qn + 1);
    gao.init(qn + 7);
    for (int i = 1; i <= qn; i++) {
        int l = q[i - 1].v, r = q[i].v;
        int cnt = q[i].cnt - q[i - 1].cnt;
        if (cnt < 0) return false;
        gao.add_Edge(0, i, cnt);
        for (int j = 0; j < 5; j++)
            gao.add_Edge(i, qn + j + 1, get(r, j) - get(l, j));
    }
    for (int i = 0; i < 5; i++)
        gao.add_Edge(qn + i + 1, qn + 6, n / 5);
    return gao.Maxflow(0, qn + 6) == n;
}

int main() {
    scanf("%d%d%d", &n, &b, &qn);
    q[0] = Q(0, 0);
    for (int i = 1; i <= qn; i++) q[i].read();
    q[++qn] = Q(b, n);
    printf("%s\n", judge() ? "fair" : "unfair");
    return 0;
}