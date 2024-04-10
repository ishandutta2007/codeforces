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
pii a[maxn];
int d[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", &a[i+1].fi, &a[i+1].se);
    sort(a+1, a+n+1);
    a[0].fi = -1000000000;
}

void solve() {
    d[0] = 0;
    int res = n;
    fore(i, 1, n) {
        int x = a[i].fi - a[i].se;
        int j = lower_bound(a, a+n+1, pii(x, -1)) - a - 1;
        assert(j < i);
        d[i] = i-j-1 + d[j];
        res = min(res, d[i] + (n-i));
    }
    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}