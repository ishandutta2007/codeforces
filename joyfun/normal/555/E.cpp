#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <algorithm>  
#include <vector>  
using namespace std;  
  
const int N = 200005;  
const int M = 400005;  
  
int n, m, q;

struct Edge {  
    int u, v, id;  
    bool iscut;  
    Edge() {}  
    Edge(int u, int v, int id) {  
        this->u = u;  
        this->v = v;  
        this->id = id;  
        this->iscut = false;  
    }  
} edge[M], cut[M];
  
int en, head[N], nxt[M], cutn;  
  
int pre[N], dfn[N], bccno[N], bccn, dfs_clock;  

void dfs_cut(int u, int fa) {  
    pre[u] = dfn[u] = ++dfs_clock;  
    for (int i = head[u]; i + 1; i = nxt[i]) {  
        int v = edge[i].v;  
        if (edge[i].id == fa) continue;  
        if (!pre[v]) {  
            dfs_cut(v, edge[i].id);  
            dfn[u] = min(dfn[u], dfn[v]);  
            if (dfn[v] > pre[u]) {  
                edge[i].iscut = edge[i^1].iscut = true;//
                cut[cutn++] = edge[i];//
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
    for (int i = head[u]; i + 1; i = nxt[i]) {  
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

int dep[N], fa[N], son[N], sz[N], top[N], id[N], idx;

void init() {
    en = 0;
    idx = 0;
    memset(head, -1, sizeof(head));
}

void add_Edge(int u, int v, int id) {
    edge[en] = Edge(u, v, id);
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

struct Node {
    int l, r, sum[2], lazy[2];
    void gao(int f) {
        lazy[f] = sum[f] = 1;
    }
} node[N * 4];

void pushdown(int x) {
    for (int i = 0; i < 2; i++) {
        if (node[x].lazy[i]) {
            node[lson(x)].gao(i);
            node[rson(x)].gao(i);
            node[x].lazy[i] = 0;
        }
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r;
    node[x].sum[0] = node[x].sum[1] = 0;
    node[x].lazy[0] = node[x].lazy[1] = 0;
    if (l == r) return;
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
}

void add(int l, int r, int val, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].gao(val);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, val, lson(x));
    if (r > mid) add(l, r, val, rson(x));
}

void gaoadd(int u, int v) {
    int tp1 = top[u], tp2 = top[v];
    int bo = 0;
    while (tp1 != tp2) {
        if (dep[tp1] < dep[tp2]) {
            swap(tp1, tp2);
            swap(u, v);
            bo ^= 1;
        }
        add(id[tp1], id[u], bo);
        // operator in [id[tp1], id[u]];
        u = fa[tp1];
        tp1 = top[u];
    }
    if (dep[u] < dep[v]) {
        swap(u, v);
        bo ^= 1;
    }
    if (u != v) add(id[son[v]], id[u], bo);
    // if Edge && u != v, operator in [id[son[u]], id[v]];
    // operator in [id[u], id[v]];
}

bool query(int v, int x = 0) {
    if (node[x].l == node[x].r) return (node[x].sum[0] && node[x].sum[1]);
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (v <= mid) return query(v, lson(x));
    else return query(v, rson(x));
}

int fuck;

bool judge() {
    for (int i = 1; i <= bccn; i++) 
        if (query(i)) {
            fuck = i;
            return false;
        }
    return true;
}

int parent[N];

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    init();
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        add_Edge(u, v, i);
        add_Edge(v, u, i);
    }
    find_cut();
    find_bcc();
    init();
    for (int i = 1; i <= bccn; i++) parent[i] = i;
    for (int i = 0; i < cutn; i++) {
        int u = bccno[cut[i].u];
        int v = bccno[cut[i].v];
        int pu = find(u), pv = find(v);
        if (pu != pv) parent[pu] = pv;
        add_Edge(u, v, 1);
        add_Edge(v, u, 1);
    }
    for (int i = 1; i <= bccn; i++) {
        if (fa[i]) continue;
        dfs1(i, i, 1);
        dfs2(i, i);
    }
    build(1, bccn);
    int flag = 1;
    while (q--) {
        scanf("%d%d", &u, &v);
        if (!flag || bccno[u] == bccno[v]) continue;
        if (find(bccno[u]) != find(bccno[v])) {
            flag = 0;
            continue;
        }
        gaoadd(bccno[u], bccno[v]);
    }
    printf("%s\n", (flag && judge()) ? "Yes" : "No");
    return 0;
}