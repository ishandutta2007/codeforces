#include <bits/stdc++.h>
#define IOS std::cin.tie(nullptr)->sync_with_stdio(false);
using namespace std;
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid  (l+((r-l)>>1))
using ll = long long;
const int maxn = 1e5 + 50;

int n, q;
ll a[maxn];

struct edge_node {
    int to, nxt;
} edge[maxn<<1];

int head[maxn], id = 2;

inline void add_edge(int u, int v) {
    edge[id] = edge_node {v, head[u]};
    head[u] = id++;
    edge[id] = edge_node {u, head[v]};
    head[v] = id++;
}

int dfn[maxn], cnt = 0, top[maxn], fa[maxn], son[maxn], depth[maxn], sz[maxn];
ll dfnw[maxn];

void dfs1(int u, int pre) {
    fa[u] = pre;
    depth[u] = depth[pre] + 1;
    sz[u] = 1;
    for(int i = head[u]; i;i = edge[i].nxt) {
        int v = edge[i].to;
        if(v != pre) {
            dfs1(v, u);
            sz[u] += sz[v];
            if(sz[son[u]] < sz[v]) {
                son[u] = v;
            }
        }
    }
}

void dfs2(int u, int t) {
    dfn[u] = ++cnt;
    dfnw[cnt] = a[u];
    top[u] = t;
    if(!son[u]) { return; }
    dfs2(son[u], t);
    for(int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(v != fa[u] && v != son[u]) {
            dfs2(v, v);
        }
    }
}

struct ty {
    ll sum;
} tree[maxn<<2];

inline void push_up(int rt) {
    auto& res = tree[rt];
    auto& lres = tree[lson];
    auto& rres = tree[rson];
    res.sum = lres.sum + rres.sum;
}

void build(int rt, int l, int r) {
    if(l == r) {
        tree[rt].sum = dfnw[l];
        return;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(rt);
}

void modify(int rt, int l, int r, int x, ll val) {
    if(l == r) {
        tree[rt].sum = val;
        return;
    }
    if(x <= mid) {
        modify(lson, l, mid, x, val);
    } else {
        modify(rson, mid + 1, r, x, val);
    }
    push_up(rt);
}

ll query(int rt, int l, int r, int x, int y) {
    if(x == l && r == y) {
        return tree[rt].sum;
    }
    if(y <= mid) {
        return query(lson, l, mid, x, y);
    } else if(x > mid) {
        return query(rson, mid + 1, r, x, y);
    }
    auto lres = query(lson, l, mid, x, mid);
    auto rres = query(rson, mid + 1, r, mid + 1, y);
    return lres + rres;
}

void modify_vertex(int u, ll val) {
    modify(1, 1, n, dfn[u], val);
}

ll query_path(int u, int v) {
    ll res = 0;
    while(top[u] != top[v]) {
        if(depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }
        ll tmp = query(1, 1, n, dfn[top[u]], dfn[u]);
        res = res + tmp;
        u = fa[top[u]];
    }
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    ll tmp = query(1, 1, n, dfn[v], dfn[u]);
    res = res + tmp;
    return res;
}


signed main() {
    IOS
    cin >> n >> q;
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for(int i = 1;i <= n - 1;++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int u;
            ll val;
            cin >> u >> val;
            val = abs(val);
            a[u] = val;
            modify_vertex(u, val);
        } else {
            int u, v;
            cin >> u >> v;
            ll res = query_path(u, v);
            ll ans = res * 2 - a[u] - a[v];
            cout << ans << '\n';
        }
    }
    return 0;
}