#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <cstdlib>
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
const int maxn = 100500;

int n, m;
vi e[maxn];
int par[maxn];
int s[maxn];
int b[maxn];

void dfs1(int v) {
    b[v] = 1;
    s[v] = par[v];
    forn(i, e[v].size()) {
        int to = e[v][i];
        if (b[to]) {
            swap(e[v][i], e[v].back());
            e[v].pop_back();
            --i;
            continue;
        }
        dfs1(to);
        s[v] |= s[to];
    }
}

int ans[maxn * 10];
int sz = 0;

void dfs(int v, int anc = -1) {
    par[v] ^= 1;
    ans[sz++] = v;
    forn(i, e[v].size()) {
        int to = e[v][i];
        if (!s[to]) continue;
        dfs(to, v);
        ans[sz++] = v;
        par[v] ^= 1;
    }
    if (par[v]) {
        if (anc == -1) {
            assert(!e[v].empty());
            ans[sz++] = e[v][0];
            ans[sz++] = v;
            ans[sz++] = e[v][0];
        } else {
            ans[sz++] = anc;
            ans[sz++] = v;
            par[anc] ^= 1;
        }
    }
}

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
    forn(i, n) scanf("%d", &par[i]);
}

void solve() {
    if (count(par, par+n, 1) == 0) {
        printf("0\n");
        return;
    } else if (count(par, par+n, 1) == 1) {
        forn(i, n) if (par[i] == 1) {
            printf("1\n");
            printf("%d\n", i+1);
            return;
        }
    }
    int sv = max_element(par, par+n) - par;
    dfs1(sv);
    forn(i, n) if (par[i] && !s[i]) {
        printf("-1\n");
        return;
    }
    dfs(sv);
    printf("%d\n", sz);
    forn(i, sz) printf("%d ", ans[i] + 1);
    printf("\n");
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