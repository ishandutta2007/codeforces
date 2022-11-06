#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
bool query(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    if (x1 < 1 || x1 > n) exit(1);
    if (y1 < 1 || y1 > n) exit(1);
    if (x2 < 1 || x2 > n) exit(1);
    if (y2 < 1 || y2 > n) exit(1);
    if (x1 > x2 || y1 > y2) exit(1);
    if (x1 + y1 + 2 > x2 + y2) exit(1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1) exit(1);
    return x;
}

int G[51][51];

int solveS(int n) {
    vector<pii> v;
    for (int s = 2; s <= n + n; ++s) {
        v.emplace_back(s / 2, (s + 1) / 2);
    }
    int st = -1, ed = -1;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 3; j < v.size(); j += 2) {
            bool pos = 1;
            for (int k = i; k <= j; ++k) {
                pii a = v[k];
                pii b = v[i + j - k];
                if (G[a.fs][a.se] != G[b.fs][b.se]) {
                    pos = 0;
                    break;
                }
            }
            if (pos) {
                st = i, ed = j;
                break;
            }
            pos = 1;
            for (int k = i; k <= j; ++k) {
                pii a = v[k];
                pii b = v[i + j - k];
                if (G[a.fs][a.se] == G[b.fs][b.se]) {
                    pos = 0;
                    break;
                }
            }
            if (pos) {
                st = i, ed = j;
                break;
            }
        }
        if (st != -1) break;
    }
    if (st == -1) exit(1);
    pii a = v[st], b = v[ed];
    int ret = !query(a.fs, a.se, b.fs, b.se);
    return ret ^ G[a.fs][a.se] ^ G[b.fs][b.se];
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    DEBUG("Hello World!\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            G[i][j] = -1;
        }
    }
    G[1][1] = 1;
    G[1][2] = 0;
    G[n][n] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (G[i][j] != -1) continue;
            if (i == 2 && j == 1) continue;
            if (i > 1 && j > 1) {
                int ret = !query(i - 1, j - 1, i, j);
                G[i][j] = G[i - 1][j - 1] ^ ret;
            }
            else if (j > 2) {
                int ret = !query(i, j - 2, i, j);
                G[i][j] = G[i][j - 2] ^ ret;
            }
            else if (i > 2) {
                int ret = !query(i - 2, j, i, j);
                G[i][j] = G[i - 2][j] ^ ret;
            }
            else {
                DEBUG("???");
                exit(1);
            }
        }
        if (i == 2) {
            int ret = !query(2, 1, 2, 3);
            G[2][1] = G[2][3] ^ ret;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            DEBUG("%d", G[i][j]);
        }
        DEBUG("\n");
    }
    int sx = -1, sy = -1, ex = -1, ey = -1;
    bool pos = 0;
    for (int s = 2; s <= n + n; ++s) {
        for (int i1 = 1; i1 < n; ++i1) {
            int j1 = s - i1;
            int i2 = i1 + 1;
            int j2 = s - i2;
            if (j1 < 1 || j1 > n) continue;
            if (j2 < 1 || j2 > n) continue;
            if (G[i1][j1] == G[i2][j2]) continue;
            if (s > n + 1) {
                ex = i2;
                ey = j1;
            }
            else {
                sx = i1;
                sy = j2;
            }
            pos = 1;
            break;
        }
        if (pos) break;
    }
    DEBUG("%d %d %d %d\n", sx, sy, ex, ey);
    int ch = -1;
    if (!pos) {
        ch = solveS(n);
        if (ch != 0 && ch != 1) exit(1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ch != -1) break;
            if (sx == -1) {
                if ((ex + ey) - (i + j) != 3) continue;
                if (ex <= i) continue;
                if (ey <= j) continue;
                int ret = !query(i, j, ex, ey);
                ch = G[i][j] ^ G[ex][ey] ^ ret;
            }
            else {
                if ((i + j) - (sx + sy) != 3) continue;
                if (i <= sx) continue;
                if (j <= sy) continue;
                int ret = !query(sx, sy, i, j);
                ch = G[i][j] ^ G[sx][sy] ^ ret;
            }
        }
    }
    if (ch == -1) exit(1);
    printf("!\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i + j & 1) G[i][j] ^= ch;
            printf("%d", G[i][j]);
            if (G[i][j] != 0 && G[i][j] != 1) exit(1);
        }
        printf("\n");
    }
    fflush(stdout);
    return 0;
}