#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;
const int M = 400005;
int dep[N], fa[N], son[N], sz[N], top[N], id[N], idx;

struct Edge {
    int u, v, w, id;
    Edge() {}
    Edge(int u, int v, int w, int id) {
        this->u = u;
        this->v = v;
        this->w = w;
        this->id = id;
    }
    void read(int id) {
        this->id = id;
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator < (const Edge& c) const {
        return w < c.w;
    }
} tmp[M], edge[M], span[M];
int sn;

int head[N], nxt[M], en;

void init() {
    en = 0;
    idx = 0;
    memset(head, -1, sizeof(head));
}

void add_Edge(int u, int v) {
    edge[en] = Edge(u, v, 1, 1);
    nxt[en] = head[u];
    head[u] = en++;
}

void dfs1(int u, int f, int d) {
    dep[u] = d;
    sz[u] = 1;
    fa[u] = f;
    son[u] = 0;
    for (int i = head[u]; i + 1; i = nxt[i]) {
        int v = edge[i].v;
        if (v == f) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp) {
    id[u] = ++idx;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i + 1; i = nxt[i]) {
        int v = edge[i].v;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)
int n, m;

struct Node {
    int l, r, Max;
} node[N * 4];

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r;
    node[x].Max = 0;
    if (l == r) return;
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
}

void pushup(int x) {
    node[x].Max = max(node[lson(x)].Max, node[rson(x)].Max);
}

void add(int v, int val, int x = 0) {
    if (node[x].l == node[x].r) {
        node[x].Max = max(node[x].Max, val);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    if (v <= mid) add(v, val, lson(x));
    else add(v, val, rson(x));
    pushup(x);
}

int get(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) return node[x].Max;
    int mid = (node[x].l + node[x].r)>>1;
    int ans = 0;
    if (l <= mid) ans = max(ans, get(l, r, lson(x)));
    if (r > mid) ans = max(ans, get(l, r, rson(x)));
    return ans;
}

int gaoquery(int u, int v) {
    int tp1 = top[u], tp2 = top[v];
    int ans = 0;
    while (tp1 != tp2) {
        if (dep[tp1] < dep[tp2]) {
            swap(tp1, tp2);
            swap(u, v);
        }
        ans = max(ans, get(id[tp1], id[u]));
        // operator in [id[tp1], id[u]];
        u = fa[tp1];
        tp1 = top[u];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (u != v) ans = max(ans, get(id[son[u]], id[v]));
    // if Edge && u != v, operator in [id[son[u]], id[v]];
    // operator in [id[u], id[v]];
    return ans;
}

int parent[N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

long long out[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) parent[i] = i;
    int u, v, w;
    init();
    for (int i = 0; i < m; i++)
        tmp[i].read(i);
    sort(tmp, tmp + m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int pu = find(tmp[i].u);
        int pv = find(tmp[i].v);
        if (pu != pv) {
            sum += tmp[i].w;
            parent[pu] = pv;
            span[sn++] = tmp[i];
            add_Edge(tmp[i].u, tmp[i].v);
            add_Edge(tmp[i].v, tmp[i].u);
        }
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    build(1, n);
    for (int i = 0; i < sn; i++) {
        if (dep[span[i].u] < dep[span[i].v]) swap(span[i].u, span[i].v);
        add(id[span[i].u], span[i].w);
    }
    for (int i = 0; i < m; i++)
        out[tmp[i].id] = sum - gaoquery(tmp[i].u, tmp[i].v) + tmp[i].w;
    for (int i = 0; i < m; i++) printf("%lld\n", out[i]);
    return 0;
}