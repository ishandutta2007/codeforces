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

const int maxn = 450;
int n, m;
int e[maxn][maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        e[x][y] = e[y][x] =1 ;
    }
}
int d[maxn], q[maxn];

int bfs() {
    forn(i, n) d[i] = maxn;
    int lq = 0, rq = 1;
    q[0] = d[0] = 0;
    while (lq != rq) {
        int v = q[lq++];
        forn(i, n) if (e[v][i] && d[i] == maxn) {
            d[i] = d[v] + 1;
            q[rq++] = i;
        }
    }
    return d[n-1];
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    if (e[0][n-1]) {
        forn(i, n) forn(j, n) e[i][j] ^= 1;
    }
    int res = bfs();
    if (res == maxn) cout << -1;
    else cout << res;
    cout << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}