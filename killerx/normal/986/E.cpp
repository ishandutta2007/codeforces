#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 100005;
const int mod = 1000000007;

void uadd(int &x, int y, int mod) {
    x += y - mod;
    x += (x >> 31) & mod;
}

int qp(int x, int n, int mod) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

unsigned rng() {
    static unsigned x = (unsigned ll) new char;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

struct Op {
    int id, tp, x;
    Op(int id, int tp, int x): id(id), tp(tp), x(x) {}
};

struct Node {
    int v, s, sz;
    unsigned fix;
    Node *ls, *rs;
    void pushup() {
        s = v;
        if (ls) uadd(s, ls->s, mod - 1);
        if (rs) uadd(s, rs->s, mod - 1);
        sz = 1;
        if (ls) sz += ls->sz;
        if (rs) sz += rs->sz;
    }
} pool[10000000], *ptr = pool;

Node *newNode(int v) {
    Node *x = ptr ++;
    x->v = v;
    x->s = v;
    x->sz = 1;
    x->fix = rng();
    x->ls = NULL;
    x->rs = NULL;
    return x;
}

void split(Node *x, int v, Node *&a, Node *&b) {
    if (!x) { a = b = NULL; return ; }
    if (x->v <= v) {
        a = x;
        split(x->rs, v, a->rs, b);
        a->pushup();
    } else {
        b = x;
        split(x->ls, v, a, b->ls);
        b->pushup();
    }
}

Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    if (a->fix < b->fix) {
        a->rs = merge(a->rs, b);
        a->pushup();
        return a;
    } else {
        b->ls = merge(a, b->ls);
        b->pushup();
        return b;
    }
}

int n, q;
int a[mxn];
vector <pair <int, int> > fac[mxn];
vector <int> g[mxn];
int dep[mxn], fa[mxn][20];
vector <Op> qry[mxn];
Node *vec[10000007];
int ans[mxn];

void factor(int x, vector <pair <int, int> > &vec) {
    for (int i = 2; 1LL * i * i <= x; ++ i) {
        if (x % i == 0) {
            int e = 0;
            while (x % i == 0) x /= i, ++ e;
            vec.pb(mp(i, e));
        }
    }
    if (x > 1) vec.pb(mp(x, 1));
}

void INS(int x, int v) {
    Node *a, *b, *c;
    split(vec[x], v, a, b);
    c = newNode(v);
    vec[x] = merge(merge(a, c), b);
}

void DEL(int x, int v) {
    Node *a, *b, *c;
    split(vec[x], v, a, b);
    split(a, v - 1, a, c);
    c = merge(c->ls, c->rs);
    vec[x] = merge(merge(a, c), b);
}

void dfs0(int u, int p) {
    rep(i, 20 - 1) fa[u][i + 1] = fa[fa[u][i]][i];
    rep(i, g[u].size()) {
        int v = g[u][i];
        if (v == p) continue;
        fa[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs0(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 20 - 1; ~i; -- i)
        if ((dep[v] - dep[u]) >> i & 1)
            v = fa[v][i];
    if (u == v) return u;
    for (int i = 20 - 1; ~i; -- i)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void dfs1(int u, int p) {
    rep(i, fac[u].size()) {
        int x = fac[u][i].first;
        int e = fac[u][i].second;
        INS(x, e);
    }
    rep(i, qry[u].size()) {
        int id = qry[u][i].id;
        int tp = qry[u][i].tp;
        int x = qry[u][i].x;
        vector <pair <int, int> > facx;
        factor(x, facx);
        rep(j, facx.size()) {
            int y = facx[j].first;
            int e = facx[j].second;
            Node *a, *b;
            split(vec[y], e, a, b);
            int expo = a ? a->s : 0;
            uadd(expo, 1LL * (b ? b->sz : 0) * e % (mod - 1), mod - 1);
            if (tp == -1) expo = mod - 1 - expo;
            ans[id] = 1LL * ans[id] * qp(y, expo, mod) % mod;
            vec[y] = merge(a, b);
        }
    }
    rep(i, g[u].size()) {
        int v = g[u][i];
        if (v == p) continue;
        dfs1(v, u);
    }
    rep(i, fac[u].size()) {
        int x = fac[u][i].first;
        int e = fac[u][i].second;
        DEL(x, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        -- u, -- v;
        g[u].pb(v), g[v].pb(u);
    }
    rep(i, n) cin >> a[i], factor(a[i], fac[i]);
    dfs0(0, -1);
    cin >> q;
    rep(i, q) {
        int u, v, x;
        cin >> u >> v >> x;
        -- u, -- v;
        int l = lca(u, v);
        qry[u].pb(Op(i, +1, x));
        qry[v].pb(Op(i, +1, x));
        qry[l].pb(Op(i, -1, x));
        if (l) qry[fa[l][0]].pb(Op(i, -1, x));
        ans[i] = 1;
    }
    dfs1(0, -1);
    rep(i, q) cout << ans[i] << "\n";
    return 0;
}