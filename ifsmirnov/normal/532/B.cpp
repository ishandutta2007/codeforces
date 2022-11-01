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
const i64 inf = 1e18+100500;

const int maxn = 200500;

int n;
vi e[maxn];
int a[maxn];

i64 d[maxn][2];
i64 f[maxn][2];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        int p;
        scanf("%d%d", &p, &a[i]);
        if (i) {
            --p;
            e[p].pb(i);
        }
    }
}

void relax(i64& x, i64 y) { x = max(x, y); }

void dfs(int v) {
    int k = e[v].size();

    forn(i, k) {
        int to = e[v][i];
        dfs(to);
    }

    forn(i, k+1) f[i][0] = f[i][1] = -inf;
    f[0][0] = 0;

    forn(i, k) {
        int to = e[v][i];
        forn(c, 2) if (f[i][c] != -inf) forn(t, 2) if (d[to][t] != -inf) {
            relax(f[i+1][c^t], f[i][c] + d[to][t]);
        }
    }

    d[v][0] = f[k][0];
    d[v][1] = max(f[k][0] + a[v], f[k][1]);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    dfs(0);
    cout << max(d[0][0], d[0][1]) << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}