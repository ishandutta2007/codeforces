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
int n;
int a[maxn], b[maxn], p;

ld can(ld t) {
    ld s = 0;
    forn(i, n) {
        ld need = max(ld(0), 1.0 * a[i] * t - b[i]);
        s += need / p;
    }
    return s <= t;
}

void solve() {
    cin >> n >> p;
    forn(i, n) cin >> a[i] >> b[i];
    ld l = 0, r = 1e18;
    if (can(r)) {
        cout << -1 << "\n";
        return;
    }
    forn(i, 120) {
        ld m = (l+r)/2;
        if (can(m)) l = m;
        else r = m;
    }
    cout.precision(10);
    cout << fixed;
    cout << (l+r)/2 << endl;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}