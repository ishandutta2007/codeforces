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
inline int add(int x, int y) { return (x+y)%mod; }
inline int mul(int x, int y) { return (i64)x*y%mod; }
const int maxn = 100500;

int mpow(int x, int k) {
    if (k == 1) return x;
    if (k%2 == 0) return mpow(mul(x,x), k/2);
    else return mul(x, mpow(mul(x,x), k/2));
}
int rev(int x) { return mpow(x, mod-2); }

int n;
vi e[maxn];
int c[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int x;
        scanf("%d", &x);
        e[x].pb(i+1);
    }
    forn(i, n) scanf("%d", &c[i]);
}

int d[maxn][2];

void dfs(int v) {
    if (e[v].empty()) {
        d[v][0] = 1;
        d[v][c[v]] = 1;
//         cout << v << ": " << d[v][0] << " " << d[v][1] << endl;
        return;
    }
    vi r(e[v].size()), l(e[v].size());
    forn(i, e[v].size()) {
        int to = e[v][i];
        dfs(to);
        r[i] = d[to][0];
        if (i) r[i] = mul(r[i], r[i-1]);
    }
    ford(i, e[v].size()) {
        int to = e[v][i];
        l[i] = d[to][0];
        if (i+1 != (int)e[v].size()) l[i] = mul(l[i], l[i+1]);
    }
//     cout << "r.back() = " << r.back() << endl;
//     if (v == 4) {
//         cerr << "rere" << endl;
//     }
    if (!c[v]) {
        forn(i, e[v].size()) {
            int x = 1;
            if (i) x = mul(x, r[i-1]);
            if (i+1 != (int)e[v].size()) x = mul(x, l[i+1]);
            x = mul(x, d[e[v][i]][1]);
            d[v][1] = add(d[v][1], x);
        }
        d[v][0] = add(d[v][1], r.back());
    } else {
        d[v][0] = r.back();
        d[v][1] = r.back();
    }
//     cout << v << ": " << d[v][0] << " " << d[v][1] << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    dfs(0);
    cout << d[0][1] << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}