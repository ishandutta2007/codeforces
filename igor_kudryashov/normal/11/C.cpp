#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;

const int dx [] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy [] = {-1, 0, 1, -1, 1, -1, 0, 1};

int tests;
int n, m;
char f[255][255];
bool used[255][255];
bool used2[255][255];
int col[255][255];
int ITER;

inline bool correct (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfsVER (int ax, int ay) {
    ITER++;
    vector <pt> q;
    int yk = 0;
    q.push_back(mp(ax, ay));
    col[ax][ay] = ITER;
    int minx = ax, maxx = ax, miny = ay, maxy = ay;
    while (yk < (int) q.size()) {
        int x = q[yk].first, y = q[yk].second;
        yk++;
        forn(i, 8) {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty) || col[tx][ty] == ITER || f[tx][ty] == '0') continue;
            col[tx][ty] = ITER;
            minx = min(tx, minx);
            maxx = max(tx, maxx);
            miny = min(ty, miny);
            maxy = max(ty, maxy);
            q.push_back(mp(tx, ty));
        }
    }
    if ((int) q.size() < 4) return 0;
    if (maxx - minx < 1) return 0;
    if (maxy - miny < 1) return 0;
    if (maxx - minx != maxy - miny) return 0;
    for (int j = miny; j <= maxy; j++) {
        if (col[minx][j] != ITER) return 0;
        used2[minx][j] = true;
        if (col[maxx][j] != ITER) return 0;
        used2[maxx][j] = true;
    }
    for (int i = minx; i <= maxx; i++) {
        if (col[i][miny] != ITER) return 0;
        used2[i][miny] = true;
        if (col[i][maxy] != ITER) return 0;
        used2[i][maxy] = true;
    }
    forn(i, q.size()) {
        int x = q[i].first, y = q[i].second;
        if (!used2[x][y]) return 0;
    }
    return 1;
}

int bfsDia (int ax, int ay) {
    int OLD = ITER;
    ITER++;
    vector <pt> q;
    int yk = 0;
    q.push_back(mp(ax, ay));
    col[ax][ay] = ITER;
    int mind = ax + ay;
    int minx1 = ax, maxx1 = ax;
    while (yk < (int) q.size()) {
        int x = q[yk].first, y = q[yk].second;
        yk++;
        forn(i, 8) {
            int tx = x + dx[i], ty = y + dy[i];
            if (!correct(tx, ty) || col[tx][ty] == ITER || col[tx][ty] != OLD) continue;
            col[tx][ty] = ITER;
            if (tx + ty <= mind) {
                mind = tx + ty;
                minx1 = min(tx, minx1);
                maxx1 = max(tx, maxx1);
            }
            q.push_back(mp(tx, ty));
        }
    }
    if ((int) q.size() < 4) return 0;
    if (maxx1 - minx1 < 1) return 0;
    int k = maxx1 - minx1;
    int y = mind - minx1;
    for (int i = minx1; i < maxx1; i++) {
        int tx = i, ty = y - (minx1 - i);
        if (!correct(tx, ty)) return 0;
        if (col[tx][ty] != ITER) return 0;
        used[tx][ty] = true;
        ty = y + (minx1 - i);
        if (!correct(tx, ty)) return 0;
        if (col[tx][ty] != ITER) return 0;
        used[tx][ty] = true;
    }
    int x = minx1 + 2 * k;
    for (int i = x; i >= maxx1; i--) {
        int tx = i, ty = y - (x - i);
        if (!correct(tx, ty)) return 0;
        if (col[tx][ty] != ITER) return 0;
        used[tx][ty] = true;
        ty = y + (x - i);
        if (!correct(tx, ty)) return 0;
        if (col[tx][ty] != ITER) return 0;
        used[tx][ty] = true;
    }
    forn(i, q.size()) {
        int x = q[i].first, y = q[i].second;
        if (!used[x][y]) return 0;
    }
    return 1;
}

int get (int x, int y) {
    int res = 0;
    res += bfsVER(x, y);
    res += bfsDia(x, y);
    return res;
}

int solve () {
    ITER = 0;
    int res = 0;
    memset(col, 0, sizeof(col));
    memset(used, 0, sizeof(used));
    memset(used2, 0, sizeof(used2));
    forn(i, n)
        forn(j, m) {
            if (f[i][j] == '1' && col[i][j] == 0) res += get(i, j);
        }
    return res;
}

int main()
{
    cin >> tests;
    forn(kt, tests) {
        scanf("%d%d", &n, &m);
        forn(i, n) scanf("%s", &f[i]);
        printf("%d\n", solve());
    }
    return 0;
}