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

int n, m;
const int maxn = 510;
int e[maxn][maxn];
char s[maxn];
int b[maxn];
int g[maxn];
int deg[maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u][--v] = 1;
        e[v][u] = 1;
        ++deg[v];
        ++deg[u];
    }
}

void dfs(int v, int cc) {
    b[v] = cc;
    s[v] = 'a'+cc*2-1;
    forn(to, n) if (e[v][to] && !g[to]) {
        if (!b[to]) {
            dfs(to, 3-cc);
        } else if (b[to] == b[v]) {
            cout << "No" << endl;
            exit(0);
        }
    }
}

void solve() {
    forn(i, n) {
        if (deg[i] + 1 == n) {
            s[i] = 'b';
            g[i] = 0;
        } else {
            g[i] = 1;
        }
//         forn(j, n) e[i][j] = !e[i][j];
//         e[i][i] = 0;
    }
//     forn(i, n) cout << (s[i]?s[i]:'.'); cout << endl;

    forn(i, n) if (g[i] && !s[i]) {
        s[i] = 'a';
        forn(j, n) if (g[j] && e[i][j]) s[j] = 'a';
        break;
    }
//     forn(i, n) cout << (s[i]?s[i]:'.'); cout << endl;
    forn(i, n) if (!s[i]) s[i] = 'c';
//     forn(i, n) cout << (s[i]?s[i]:'.'); cout << endl;
    forn(i, n) forn(j, i) {
        bool need_edge = abs(s[i] - s[j]) <= 1;
        if (need_edge != e[i][j]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl << s << endl;
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