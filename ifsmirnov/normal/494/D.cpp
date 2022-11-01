#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int mod = 1000000007;
const int maxn = 100500;
int add(int x, int y) { return (x+y)%mod; }
int add(int x, int y, int z) { return add(x, add(y, z)); }
int mul(int x, int y) { return (i64)x*y%mod; }
int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }

int n;
vector<pii> e[maxn];
int p[maxn][20], wp[maxn], h[maxn], H[maxn];
int cd[maxn], cu[maxn], sd[maxn], su[maxn], sd2[maxn], su2[maxn];
int tin[maxn], tout[maxn], dtime;

inline bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int getr1(int u, int w) {
    return add(sd[u], mul(w, add(cd[u], 1)));
}

int getr2(int u, int w) {
    return add(sd2[u], mul(2, mul(w, sd[u])), mul(cd[u] + 1, mul(w, w)));
}

void buildlca() {
    forn(k, 20) if (k) {
        forn(i, n) p[i][k] = p[p[i][k-1]][k-1];
    }
}

int lca(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    forn(k, 20) if ((H[u] - H[v]) & (1<<k)) {
        u = p[u][k];
    }
    assert(H[u] == H[v]);
    if (u == v) return u;

    ford(k, 20) {
        if (p[u][k] != p[v][k]) {
            u = p[u][k];
            v = p[v][k];
        }
    }
    return p[v][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return sub(add(h[u], h[v]), mul(2, h[l]));
}

void dfs1(int v, int anc) {
    tin[v] = dtime++;
    for (auto X : e[v]) {
        int u = X.fi, w = X.se;
        if (u == anc) continue;
        wp[u] = w;
        h[u] = add(h[v], w);
        H[u] = H[v] + 1;
        p[u][0] = v;
        dfs1(u, v);
        cd[v] += cd[u] + 1;
        sd[v] = add(sd[v], getr1(u, w));
        sd2[v] = add(sd2[v], getr2(u, w));
    }

    cu[v] = n - cd[v] - 1;
    tout[v] = dtime++;
}

void dfs2(int v, int anc) {
    // computations

    int u = anc;
    int w = wp[v];
    if (v != 0) {
        int c = cu[u] + cd[u] - (cd[v] + 1);
        int s = sub(add(su[u], sd[u]), getr1(v, w));
        int s2 = sub(add(su2[u], sd2[u]), getr2(v, w));

        su[v] = add(s, mul(w, add(c, 1)));
        su2[v] = add(s2, mul(2, mul(w, s)), mul(c + 1, mul(w, w)));
    }

    for (auto X : e[v]) {
        int u = X.fi;
        if (u != anc) {
            dfs2(u, v);
        }
    }
}

// int dfs2(int v, int anc) {
// }

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e[--u].pb(mp(--v, c));
        e[v].pb(mp(u, c));
//         cout << "add edge " << u << " " << v << endl;
    }
}

int query(int u, int v) {
    int res = add(sd2[u], su2[u]);
    if (anc(v, u)) {
        int W = sub(h[u], h[v]);
        int C = cu[v];
        int S = su[v];
        int S2 = su2[v];
        int radd = add(S2, mul(2, mul(S, W)), mul(C, mul(W, W)));
//         cout << "wer" << endl;
        return sub(res, mul(2, radd));
    } else {
        int W = dist(u, v);
        int C = cd[v] + 1;
        int S = sd[v];
        int S2 = sd2[v];
        int radd = add(S2, mul(2, mul(S, W)), mul(C, mul(W, W)));
//         cout << "www" << endl;
//         cout << res << " " << radd << endl;
        return sub(mul(2, radd), res);
    }
}

void gen_tree(int n) {
    ::n = n;
    fore(i, 1, n-1) {
        int j = rand()%i;
        int c = rand()%10 + 1;
        e[j].pb(mp(i, c));
        e[i].pb(mp(j, c));
    }
}

void dfs(int v, int anc, int cd, vi & a) {
    a.pb(cd);
    forn(i, e[v].size()) if (anc != e[v][i].fi) {
        dfs(e[v][i].fi, v, cd + e[v][i].se, a);
    }
}

void solved() {
    dfs1(0, -1);
    dfs2(0, -1);
    forn(i, n) {
        vi a;
        dfs(i, -1, 0, a);
        int s =0;
        for (auto x : a) s += x*x;
        if (s != sd2[i] + su2[i]) {
            cout << "fail" << endl;
            forn(v, n) {
                for (auto to : e[v]) cout << to.fi << " ";
                cout << endl;
            }
            exit(0);
        } else {
            cout << s << " " << sd2[i] << " " << su2[i] << endl;
        }
    }
}

void solve() {
    dfs1(0, -1);
    dfs2(0, -1);
    buildlca();
//     forn(i, n) cout << cd[i] << " "; cout << endl;
//     forn(i, n) cout << sd[i] << " "; cout << endl;
//     forn(i, n) cout << sd2[i] << " "; cout << endl;
//     cout << endl;
//     forn(i, n) cout << cu[i] << " "; cout << endl;
//     forn(i, n) cout << su[i] << " "; cout << endl;
//     forn(i, n) cout << su2[i] << " "; cout << endl;

    int q;
    scanf("%d", &q);
    forn(i, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", query(u-1, v-1));
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

//     gen_tree(200);
//     solved();
    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}