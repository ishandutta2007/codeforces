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
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
typedef pair<i64, i64> pii;

const int sz = 1<<17;
const i64 inf = 1e18;

const int maxn = 200500;

int n, m, s;
int tt[maxn], l[maxn], r[maxn], u[maxn]; // 0: u -> (l, r); 1: (l, r) -> u
int w[maxn];
i64 d[maxn];
bool usedPlan[maxn];
int b[maxn];
vi e[maxn];

struct node {
    int l, r;
    node *L, *R;
    pii mn;
    i64 upd = inf;
    node(int l, int r) : l(l), r(r), mn(inf, l) {
        if (l+1 == r) {
            L = R = NULL;
        } else {
            int m = (l+r)/2;
            L = new node(l, m);
            R = new node(m, r);
        }
    }

    void apply(i64 x) {
        upd = min(upd, x);
        if (mn.fi <= inf) {
            mn.fi = min(mn.fi, upd);
        }
    }

    void push() {
        if (L) {
            L->apply(upd);
            R->apply(upd);
        }
        upd = inf;
    }

    void update() {
        mn = min(L->mn, R->mn);
    }

    pii get() {
        return mn;
    }

    void set(int lq, int rq, i64 val) {
        if (lq <= l && r <= rq) {
            apply(val);
        } else if (r <= lq || rq <= l) {
        } else {
            push();
            L->set(lq, rq, val);
            R->set(lq, rq, val);
            update();
        }
    }

    void setInf(int i) {
        if (l+1 == r) {
            assert(l == i);
            mn = {inf + 1, i};
        } else {
            push();
            if (i < (l+r)/2) {
                L->setInf(i);
            } else {
                R->setInf(i);
            }
            update();
        }
    }
};

vi rmq2[sz*2];
vi get2(int i) {
    i += sz;
    vi res;
    for (; i; i /= 2) {
        for (int x: rmq2[i]) {
            if (!usedPlan[x]) {
                res.pb(x);
            }
        }
        rmq2[i].clear();
    }
    return res;
}
void put2(int l, int r, int x) {
    l += sz, r += sz;
    while (l < r) {
        if (l%2 == 1) rmq2[l].pb(x);
        if (r%2 == 0) rmq2[r].pb(x);
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) rmq2[l].pb(x);
}

void scan() {
    cin >> n >> m >> s;
    --s;
    int*t = tt;
    forn(i, m) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> u[i] >> l[i];
            --u[i], --l[i];
            r[i] = l[i];
            t[i] = 0;
        } else if (t[i] == 2) {
            cin >> u[i] >> l[i] >> r[i];
            --u[i], --l[i], --r[i];
            t[i] = 0;
        } else {
            cin >> u[i] >> l[i] >> r[i];
            --u[i], --l[i], --r[i];
            t[i] = 1;
        }

        cin >> w[i];

//         if (t[i] == 0) {
//             cerr << "can go from " << u[i] << " to [" << l[i] << ", " << r[i] << "] ";
//         } else {
//             cerr << "can go from [" << l[i] << ", " << r[i] << "] to " << u[i] << " ";
//         }
//         cerr << "w = " << w[i] << endl;
    }
}

node *t;
priority_queue<pii, vector<pii>, greater<pii>> q;

void solve() {
    forn(i, m) {
        if (tt[i] == 0) e[u[i]].pb(i);
        else put2(l[i], r[i], i);
    }

    forn(i, n) d[i] = inf;
    t = new node(0, n);

    q.emplace(0, s);
    while (true) {
        i64 wt = inf;
        int vt = -1;
        i64 wq = inf;
        int vq = -1;

        if (!q.empty()) {
            wq = q.top().fi;
            vq = q.top().se;
        }

        auto tg = t->get();
        wt = tg.fi;
        vt = tg.se;

        if (wt >= inf && wq >= inf) break;

        int v = -1;
        i64 w;
        if (wt < wq) {
            t->setInf(vt);
            v = vt;
            w = wt;
        } else {
            q.pop();
            v = vq;
            w = wq;
        }

        assert(v != -1);

        if (b[v]) {
            continue;
        }

        b[v] = 1;
        d[v] = w;

        for (int id: e[v]) {
            int l = ::l[id];
            int r = ::r[id] + 1;
            i64 nw = w + ::w[id];
            t->set(l, r, nw);
        }

        for (auto id: get2(v)) {
            assert(!usedPlan[id]);
            usedPlan[id] = true;
            i64 nw = w + ::w[id];
            int u = ::u[id];
            if (d[u] > nw) {
                d[u] = nw;
                q.emplace(d[u], u);
            }
        }
    }

    forn(i, n) {
        if (d[i] == inf) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}