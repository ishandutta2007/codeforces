#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstring>
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

const int maxn = 110;

int n;
int c[maxn][maxn], d[maxn], pos[maxn], q[maxn];


int m, k;
int a[maxn];
int x[maxn], y[maxn];
int idx[maxn];
int S, T;

set<int> prs;

bool bfs() {
    forn(i, n) d[i] = maxn;
    d[S] = 0;
    int lq = 0, rq = 1;
    q[0] = S;
    while (lq != rq) {
        int v = q[lq++];
        forn(i, n) if (d[i] == maxn && c[v][i] > 0) {
            d[i] = d[v] + 1;
            q[rq++] = i;
        }
    }
    return d[T] != maxn;
}

int dfs(int v, int curf) {
    if (v == T || !curf) return curf;
    for (int &i = pos[v]; i < n; ++i) {
        if (c[v][i] > 0 && d[i] == d[v] + 1) {
            if (int ret = dfs(i, min(curf, c[v][i]))) {
                c[v][i] -= ret;
                c[i][v] += ret;
                return ret;
            }
        }
    }
    return 0;
}

int dinic() {
    int f = 0;
    while (bfs()) {
        forn(i, n) pos[i] = 0;
        while (int ff = dfs(S, 10000000)) f += ff;
    }
    return f;
}

void scan() {
    scanf("%d%d", &m, &k);
    forn(i, m) scanf("%d", &a[i]);
    forn(i, k) {
        scanf("%d%d", &x[i], &y[i]), --x[i], --y[i];
        if (x[i]%2) swap(x[i], y[i]);
    }
}

int solve(int pr) {
//     cout << "pr = " << pr << endl;
    memset(c, 0, sizeof c);
    S = 0, T = 1;
    n = 2;
    forn(i, m) {
        if (a[i] % pr == 0) {
            int x = a[i];
            idx[i] = n;
            int c = 0;
            while (x % pr == 0) x /= pr, ++c;
            if (i%2 == 0) ::c[S][n] = c;
            else ::c[n][T] = c;
            ++n;
        } else {
            idx[i] = 0;
        }
    }
    forn(i, k) {
        if (idx[x[i]] && idx[y[i]]) c[idx[x[i]]][idx[y[i]]] = 100000;
    }
    return dinic();

//     forn(i, n) {
//         forn(j, n) cout << c[i][j] << " ";
//         cout << endl;
//     }
//     cout << endl;
}

void solve() {
    forn(i, m) {
        int x = a[i];
        for (int j = 2; j*j <= x; ++j) {
            if (x%j == 0) {
                prs.insert(j);
                while (x%j == 0) x /= j;
            }
        }
        if (x != 1) prs.insert(x);
    }

    int res = 0;
    for (auto pr: prs) {
        res += solve(pr);
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