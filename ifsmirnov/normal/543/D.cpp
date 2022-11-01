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
const int maxn = 200500;
const int mod = 1000000007;
int add(int x, int y) { return (x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }

int n;
vi e[maxn];
int d[maxn], up[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int p;
        scanf("%d", &p);
        e[p-1].pb(i+1);
    }
}

void dfs1(int v) {
    d[v] = 1;
    for (auto to: e[v]) {
        dfs1(to);
        d[v] = mul(d[v], (d[to] + 2));
    }
    d[v] = add(d[v], mod-1);
}

void dfs2(int v) {
    vi p(e[v].size()), s(e[v].size());
    forn(i, e[v].size()) {
        p[i] = add(d[e[v][i]], 2);
        if (i) p[i] = mul(p[i], p[i-1]);
    }
    ford(i, e[v].size()) {
        s[i] = add(d[e[v][i]], 2);
        if (i + 1 != (int)e[v].size()) s[i] = mul(s[i], s[i+1]);
    }
    forn(i, e[v].size()) {
        int pp = i == 0 ? 1 : p[i-1];
        int ss = i+1 == (int)e[v].size() ? 1 : s[i+1];
        up[e[v][i]] = add(
                mul(up[v] + 2 - (v == 0), mul(pp, ss)),
                mod-1);
    }
    for (auto to: e[v]) {
        dfs2(to);
    }
}

int ans(int v) {
    int ans = 1;
    for (auto to: e[v]) {
        ans = mul(ans, d[to] + 2);
    }
    if (v) {
        ans = mul(ans, up[v] + 2);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    dfs1(0);
    dfs2(0);
//     forn(i, n) cout << d[i] << " "; cout << endl;
//     forn(i, n) cout << up[i] << " "; cout << endl;
    forn(v, n) {
        printf("%d ", ans(v));
    }
    printf("\n");


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}