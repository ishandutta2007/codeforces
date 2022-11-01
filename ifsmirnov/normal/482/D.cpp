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
const int maxn = 100500;
const int mod = 1000000007;
int add(int x, int y) { return (x+y)%mod; }
void madd(int &x, int y) { x = add(x, y); }
int mul(int x, int y) { return (i64)x*y%mod; }

int n;
int d[maxn][2];
vi e[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int p;
        scanf("%d", &p);
        e[p-1].pb(i+1);
    }
    forn(i, n) sort(all(e[i]));
}

int g[maxn][2];

void dfs(int v) {
    int dg = e[v].size();
    forn(i, dg) dfs(e[v][i]);

    // count sim
    forn(TG, 2) {
        forn(i, dg+1) forn(j, 2) g[i][j] = 0;
        g[0][0] = 1;

        forn(i, dg) {
            int to = e[v][i];
            forn(r, 2) {
                madd(g[i+1][r], g[i][r]);
                madd(g[i+1][r^TG], mul(g[i][r], d[to][TG]));
            }
        }
        d[v][!TG] = g[dg][TG];
    }

    // non-sim
    forn(i, dg+1) forn(j, 2) g[i][j] = 0;
    g[0][0] = 1;

    forn(i, dg) {
        int to = e[v][i];
        forn(r, 2) {
            madd(g[i+1][r], g[i][r]);
            forn(t, 2) {
                madd(g[i+1][r^t], mul(g[i][r], d[to][t]));
            }
        }
    }
//     cout << "v = " << v << endl;
//     cout << "sim: " << d[v][0] << " " << d[v][1] << endl;
//     cout << "total: " << g[dg][1] << " " << g[dg][0] << endl;
    forn(i, 2) {
        d[v][i] = ((i64)g[dg][!i] * 2 - d[v][i] + mod) % mod;
    }
//     cout << "all: " << d[v][0] << " " << d[v][1] << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    dfs(0);
    printf("%d\n", add(d[0][0], d[0][1]));

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}