#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long i64;
typedef vector<i64> vi;
typedef pair<i64, i64> pii;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
// #define sz(x) int((x).size())
const i64 inf = 2e18;

const int maxn = 300500;

int n;
pii a[maxn];
i64 have;

i64 shr[maxn];
int k;

void scan() {
    cin >> n;
    cin >> have;
    i64 _; cin >> _;
    --n;
    forn(i, n) {
        cin >> a[i].fi >> a[i].se;
        ++a[i].se;
        shr[i] = a[i].se - a[i].fi;
    }
}

struct E {
    i64 s;
    int c;
    E() : s(0), c(0) {}
    E(i64 s, int c) : s(s), c(c) {}
};

E operator+(const E& a, const E& b) {
    E e;
    e.s = min(inf, a.s + b.s);
    e.c = a.c + b.c;
    return e;
}

const int sz = 1<<19;
E rmq[sz*2+14];
void put(int i, i64 x) {
    i += sz;
    assert(rmq[i].c == 0);
    assert(rmq[i].s == 0);
    rmq[i] = rmq[i] + E(x, 1);
    for (i /= 2; i; i /= 2) rmq[i] = rmq[i*2] + rmq[i*2+1];
}

// max c: can take with have
int get(i64 have) {
    int v = 1;
//     cerr << rmq[v].c << endl;
    if (rmq[v].s <= have) return rmq[v].c;
    int c = 0;
    while (v < sz) {
        if (rmq[v*2].s > have) {
            v = v*2;
        } else {
            have -= rmq[v*2].s;
            c += rmq[v*2].c;
            v = v*2+1;
        }
    }
    assert(rmq[v].s > have);
//     cerr << "c = " << c << endl;
    return c;
}

int sval[maxn];

void getshr() {
    sort(shr, shr+n);
//     unique(shr, shr+n);

    forn(i, n) {
        i64 v = a[i].se - a[i].fi;
        int p = lower_bound(shr, shr+n, v) - shr;
        --shr[p];
        sval[i] = p;
    }
}

void solve() {
    forn(i, n) a[i].se = -a[i].se;
    sort(a, a+n, greater<pii>());
    forn(i, n) a[i].se = -a[i].se;

    getshr();
//     forn(i, n) cerr << sval[i] << " "; cerr << endl;

    a[n] = {0,0};

    int best = n;

    forn(i, n+1) {
        i64 give = have - a[i].fi;
        if (give >= 0) {
            int c = get(give);
//             cerr << i << ": give " << give << endl;
//             cerr << i << ": kills " << c << endl;
            best = min(best, i-c);
        }
        if (i != n) {
            put(sval[i], a[i].se-a[i].fi);
//             cerr << "put " << a[i].se - a[i].fi << " to " << sval[i] << endl;
        }
//         cerr << endl;
    }

    cout << best+1 << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}