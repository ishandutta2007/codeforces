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

const int maxn = 500;

int c[maxn][maxn];
int d[maxn], q[maxn], pos[maxn];
int n, m, S, T;
int e[maxn][maxn];

void scan() {
    scanf("%d%d", &n, &m);
    S = n*2; T = S+1;
    forn(i, n) {
        int t; scanf("%d", &t); c[S][i] = t;
    }
    forn(i, n) {
        int t; scanf("%d", &t); c[i+n][T] = t;
    }

    forn(i, n) e[i][i] = 1;

    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u,--v;
        e[v][u] = e[u][v] = 1;
    }

    forn(i, n) forn(j, n) if (e[i][j]) c[i][j+n] = 10000;

    n = n*2 + 2;
}

bool bfs() {
    forn(i, n) d[i] = maxn;
    d[S] = 0;
    q[0] = S;
    int lq = 0, rq = 1;
    while (lq != rq) {
        int v = q[lq++];
        forn(i, n) if (c[v][i] && d[i] == maxn) {
            d[i] = d[v] + 1, q[rq++] = i;
        }
    }

    return d[T] != maxn;
}

int dfs(int v, int curf) {
    if (v == T || !curf) return curf;
    for (int &i = pos[v]; i < n; ++i) {
        if (d[v] + 1 == d[i] && c[v][i]) {
            int ret = dfs(i, min(curf, c[v][i]));
            if (ret) {
                c[v][i] -= ret;
                c[i][v] += ret;
                return ret;
            }
        }
    }
    return 0;
}

int flow() {
    int f = 0;
    while (bfs()) {
        forn(i, n) pos[i] = 0;
        while (int ff = dfs(S, 1000000)) {
            f += ff;
        }
    }
    return f;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    int ss = 0, tt = 0;
    forn(i, n/2-1) ss += c[S][i], tt += c[i+n/2-1][T];
    if (ss != tt) {
        cout << "NO" << endl;
        return 0;
    }
    int f = flow();
    if (f == ss) {
        printf("YES\n");
        n = n/2 - 1;
        forn(i, n) {
            forn(j, n) {
                if (c[i][j+n] < 100) {
                    printf("0 ");
                } else {
                    printf("%d ", 10000 - c[i][j+n]);
                }
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}