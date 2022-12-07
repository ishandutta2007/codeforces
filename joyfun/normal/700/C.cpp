#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1005;
const int M = 200005;
const int INF = 2000000005;

struct Edge {
    int u, v, w, id;
    bool iscut;

    Edge() {}
    Edge(int u, int v, int w, int id) {
        this->u = u;
        this->v = v;
        this->w = w;
        this->iscut = false;
        this->id = id;
    }

    void read(int id) {
        iscut = false;
        this->id = id;
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator < (const Edge& c) const {
        return w < c.w;
    }
};

struct BCC {
    int n;
    Edge edge[M];
    int en, first[N], next[M];
    int pre[N], dfn[N], bccno[N], bccn, dfs_clock;
    vector<Edge> bcc[N];

    Edge cut[M];
    int cutn;

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        en = 0;
    }

    void add_Edge(int u, int v, int w, int id) {
        edge[en] = Edge(u, v, w, id);
        next[en] = first[u];
        first[u] = en++;
    }

    void dfs_cut(int u, int fa) {
        pre[u] = dfn[u] = ++dfs_clock;
        for (int i = first[u]; i + 1; i = next[i]) {
            int v = edge[i].v;
            if (edge[i].id == fa) continue;
            if (!pre[v]) {
                dfs_cut(v, edge[i].id);
                dfn[u] = min(dfn[u], dfn[v]);
                if (dfn[v] > pre[u]) {
                    edge[i].iscut = edge[i^1].iscut = true;
                    cut[cutn++] = edge[i];
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

    void dfs_bcc(int u) {
        pre[u] = 1;
        bccno[u] = bccn;
        for (int i = first[u]; i + 1; i = next[i]) {
            if (edge[i].iscut) continue;
            int v = edge[i].v;
            if (pre[v]) continue;
            dfs_bcc(v);
        }
    }

    void find_bcc() {
        bccn = 0;
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; i++) {
            if (!pre[i]) {
                bccn++;
                dfs_bcc(i);
            }
        }
    }

    void build() {
        for (int i = 1; i <= bccn; i++) bcc[i].clear();
        for (int i = 0; i < en; i += 2) {
            Edge e = edge[i];
            e.u = bccno[e.u], e.v = bccno[e.v];
            if (e.u == e.v) continue;
            bcc[e.u].push_back(e);
            swap(e.u, e.v);
            bcc[e.u].push_back(e);
        }
    }
} gao;

int n, m, S, T;
Edge e[M];

struct Ans {
    int w, a, b;
    Ans() {w = INF;}
    Ans(int w, int a, int b) : w(w), a(a), b(b) {}
    bool operator < (const Ans& c) const {
        return w < c.w;
    }
} ans;

int fa[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int Min, Minv;

bool dfs(int u, int p, int t) {
    if (u == t) return true;
    for (int i = 0; i < gao.bcc[u].size(); i++) {
        Edge e = gao.bcc[u][i];
        if (e.v == p) continue;
        if (dfs(e.v, u, t)) {
            if (Min > e.w) {
                Min = e.w;
                Minv = e.id;
            }
            return true;
        }
    }
    return false;
}

void go(int bid, int ad) {
    gao.init(n);
    for (int i = 1; i <= m; i++) if (bid != i) {
        gao.add_Edge(e[i].u, e[i].v, e[i].w, e[i].id);
        gao.add_Edge(e[i].v, e[i].u, e[i].w, e[i].id);
    }
    gao.find_cut(); gao.find_bcc(); gao.build();
    Min = INF;
    dfs(gao.bccno[S], gao.bccno[S], gao.bccno[T]);
    if (Min != INF) ans = min(ans, Ans(Min + ad, e[bid].id, Minv));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    scanf("%d%d", &S, &T);
    int u, v, w;
    for (int i = 1; i <= m; i++) e[i].read(i);
  //  sort(e + 1, e + 1 + m);
    go(0, 0);
    for (int i = 1; i <= m; i++) {
        int pu = find(e[i].u), pv = find(e[i].v);
        if (pu == pv) continue;
        fa[pu] = pv;
        go(i, e[i].w);
    }
    if (find(S) != find(T)) printf("0\n0\n");
    else {
        if (ans.w == INF) printf("-1\n");
        else {
            printf("%d\n", ans.w);
            int cnt = (ans.a != 0) + (ans.b != 0);
            printf("%d\n", cnt);
            if (ans.a != 0) printf("%d ", ans.a);
            if (ans.b != 0) printf("%d ", ans.b);
            printf("\n");
        }
    }
    return 0;
}