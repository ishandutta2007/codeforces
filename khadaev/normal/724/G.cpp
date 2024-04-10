#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int B = 60;

vector<vector<pair<int, ll>>> e;
vector<int> comp;
vector<pair<int, ll>> par;
vector<ll> path;
vector<int> cnt[B][2];

void dfs(int i, int c) {
    comp[i] = c;
    forn(j, 0, B) cnt[j][0][i] = 1;
    for (pair<int, ll> p : e[i])
        if (!comp[p.fs]) {
            par[p.fs] = {i, p.sn};
            dfs(p.fs, c);
            forn(j, 0, B) {
                if (p.sn & (1ll << j)) {
                    cnt[j][0][i] += cnt[j][1][p.fs];
                    cnt[j][1][i] += cnt[j][0][p.fs];
                } else {
                    cnt[j][0][i] += cnt[j][0][p.fs];
                    cnt[j][1][i] += cnt[j][1][p.fs];
                }
            }
        }
}

vector<int> used;
void dfs2(int i) {
    used[i] = 1;
    for (auto p : e[i])
        if (!used[p.fs]) {
            path[p.fs] = path[i] ^ p.sn;
            dfs2(p.fs);
        }
}

bool notInTree(int u, int v) {
    return (par[u].fs != v && par[v].fs != u);
}

int Comp = 0;

vector<vector<ll>> basis;

ll ans = 0;

vector<int> root;
vector<ll> pow2;

void solve(int c) {
    int ix = 0;
    int sz = basis[c].size();
    char good[B];
    forn(i, 0, B) good[i] = 0;
    forn(i, 0, B) {
        forn(j, ix, sz)
            if (basis[c][j] & (1ll << i)) {
                if (j != ix) swap(basis[c][j], basis[c][ix]);
                ++ix;
                forn(k, ix, sz)
                    if (basis[c][k] & (1ll << i))
                        basis[c][k] ^= basis[c][ix - 1];
                break;
            }
    }
    forn(i, 0, B)
        forn(j, 0, sz)
            if (basis[c][j] & (1ll << i))
                good[i] = 1;
    forn(i, 0, B) {
        if (good[i]) {
            int v = root[c];
            ll sz = cnt[i][0][v] + cnt[i][1][v];
            ll add = sz * (sz - 1) / 2 % MOD * pow2[ix - 1 + i] % MOD;
            ans += add;
            if (ans >= MOD) ans -= MOD;
            //cerr << i << ' ' << add << '\n';
        } else {
            int v = root[c];
            ll odds = 1ll * cnt[i][0][v] * cnt[i][1][v];
            ans = (ans + pow2[ix + i] * odds) % MOD;
            //cerr << "!!!:" << i << ' ' << pow2[ix + i] * odds << '\n';
        }
    }
} 

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    e.resize(n);
    path.resize(n);
    used.resize(n);
    forn(i, 0, m) {
        int u, v;
        ll c;
        scanf("%d %d %lld", &u, &v, &c);
        --u, --v;
        e[u].eb(v, c);
        e[v].eb(u, c);
    }
    comp.resize(n);
    par.resize(n);
    forn(i, 0, B) forn(j, 0, 2) cnt[i][j].resize(n);
    forn(i, 0, n)
        if (!comp[i]) {
            par[i] = {-1, -1};
            dfs(i, ++Comp);
        }
    forn(i, 0, n) if (!used[i]) dfs2(i);
    basis.resize(Comp + 1);
    forn(u, 0, n)
        for (auto q : e[u]) {
            int v = q.fs;
            if (u < v && notInTree(u, v)) {
                basis[comp[u]].eb(q.sn ^ path[u] ^ path[v]);
                //cerr << u << ' ' << v << '\n';
        
            }
        }
    /*fore(i, 1, Comp) {
        cout << '\n';
        cout << i << '\n';
        for (int x : basis[i]) cout << x << ' ';
        cout << '\n';
    }*/
    root.resize(Comp + 1);
    forn(i, 0, n) if (par[i].fs == -1)
        root[comp[i]] = i;
    pow2.resize(2 * B + 10);
    pow2[0] = 1;
    forn(i, 1, 2 * B + 10)
        pow2[i] = 2 * pow2[i - 1] % MOD;

    fore(i, 1, Comp) solve(i);
    printf("%lld\n", ans);
}