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
// #define sz(x) int((x).size())

bool prime(int n) {
    for (int i = 2; i < n; ++i) if (n%i == 0) return false;
    return true;
}

vi ppr;
vi pprm[100];

void genpr() {
    fore(i, 2, 40) if (prime(i)) {
        int x = i;
        while (x <= 40) ppr.pb(x), x *= i;
    }
    sort(all(ppr));
    ppr.shrink_to_fit();
    fore(i, 2, 40) {
        for (int x: ppr) if (i%x == 0) {
            pprm[i].pb(x);
        }
        pprm[i].shrink_to_fit();
    }
}

const int maxn = 100500;

int n, m;
vi a[maxn];
int lastseen[maxn];
vi newnum[maxn];
int res[maxn];

void scan() {
    cin >> n >> m;
    forn(i, m+1) lastseen[i] = -111;
    forn(i, n) {
        int k;
        cin >> k;
        a[i].resize(k);
        forn(j, k) cin >> a[i][j];
        for (int x: a[i]) {
            if (lastseen[x] < i-1) {
                newnum[i].pb(x);
            }
            lastseen[x] = i;
        }
    }
//     forn(i, n) {
//         for (int x: newnum[i]) cerr << x << " ";
//         cerr << endl;
//     }
//     cerr << endl;
}

int has(int i, int x) {
    auto it = find(all(a[i]), x);
    return it != a[i].end();
}

int pos(int i, int x) {
#ifdef LOCAL
//     assert(has(i, x));
#endif
    auto it = find(all(a[i]), x);
    if (it == a[i].end()) return -1;
    return it - a[i].begin();
}

int cnt[40][40];
int ccnt[40];

bool check(int m, int i) {
//     for (int p: ppr) if (m%p == 0) {
    for (int p: pprm[m]) {
        if (cnt[p][i%p] != ccnt[p]) return false;
    }
    return true;
}

void apply(int m, int i, int d) {
//     for (int p: ppr) if (m%p == 0) {
    for (int p: pprm[m]) {
        cnt[p][i%p] += d;
        ccnt[p] += d;
    }
}

void solve(int st, int x) {
//     if (st != 0 || x != 1) return;
//     cerr << "go " << st << " " << x << endl;
    int l = st, r = st;
    int R = n;
//     while (has(R, x)) ++R;
    for (; l < R; ++l) {
        while (r < R) {
            int p = pos(r, x);
            if (p == -1) {
                R = r;
                break;
            }
            if (check(a[r].size(), p)) {
                apply(a[r].size(), p, 1);
                ++r;
            } else {
                break;
            }
        }
        res[x] = max(res[x], r-l);
        apply(a[l].size(), pos(l, x), -1);
    }
}

void solve() {
    forn(st, n) {
        for (int x: newnum[st]) {
            solve(st, x);
        }
    }
    forn(i, m) cout << res[i+1] << "\n";
}

int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    genpr();

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}