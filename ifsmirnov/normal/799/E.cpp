#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
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

const i64 inf = 1e18;

const int maxn = 200500;

const int sz = 1<<18;

int n, m, k, c[maxn];
vector<pii> a, b, ab; // {cost, id}
pii shr[maxn];

void scan() {
    cin >> n >> m >> k;
    forn(i, n) {
        cin >> c[i];
        shr[i] = {c[i], i};
    }
    int q;
    cin >> q;
    a.resize(q);
    forn(i, q) {
        cin >> a[i].se;
        --a[i].se;
        a[i].fi = c[a[i].se];
    }
    set<pii> com(all(a));
    cin >> q;
    b.resize(q);
    forn(i, q) {
        cin >> b[i].se;
        --b[i].se;
        b[i].fi = c[b[i].se];
        if (com.count(b[i])) ab.pb(b[i]);
    }
    com = set<pii>(all(ab));

    a.erase(remove_if(all(a), [&com](const pii& p) { return com.count(p); }), a.end());
    b.erase(remove_if(all(b), [&com](const pii& p) { return com.count(p); }), b.end());
}

typedef pair<int, i64> P;

P rmq[sz*2];
P add(P a, P b) {
    return P{a.fi+b.fi, a.se+b.se};
}

void add(int i, int x) {
//     cerr << "add " << i << " " << x << endl;
    i += sz;
    if (x == -1) rmq[i] = {0, 0};
    else rmq[i] = {1, x};
    for (i /= 2; i; i /= 2) {
        rmq[i] = add(rmq[i*2], rmq[i*2+1]);
    }
}

i64 get(int need) {
//     cerr << "get " << need << endl;
    if (need < 0 || need > rmq[1].fi) return inf;
    if (need == 0) return 0;
    int v = 1;
    i64 res = 0;
    while (v < sz) {
        if (rmq[v*2].fi >= need) {
            v *= 2;
        } else {
            need -= rmq[v*2].fi;
            res += rmq[v*2].se;
            v = v*2+1;
        }
    }
    assert(rmq[v].fi == 1);
    assert(need == 1);
    res += rmq[v].se;
//     cerr << "res = " << res << endl;
    return res;
}


void solve() {
    if (k > m) { cout << "-1\n"; return; }

    sort(shr, shr+n);
    for (auto& kv: a) kv.se = lower_bound(shr, shr+n, kv) - shr;
    for (auto& kv: b) kv.se = lower_bound(shr, shr+n, kv) - shr;
    for (auto& kv: ab) kv.se = lower_bound(shr, shr+n, kv) - shr;
    sort(all(a));
    sort(all(b));
    sort(all(ab));

    forn(i, n) add(lower_bound(shr, shr+n, pii{c[i], i}) - shr, c[i]);

    i64 best = inf;
    i64 cur = 0;
    forn(i, min(k, (int)ab.size())) {
        add(ab[i].se, -1);
        cur += ab[i].fi;
    }
    int na = k - min(k, (int)ab.size());
    if ((int)a.size() < na || (int)b.size() < na) {
        cout << "-1\n";
        return;
    }
    forn(i, na) {
        add(a[i].se, -1);
        add(b[i].se, -1);
        cur += a[i].fi;
        cur += b[i].fi;
    }


    for (int comm = min(k, (int)ab.size()); comm >= 0; --comm) {
        int na = k - comm;
//         cerr << comm << " common, " << na << " per person\n";
        if ((int)a.size() < na || (int)b.size() < na) break;

        if (comm + na*2 > m) break;

//         cerr << "cur = " << cur << endl;

        best = min(best, cur + get(m - comm - na*2));

        if ((int)a.size() <= na || (int)b.size() <= na) break;
        add(a[na].se, -1);
        add(b[na].se, -1);
        cur += a[na].fi;
        cur += b[na].fi;
        if (comm == 0) break;
        add(ab[comm-1].se, ab[comm-1].fi);
        cur -= ab[comm-1].fi;
    }

    if (best == inf) cout << -1 << "\n";
    else cout << best << "\n";
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}