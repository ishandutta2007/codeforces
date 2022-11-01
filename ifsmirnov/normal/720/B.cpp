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

vi cycles[maxn];
int nc;

int n, m;
vector<pii> e[maxn];
int b[maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u, --v;
        e[u].pb({v, c});
        e[v].pb({u, c});
    }
}

vi path;
vi cols;
void dfs(int v, int anc) {
    b[v] = 1;
    path.pb(v);

    for (auto kv: e[v]) {
        int to = kv.fi;
        if (to == anc) continue;
        cols.pb(kv.se);

        if (b[to] == 0) dfs(to, v);
        else if (b[to] == 1) {
            int root = to;
            for (int i = path.size() - 1; ; --i) {
                cycles[nc].pb(cols[i]);
                if (path[i] == root) break;
                assert(i >= 0);
            }
            ++nc;
        }
        cols.pop_back();
    }

    b[v] = 2;
    path.pop_back();
}

int p[maxn];
int ok[maxn];

int get(int x) { return x == p[x] ? x : (p[x] = get(p[x])); }
void unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) ok[x] = true;
    else {
        p[x] = y;
        ok[y] |= ok[x];
    }
}

void solve() {
    dfs(0, -1);

#ifdef LOCAL
    forn(i, nc) {
        for (int x: cycles[i]) cerr << x << " "; cerr << endl;
    }
#endif
    int ncol = m + 1;
//     int ncol = 0;
    map<int, int> cnt;
    forn(v, n) for (auto kv: e[v]) if (v < kv.fi) {
        int c = kv.se;
//         ncol = max(ncol, c+1);
        ++cnt[c];
    }
//     cerr << "ncol = " << ncol << endl;

    forn(i, nc) for (int x: cycles[i]) {
        --cnt[x];
        assert(cnt[x] >= 0);
    }

    int m = ncol + nc;
    forn(i, ncol + nc) p[i] = i;
    for (auto kv: cnt) if (kv.se > 0) ok[kv.fi] = 1;
//     forn(i, m) cerr << ok[i] << " "; cerr << endl;

    forn(i, nc) for (int x: cycles[i]) {
        unite(x, i+ncol);
//         cerr << "unite " << x << " " << i+ncol << endl;
    }

    int res = cnt.size();
//     cerr << "res = " << res << endl;
    forn(i, nc + ncol) {
        if (i < ncol && !cnt.count(i)) continue;
        if (p[i] == i && !ok[i]) {
//             cerr << "i = " << i << endl;
            --res;
        }
    }

    cout << res << endl;
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