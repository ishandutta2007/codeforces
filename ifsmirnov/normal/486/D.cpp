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
int add(int x, int y) { return (x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }
const int maxn = 100500;

int n, d;
vi e[maxn];
int w[maxn], b[maxn], w0;
int order[maxn];

void scan() {
    scanf("%d%d", &d, &n);
    forn(i, n) scanf("%d", &w[i]);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
}

int dfs(int v, int anc) {
    if (b[v] || !(w[v] - w0 <= d)) return 0;
    int res = 1;
    for (auto to : e[v]) if (to != anc) {
        res = mul(res, add(1, dfs(to, v)));
    }
    return res;
}

void solve() {
    forn(i, n) order[i] = i;
    sort(order, order+n, [](int i, int j) { return w[i] < w[j]; });
    int res = 0;
    forn(I, n) {
        int i = order[I];
        w0 = w[i];
        res = add(res, dfs(i, -1));
        b[i] = 1;
    }
    cout << res << endl;
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