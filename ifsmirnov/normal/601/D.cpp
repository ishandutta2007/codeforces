#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

const int maxn = 300500;

const int m1 = 1000000009;
const int m2 = 1000000007;
const int p1 = 10099;
const int p2 = 424243;

struct Hash {
    int h1, h2;
    bool operator<(const Hash& o) const {
        return h1 < o.h1 || (h1 == o.h1 && h2 < o.h2);
    }
    Hash() : h1(0), h2(0) {}

    void addc(int c) {
        h1 = ((i64)h1 * p1 + c) % m1;
        h2 = ((i64)h2 * p2 + c) % m2;
    }
};


int n;
vi e[maxn];
char c[maxn];
int W[maxn];
Hash h[maxn];
int hh[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &W[i]);
    scanf("%s", c);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &v, &u);
        --u, --v;
        e[v].pb(u);
        e[u].pb(v);
    }
}

map<Hash, int> shr;
int get(Hash h) {
    if (shr.count(h)) return shr[h];
    int s = shr.size();
    return shr[h] = s;
}

vi en[maxn];

int p[maxn][20];
int lca(int u, int v) {
    if (hh[u] < hh[v]) swap(u, v);
    forn(k, 20) if ((hh[u] - hh[v]) & (1<<k)) u = p[u][k];
    if (u == v) return v;
    ford(k, 20) {
        if (p[u][k] != p[v][k]) {
            u = p[u][k];
            v = p[v][k];
        }
    }
    return p[v][0];
}

void dfs(int v, int anc) {
    en[get(h[v])].pb(v);
    if (anc != -1) p[v][0] = anc;
    for (auto to: e[v]) if (to != anc) {
        hh[to] = hh[v] + 1;
        h[to] = h[v];
        h[to].addc(c[to]);
        dfs(to, v);
    }
}


int s[maxn];

int best = -1, bestc = 0;

int cs[maxn];

void dfs2(int v, int anc) {
    cs[v] = s[v];
    for (auto to: e[v]) if (to != anc) {
        dfs2(to, v);
        cs[v] += cs[to];
    }
    int cs = ::cs[v];
//     cout << v+1 << ": " << cs << endl;
    if (cs + W[v] > best) {
        best = cs + W[v];
        bestc = 0;
    }
    if (cs + W[v] == best) {
        ++bestc;
    }
}

void solve() {
    h[0].addc(c[0]);
    dfs(0, -1);
    forn(k, 20) if (k) forn(i, n) p[i][k] = p[p[i][k-1]][k-1];
//     cout << "shr.size() = " << shr.size() << endl;
    forn(i, shr.size()) {
//         cout << "add ";
        forn(j, en[i].size()) {
            ++s[en[i][j]];
            if (j) {
                --s[lca(en[i][j], en[i][j-1])];
//                 cout << "-" << lca(en[i][j], en[i][j-1])+1 << " ";
            }
//             cout << en[i][j]+1 << " ";
        }
//         cout << endl;
    }

    dfs2(0, -1);
    cout << best << " " << bestc << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}