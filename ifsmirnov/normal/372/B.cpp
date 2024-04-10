#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 45;

typedef int ar[maxn][maxn];
int n, m, q;
ar s;
int get(ar a, int x1, int y1, int x2, int y2) {
    int res = a[x2][y2];
    if (y1) res -= a[x2][y1-1];
    if (x1) res -= a[x1-1][y2];
    if (x1&&y1) res += a[x1-1][y1-1];
    return res;
}
int d[maxn][maxn][maxn][maxn], b[maxn][maxn][maxn][maxn][4];

#define P [x1][y1][x2][y2][t]
int go(int x1, int y1, int x2, int y2, int t) {
    int &res = b P;
    if (res == -1) {
        res = 0;
//         res = d[x1][y1][x2][y2];
        if (t) res += go(x1, y1, x2, y2, t-1);
        if (t == 0) {
//             cout << "pure add " << x1 << " " << y1
//                     << " " << x2 << " " << y2 << " " <<
//                         d[x1][y1][x2][y2] << endl;
            res = d[x1][y1][x2][y2];
            if (x2 != x1) res += go(x1, y1, x2-1, y2, t);
        } else if (t == 1) {
            if (y2 != y1) res += go(x1, y1, x2, y2-1, t);
        } else if (t == 2) {
            if (x1 != x2) res += go(x1+1, y1, x2, y2, t);
        } else if (t == 3) {
            if (y1 != y2) res += go(x1, y1+1, x2, y2, t);
        }
    }
    return res;
}

char buf[maxn];
void scan() {
    scanf("%d%d%d", &n, &m, &q);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, m) if (buf[j] == '1') ++s[i][j];
    }
}

void solve() {
    forn(i, n) {
        forn(j, m) {
            if (i) s[i][j] += s[i-1][j];
            if (j) s[i][j] += s[i][j-1];
            if (i&&j) s[i][j] -= s[i-1][j-1];
        }
    }

    int cnt = 0;
    forn(x1, n) forn(y1, m) fore(x2, x1, n-1) fore(y2, y1, m-1) {
        forn(t, 4) b[x1][y1][x2][y2][t] = -1;
        if (!get(s, x1, y1, x2, y2)) {
            ++d[x1][y1][x2][y2];
        }
    }
    forn(III, q) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1;--y1;--x2;--y2;
        printf("%d\n", go(x1, y1, x2, y2, 3));
    }
}

int main()
{
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}