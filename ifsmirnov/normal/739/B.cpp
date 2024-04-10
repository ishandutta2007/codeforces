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
int n;
vector<pii> e[maxn];
int a[maxn];
int s[maxn];
int res[maxn];

vector<i64> sh, sv;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) if (i) {
        int p, w;
        scanf("%d%d", &p, &w);
        e[p-1].pb({i, w});
    }
}

int dfs(int v, i64 h) {
    sh.pb(h);
    sv.pb(v);

    i64 val = h - a[v];
    int it = lower_bound(all(sh), val) - sh.begin();
    assert(it < (int)sh.size());
    ++s[sv[it]];

//     cerr << v << ": " << sv[it] << endl;

    int res = 1;
    for (auto kv: e[v]) {
        res += dfs(kv.fi, h+kv.se);
    }

    ::res[v] = res;
    res -= s[v];

    sv.pop_back();
    sh.pop_back();
    return res;
}

void solve() {
    dfs(0, 0);
    forn(i, n) printf("%d ", res[i] - 1);
    printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}