#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXNODE = 100005;
const int MAXEDGE = 100005;

typedef long long Type;
const Type INF = 0x3f3f3f3f3f3f3f;

struct Edge {
    int u, v, id;
    Type dist;
    Edge() {}
    Edge(int u, int v, Type dist) {
        this->u = u;
        this->v = v;
        this->dist = dist;
    }
};

struct HeapNode {
    Type d;
    int u;
    HeapNode() {}
    HeapNode(Type d, int u) {
        this->d = d;
        this->u = u;
    }
    bool operator < (const HeapNode& c) const {
        return d > c.d;
    }
};

struct Dijkstra {
    int n, m;
    Edge edges[MAXEDGE];
    int first[MAXNODE];
    int next[MAXEDGE];
    bool done[MAXNODE];
    Type d[MAXNODE];

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        m = 0;
    }

    void add_Edge(int u, int v, Type dist) {
        edges[m] = Edge(u, v, dist);
        next[m] = first[u];
        first[u] = m++;
    }

    void dijkstra(int s) {
        priority_queue<HeapNode> Q;
        for (int i = 1; i <= n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, false, sizeof(done));
        Q.push(HeapNode(0, s));
        while (!Q.empty()) {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = first[u]; i != -1; i = next[i]) {
                Edge& e = edges[i];
                if (d[e.v] > d[u] + e.dist) {
                    d[e.v] = d[u] + e.dist;
                    Q.push(HeapNode(d[e.v], e.v));
                }
            }
        }
    }
} gao;

const int N = 100005;
const int M = 200005;

int ans[MAXEDGE];

struct Edge2 {
    int u, v, id;
    bool iscut;
    Edge2() {}
    Edge2(int u, int v, int id) {
        this->u = u;
        this->v = v;
        this->id = id;
        this->iscut = false;
    }
};

struct BCC {

    int n;
    int en, first[N], next[M], cutn;
    Edge2 edge[M], cut[M];

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        en = 0;
    }

    void add_edge(int u, int v, int id) {
        edge[en] = Edge2(u, v, id);
        next[en] = first[u];
        first[u] = en++;
    }

    int pre[N], dfn[N], bccno[N], bccn, dfs_clock;

    void dfs_cut(int u, int fa) {
        pre[u] = dfn[u] = ++dfs_clock;
        for (int i = first[u]; i + 1; i = next[i]) {
            int v = edge[i].v;
            if (edge[i].id == fa) continue;
            if (!pre[v]) {
                dfs_cut(v, edge[i].id);
                dfn[u] = min(dfn[u], dfn[v]);
                if (dfn[v] > pre[u]) {
                    edge[i].iscut = edge[i^1].iscut = true;//
                    ans[edge[i].id] = -1;
                }
            } else dfn[u] = min(dfn[u], pre[v]);
        }
    }

    void find_cut() {
        dfs_clock = cutn = 0;
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; i++)
            if (!pre[i]) dfs_cut(i, -1);
    }

} magic;

typedef long long ll;

int n, m, s, t;

Edge e[MAXEDGE];
ll d1[MAXNODE], d2[MAXNODE];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].dist);
        e[i].id = i;
    }
    gao.init(n);
    for (int i = 0; i < m; i++)
        gao.add_Edge(e[i].u, e[i].v, e[i].dist);
    gao.dijkstra(s);
    ll st = gao.d[t];
    for (int i = 1; i <= n; i++) d1[i] = gao.d[i];
    gao.init(n);
    for (int i = 0; i < m; i++)
        gao.add_Edge(e[i].v, e[i].u, e[i].dist);
    gao.dijkstra(t);
    for (int i = 1; i <= n; i++) d2[i] = gao.d[i];
    magic.init(n);
    for (int i = 0; i < m; i++) {
        int u = e[i].u;
        int v = e[i].v;
        ll w = e[i].dist;
        if (d1[u] + d2[v] + w == st) {
            magic.add_edge(u, v, e[i].id);
            magic.add_edge(v, u, e[i].id);
        }
    }
    magic.find_cut();
    for (int i = 0; i < m; i++) {
        if (ans[i] == -1) printf("YES\n");
        else {
            int u = e[i].u, v = e[i].v;
            ll w = e[i].dist;
            ll tmp = d1[u] + d2[v] + w - (st - 1);
            if (w - tmp > 0) printf("CAN %d\n", tmp);
            else printf("NO\n");
        }
    }
    return 0;
}