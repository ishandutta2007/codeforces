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

const int maxn = 20;

int n, m, k;
int a[maxn];
int e[maxn][maxn];
i64 d[1<<18][maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, k) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        e[u-1][v-1] = d;
    }

    forn(i, n) d[1<<i][i] = a[i];
    i64 best = 0;
    forn(mask, 1<<n) forn(x, n) if (mask&(1<<x)) {
        forn(y, n) if (!(mask&(1<<y))) {
            int nmask = mask|(1<<y);
            d[nmask][y] = max(d[nmask][y], d[mask][x] + a[y] + e[x][y]);
        }
        if (__builtin_popcount(mask) == (size_t)m) {
            best = max(best, d[mask][x]);
        }
    }

    cout << best << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}