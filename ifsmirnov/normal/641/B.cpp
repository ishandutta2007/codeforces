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

const int maxn = 105;
const int maxq = 10101;

int n, m;
int a[maxn][maxn];
int q;
int t[maxq], r[maxq], c[maxq], x[maxq];


int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &q);
    forn(i, q) {
        scanf("%d%d", &t[i], &r[i]), --r[i];

        if (t[i] == 3) scanf("%d%d", &c[i], &x[i]), --c[i];
    }

    ford(i, q) {
        if (t[i] == 3) {
            a[r[i]][c[i]] = x[i];
        } else if (t[i] == 1) {
            int x = r[i];
            int t = a[x][m-1];
            ford(y, m) if (y) a[x][y] = a[x][y-1];
            a[x][0] = t;
        } else {
            int y = r[i];
            int t = a[n-1][y];
            ford(x, n) if (x) a[x][y] = a[x-1][y];
            a[0][y] = t;
        }
    }

    forn(i, n) {
        forn(j, m) printf("%d ", a[i][j]);
        printf("\n");
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}