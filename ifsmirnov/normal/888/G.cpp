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

const int maxn = 200500;
const int K = 30;

int n;
int a[maxn];
int s0[maxn][K];
i64 res;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
    n = unique(a, a+n) - a;
}

int ask(int l, int r, int k, int x) {
    int res = 0;
    while (k >= 0) {
        int b = (x>>k)&1;
        if (s0[l][k] == 0) res += (!b)<<k;
        else if (s0[l][k] == r-l) res += b<<k;
        else if (b) l += s0[l][k];
        else r = l + s0[l][k];
        --k;
    }
    return res;
}

void go(int l, int r, int k) {
    if (l == r) return;
    int m = l;
    while (m < r && (a[m]&(1<<k)) == 0) ++m;
    if (k > 0) {
        go(l, m, k-1);
        go(m, r, k-1);
    }
    s0[l][k] = m - l;
    if (m == l || m == r) return;
    int mn = 1<<30;
    // if (m-l < r-m) {
        for (int i = l; i < m; ++i) mn = min(mn, ask(m, r, k, a[i]));
    // } else {
        // for (int i = m; i < r; ++i) mn = min(mn, ask(l, m, k, a[i]));
    // }
    res += mn;
}

int main() {
#ifdef LOCAL
    freopen("g.in", "r", stdin);
#endif

    scan();
    go(0, n, K-1);
    cout << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}