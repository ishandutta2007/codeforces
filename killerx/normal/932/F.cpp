#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct FUNC {
    ll a, b;
    FUNC(): a(1e18), b(0) {}
    FUNC(ll a, ll b): a(a), b(b) {}
    ll get(int x) { return a + b * x; }
};

struct LCSEG {
    static const int mxn = 1e5 + 7;
    struct Node {
        FUNC f;
        Node *ls, *rs;
    };
    void ins(FUNC f0, Node *&i, int l = -mxn, int r = mxn) {
        if (!i) {
            i = new Node();
        }
        if (l + 1 == r) {
            if (f0.get(l) < i->f.get(l)) i->f = f0;
            return ;
        }
        int m = l + ((r - l) >> 1);
        bool lef = f0.get(l) < i->f.get(l);
        bool mid = f0.get(m) < i->f.get(m);
        if (mid) {
            swap(i->f, f0);
        }
        if (lef != mid) {
            ins(f0, i->ls, l, m);
        } else {
            ins(f0, i->rs, m, r);
        }
    }
    ll get(int x, Node *i, int l = -mxn, int r = mxn) {
        if (!i) {
            return 1e18;
        }
        if (l + 1 == r) {
            return i->f.get(x);
        }
        int m = l + ((r - l) >> 1);
        ll ans = i->f.get(x);
        if (x < m) {
            ans = min(ans, get(x, i->ls, l, m));
        } else {
            ans = min(ans, get(x, i->rs, m, r));
        }
        return ans;
    }
    Node *merge(Node *&x, Node *&y, int l = -mxn, int r = mxn) {
        if (!x || !y) {
            return x ? x : y;
        }
        ins(y->f, x, l, r);
        int m = l + ((r - l) >> 1);
        x->ls = merge(x->ls, y->ls, l, m);
        x->rs = merge(x->rs, y->rs, m, r);
        return x;
    }
} lcseg;

const int mxn = 1e5 + 5;
int n;
int a[mxn], b[mxn];
LCSEG::Node *rt[mxn];
ll ans[mxn];
vector <int> g[mxn];

void dfs(int u, int p) {
    bool leaf = 1;
    rep(i, g[u].size()) {
        int v = g[u][i];
        if (v == p) continue;
        leaf = 0;
        dfs(v, u);
        rt[u] = lcseg.merge(rt[u], rt[v]);
    }
    if (leaf) {
        lcseg.ins(FUNC(0, b[u]), rt[u]);
    } else {
        ans[u] = lcseg.get(a[u], rt[u]);
        lcseg.ins(FUNC(ans[u], b[u]), rt[u]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1);
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    return 0;
}