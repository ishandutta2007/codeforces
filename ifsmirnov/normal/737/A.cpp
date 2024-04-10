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
const int inf = 1e9+100500;

const int maxn = 200500;

int n, k, s, t;

int c[maxn], v[maxn];
int g[maxn];

void scan() {
    scanf("%d%d%d%d", &n, &k, &s, &t);
    forn(i, n) scanf("%d%d", &c[i], &v[i]);
    forn(i, k) scanf("%d", &g[i]);
    sort(g, g+k);
    g[k++] = s;
}

bool can(int v) {
    int ct = 0;
    forn(i, k) {
        int d = g[i] - (i ? g[i-1] : 0);
        int x = min(d, v-d);
        if (v < d) return false;
        ct += x + 2*(d-x);
    }
    return ct <= t;
}

void solve() {
    int l = 0, r = 2e9 + 100;
    if (!can(r)) { cout << -1 << endl; return; }
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (can(m)) r = m;
        else l = m;
    }

    int best = inf;
    forn(i, n) if (v[i] >= r) best = min(best, c[i]);
    if (best == inf) best = -1;
    cout << best << endl;
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