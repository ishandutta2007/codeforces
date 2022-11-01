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
const int maxn = 1050;

int n, m;
int a[maxn][maxn];
int s[maxn][maxn];
char buf[maxn];

bool tr;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, m) a[i][j] = buf[j] == 'X';
    }
}

void prepare() {
    forn(i, n+10) forn(j, m+10) {
        s[i][j] = a[i][j];
        if (i) s[i][j] += s[i-1][j];
        if (j) s[i][j] += s[i][j-1];
        if (i&&j) s[i][j] -= s[i-1][j-1];
    }
}

int gets(int x1, int y1, int x2, int y2) {
    int res = s[x2][y2];
    if (x1) res -= s[x1-1][y2];
    if (y1) res -= s[x2][y1-1];
    if (x1&&y1) res += s[x1-1][y1-1];
    return res;
}
int getsq(int x, int y, int w, int h) {
    return gets(x, y, x+w-1, y+h-1);
}

void transpose() {
    forn(i, max(n, m)+10) forn(j, i) {
        swap(a[i][j], a[j][i]);
        swap(s[i][j], s[j][i]);
    }
    swap(n, m);
    tr ^= 1;
}

int check(int x, int y, int w, int h) {
//     cout << "check " << x << " " << y << "  " << w << " " << h << endl;
    int S = w*h;
    if (getsq(x, y, w, h) != S) {
        return inf;
    }
    int ts = s[n][m] - S;
    while (1) {
        bool gx = getsq(x+1, y, w, h) == S;
        bool gy = getsq(x, y+1, w, h) == S;
        if (gx && gy) return inf;
        else if (gx) ts -= h, ++x;
        else if (gy) ts -= w, ++y;
        else break;
    }
//     cout << "ts = " << ts << endl;
    if (ts == 0) return S;
    else return inf;
}

void solve() {
    int mn = inf;
    forn(III, 2) {
    int mnx, mny;
    forn(i, n) forn(j, m) {
        if (a[i][j]) {
            mnx = i;
            mny = j;
            goto l1;
        }
    }
    assert(false);
    l1:;
//     forn(i, n) {
//         forn(j, m) cout << a[i][j];
//         cout << endl;
//     }
//     forn(i, n) {
//         forn(j, m) cout << s[i][j] << " ";
//         cout << endl;
//     }
    int ay = mny;
    while (a[mnx][ay]) ++ay;

    int bx = mnx;
    while (a[bx][mny]) ++bx;
    int by = mny;
    while (!a[bx][by] && by < ay) ++by;

//     cout << "mnx, mny: " << mnx << " " <<mny << endl;
//     cout << "ay: " << ay << endl;
//     cout << "bx, by: " << bx << " " << by << endl;
//     cout << endl;
    mn = min(mn, check(mnx, mny, bx - mnx, max(1, ay - by)));
    transpose();
    }

    if (mn == inf) {
        cout << -1 << endl;
    } else {
        cout << mn << endl;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    prepare();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}