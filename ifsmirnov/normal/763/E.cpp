#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 100500;

int n, k;
vi e[maxn];

int p[maxn];
int get(int x) { return x == p[x] ? x : (p[x] = get(p[x])); }
bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    p[x] = y;
    return true;
}

struct node {
    int l, r;
    node *L, *R;
    int lp[6], rp[6];
    int nc;

    node(int l, int r) : l(l), r(r) {
        if (l+1 == r) {
            lp[0] = rp[k-1] = l;
            L = R = NULL;
            nc = 1;
        } else {
            int m = (l+r)/2;
            L = new node(l, m);
            R = new node(m, r);
            nc = L->nc + R->nc;

            for (int v = m-k; v < m+k; ++v) if (l <= v && v < r) {
                for (int to: e[v]) if (l <= to && to < r) {
                    nc -= unite(v, to);
                }
            }
            forn(i, min(k, r-l)) {
                lp[i] = ::get(l+i);
                rp[k-i-1] = ::get(r-i-1);
            }
        }
    }

    void get(int lq, int rq, vector<node*>& a) {
        if (lq <= l && r <= rq) a.pb(this);
        else if (lq >= r || rq <= l) return;
        else {
            L->get(lq, rq, a);
            R->get(lq, rq, a);
        }
    }
};

void scan() {
    scanf("%d%d", &n, &k);
    int m;
    scanf("%d", &m);
    forn(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[--x].pb(--y);
        e[y].pb(x);
    }
}

node *t;

int fakeid[maxn];

int answer(int l, int r) {
    vector<node*> a;
    t->get(l, r, a);
    assert(!a.empty());
    assert(a[0]->l == l);
    assert(a.back()->r == r);
    forn(i, a.size()-1) assert(a[i]->r == a[i+1]->l);

    int nc = 0;

    vector<int> pos;
    vector<int> comps;
    for (node* t: a) {
        int len = min(k, t->r - t->l);
        forn(i, len) {
            pos.pb(t->l + i);
            fakeid[t->l + i] = t->lp[i];
            comps.pb(t->lp[i]);
            pos.pb(t->r - i - 1);
            fakeid[t->r - i - 1] = t->rp[k - i - 1];
            comps.pb(t->rp[k-i-1]);
        }

        nc += t->nc;
    }

    sort(all(comps));
    comps.erase(unique(all(comps)), comps.end());
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    for (int x: comps) p[x] = x;

    for (int v: pos) {
        assert(fakeid[v] != -1);
        for (int to: e[v]) {
            if (fakeid[to] == -1) continue;

            nc -= unite(fakeid[v], fakeid[to]);
        }
    }

    for (int x: pos) fakeid[x] = -1;

    return nc;
}

void solve() {
    memset(fakeid, -1, sizeof fakeid);
    forn(i, n) p[i] = i;
    t = new node(0, n);

    int q;
    scanf("%d", &q);
    forn(i, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        int res = answer(l-1, r);
        printf("%d\n", res);
    }

    cerr << "total comps: " << t->nc << endl;
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}