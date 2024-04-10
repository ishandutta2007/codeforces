#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

const int maxn = 105;

int n, m, k;
char a[maxn][maxn][maxn];
char buf[maxn];

#define ok(x, y, z) ((x)>=0&&(x)<n&&(y)>=0&&(y)<m&&(z)>=00&&(z)<k)

mt19937 rr;

void scan() {
//     n = 100;
//     m = 100;
//     k = 100;
//     forn(i, n) forn(j, m) forn(t, k) {
//         a[i][j][t] = rr() % 100 >= 1;
//     }
//     return;
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) forn(j, m) {
        scanf("%s", buf);
        forn(t, k) {
            a[i][j][t] = buf[t] == '1';
        }
    }
}

char d[3][3][3];
char b[3][3][3];

int c1;

void dfs(int x, int y, int z) {
    if (x != 1 || y != 1 || z != 1) ++c1;
    b[x][y][z] = true;
    if (x != 2 && d[x+1][y][z] && !b[x+1][y][z]) dfs(x+1, y, z);
    if (y != 2 && d[x][y+1][z] && !b[x][y+1][z]) dfs(x, y+1, z);
    if (z != 2 && d[x][y][z+1] && !b[x][y][z+1]) dfs(x, y, z+1);
}

int get() {
//     cout << "g1" << endl;
    int cnt = 0;
    forn(i, 3) forn(j, 3) forn(k, 3) if (i != 1 || j != 1 || k != 1) {
        if (!d[i][j][k]) continue;
        memset(b, 0, sizeof b);
        c1 = 0;
        dfs(i, j, k);
        cnt += c1;
    }
//     cerr << "cnt = " << cnt << endl;
    return cnt;
}


bool needed(int sx, int sy, int sz) {
    if (!a[sx][sy][sz]) {
        return false;
    }

    memset(d, 0, sizeof d);
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dz = -1; dz <= 1; ++dz) {
                if (ok(sx+dx, sy+dy, sz+dz)) {
                    d[dx+1][dy+1][dz+1] = a[sx+dx][sy+dy][sz+dz];
                }
            }
        }
    }

    int old = get();
    d[1][1][1] = 0;
    int nxt = get();
    assert(nxt <= old);
    return nxt < old;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scan();


    int cnt = 0;
    forn(i, n) forn(j, m) forn(t, k) {
        cnt += needed(i, j, t);
    }

    cout << cnt << endl;

    cerr << "time: "  << clock()/1000 << endl;
}