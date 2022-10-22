#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 2e5 + 5;

int n;
std::vector <int> adj[mxn];
int q;

struct Query {
    int k, i;
};
std::vector <Query> qry[mxn];

namespace BRUTE {
const int mxn = 2e3 + 5;

int sz[mxn];
int dp[mxn][mxn];

i64 ans[mxn];

void dfs(int u, int p) {
    sz[u] = 0;
    memset(dp[u], -0x3f, sizeof(dp[u]));
    dp[u][0] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        static int ndp[mxn];
        memset(ndp, -0x3f, sizeof(ndp));
        rep(a, sz[u] + 1) rep(b, sz[v] + 1) {
            ndp[a + b] = std::max(ndp[a + b], dp[u][a] + dp[v][b]);
        }
        memcpy(dp[u], ndp, sizeof(dp[u]));
        sz[u] += sz[v];
    }
    for (auto Q : qry[u]) {
        ans[Q.i] = -(1LL << 60);
        rep(a, sz[u] + 1) ans[Q.i] = std::max(ans[Q.i], dp[u][a] - 1LL * a * Q.k);
    }
    static int ndp[mxn];
    memset(ndp, -0x3f, sizeof(ndp));
    ndp[0] = std::max(ndp[0], 1);
    rep(a, sz[u] + 1) {
        ndp[a + 1] = std::max(ndp[a + 1], dp[u][a]);
    }
    memcpy(dp[u], ndp, sizeof(dp[u]));
    sz[u] += 1;
}
} // BRUTE

namespace UPGRADE {
const int mxn = 2e3 + 5;

struct Hull {
    int x[mxn], y[mxn], sz;

    Hull() { sz = 0; }

    void push_back(int X, int Y) {
        while (sz >= 2 && 1LL * (y[sz - 1] - Y) * (x[sz - 2] - x[sz - 1]) < 1LL * (y[sz - 2] - y[sz - 1]) * (x[sz - 1] - X)) -- sz;
        x[sz] = X, y[sz] = Y, ++ sz;
    }
};

Hull conv(Hull a, Hull b) {
    int bx = a.x[0] + b.x[0], by = a.y[0] + b.y[0];
    Hull c;
    c.push_back(bx, by);
    for (int i = 1, j = 1; i < a.sz || j < b.sz; ) {
        if (i < a.sz && (j == b.sz || 1LL * (a.y[i - 1] - a.y[i]) * (b.x[j - 1] - b.x[j]) < 1LL * (b.y[j - 1] - b.y[j]) * (a.x[i - 1] - a.x[i]))) {
            c.push_back(bx += a.x[i] - a.x[i - 1], by += a.y[i] - a.y[i - 1]);
            ++ i;
        } else {
            c.push_back(bx += b.x[j] - b.x[j - 1], by += b.y[j] - b.y[j - 1]);
            ++ j;
        }
    }
    return c;
}

i64 query(Hull a, int x) {
    int lb = 0, rb = a.sz - 1;
    while (lb < rb) {
        int md = (lb + rb) >> 1;
        if (a.y[md] - a.y[md + 1] < 1LL * x * (a.x[md] - a.x[md + 1])) lb = md + 1;
        else rb = md;
    }
    return a.y[lb] - 1LL * a.x[lb] * x;
}

int sz[mxn];
Hull dp[mxn];

i64 ans[mxn];

void dfs(int u, int p) {
    sz[u] = 0;
    dp[u].push_back(0, 0);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = conv(dp[u], dp[v]);
        sz[u] += sz[v];
    }
    for (auto Q : qry[u]) ans[Q.i] = query(dp[u], Q.k);
    rep(i, dp[u].sz) dp[u].x[i] += 1;
    dp[u].push_back(0, 1);
    sz[u] += 1;
    /*
    eprintf("%d | ", u);
    for (int i = 1; i < dp[u].sz; ++ i)
        eprintf("(%d, %d)", dp[u].x[i] - dp[u].x[i - 1], dp[u].y[i] - dp[u].y[i - 1]);
    eprintf("\n");
    */
}
} // UPGRADE

namespace SOL {
struct Node {
    int dx, dy, sx, sy;
    size_t siz;
    Node *ch[2], *fa;

    Node(int _dx, int _dy) {
        dx = sx = _dx, dy = sy = _dy;
        siz = 1;
        ch[0] = ch[1] = fa = nullptr;
    }

    ~Node() {
        if (ch[0]) delete ch[0];
        if (ch[1]) delete ch[1];
    }
};

using node = Node *;

inline bool comp(node a, node b) {
    return 1LL * a->dy * b->dx < 1LL * b->dy * a->dx;
}

inline void pushup(node x) {
    x->sx = x->dx, x->sy = x->dy, x->siz = 1;
    if (x->ch[0]) x->sx += x->ch[0]->sx, x->sy += x->ch[0]->sy, x->siz += x->ch[0]->siz;
    if (x->ch[1]) x->sx += x->ch[1]->sx, x->sy += x->ch[1]->sy, x->siz += x->ch[1]->siz;
}

inline void rotate(node x) {
    node y = x->fa, z = y->fa;
    if (z) z->ch[y == z->ch[1]] = x;
    x->fa = z;
    bool d = x == y->ch[1];
    y->ch[d] = x->ch[d ^ 1];
    if (y->ch[d]) y->ch[d]->fa = y;
    x->ch[d ^ 1] = y;
    y->fa = x;
    pushup(y);
    pushup(x);
}

inline node splay(node x) {
    while (x->fa) {
        node y = x->fa, z = y->fa;
        if (z) rotate((x == y->ch[1]) ^ (y == z->ch[1]) ? x : y);
        rotate(x);
    }
    return x;
}

inline node __insert(node x, node v) {
    if (!x) return v;
    if (comp(x, v)) x->ch[1] = __insert(x->ch[1], v), x->ch[1]->fa = x;
    else x->ch[0] = __insert(x->ch[0], v), x->ch[0]->fa = x;
    pushup(x);
    return x;
}

inline node insert(node x, node v) {
    __insert(x, v);
    return splay(v);
}

inline node merge(node x, node y) {
    if (!x || !y) return x ? x : y;
    if (x->siz < y->siz) std::swap(x, y);
    node ls = y->ch[0], rs = y->ch[1];
    y->ch[0] = y->ch[1] = y->fa = nullptr;
    x = merge(x, ls);
    x = insert(x, y);
    x = merge(x, rs);
    return x;
}

inline void debug(node x) {
    if (!x) return ;
    debug(x->ch[0]);
    eprintf("(%d, %d)", x->dx, x->dy);
    debug(x->ch[1]);
}

struct Hull {
    int bx, by;
    node dif;

    void push_back(int X, int Y) {
        while (dif) {
            node u = dif;
            while (u->ch[1]) u = u->ch[1];
            dif = splay(u);
            node v = dif->ch[0];
            int xm1 = bx + u->sx, ym1 = by + u->sy;
            int xm2 = bx + (v ? v->sx : 0), ym2 = by + (v ? v->sy : 0);
            if (1LL * (ym1 - Y) * (xm2 - xm1) < 1LL * (ym2 - ym1) * (xm1 - X)) {
                u->ch[0] = nullptr;
                if (v) v->fa = nullptr;
                dif = v;
                delete u;
            } else break;
        }
        int xm1 = bx + (dif ? dif->sx : 0);
        int ym1 = by + (dif ? dif->sy : 0);
        node u = new Node(X - xm1, Y - ym1);
        dif = insert(dif, u);
    }
};

Hull conv(Hull a, Hull b) {
    return {a.bx + b.bx, a.by + b.by, merge(a.dif, b.dif)};
}

i64 query(Hull &a, int x) {
    node u = a.dif, v = nullptr;
    int bx = a.bx, by = a.by;
    while (u) {
        v = u;
        if (-u->dy < 1LL * x * -u->dx) {
            if (u->ch[0]) bx += u->ch[0]->sx, by += u->ch[0]->sy;
            bx += u->dx, by += u->dy;
            u = u->ch[1];
        } else {
            u = u->ch[0];
        }
    }
    if (v) a.dif = splay(v);
    return by - 1LL * bx * x;
}

int sz[mxn];
Hull dp[mxn];
i64 ans[mxn];

void dfs(int u, int p) {
    sz[u] = 0;
    dp[u] = {0, 0, nullptr};
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = conv(dp[u], dp[v]);
        sz[u] += sz[v];
    }
    for (auto Q : qry[u]) ans[Q.i] = query(dp[u], Q.k);
    dp[u].bx += 1;
    dp[u].push_back(0, 1);
    sz[u] += 1;
    /*
    eprintf("%d | ", u);
    debug(dp[u].dif);
    eprintf("\n");
    */
}
} // SOL

using namespace SOL;

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    rep(i, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d", &q);
    rep(i, q) {
        int u, k;
        scanf("%d %d", &u, &k);
        -- u;
        qry[u].push_back({k, i});
    }
    dfs(0, -1);
    rep(i, q) printf("%lld\n", ans[i]);
    return 0;
}