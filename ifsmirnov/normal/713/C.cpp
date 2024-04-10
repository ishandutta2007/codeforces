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

const int maxn = 3050;

int n;
i64 a[maxn];
i64 d[maxn], g[maxn];
i64 vals[maxn], k;

void relax(i64& x, i64 y) {
    x = min(x, y);
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    cin >> n;
    forn(i, n) {
        cin >> a[i];
        a[i] -= i;
        vals[i] = a[i];
    }
    sort(vals, vals+n);
    k = unique(vals, vals+n) - vals;
    forn(i, n) a[i] = lower_bound(vals, vals+k, a[i]) - vals;

    forn(i, k) d[i] = abs(vals[a[0]] - vals[i]);

    forn(i, n) if (i) {
        forn(j, k) g[j] = inf;

        i64 mn = inf;
        forn(j, k) {
            mn = min(mn, d[j]);
            relax(g[j], mn + abs(vals[a[i]] - vals[j]));
        }

        forn(j, k) d[j] = g[j];
    }

    cout << *min_element(d, d+k) << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}