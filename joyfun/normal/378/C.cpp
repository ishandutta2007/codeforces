#include <stdio.h>
#include <string.h>
#include <algorithm>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

const int N = 505;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char g[N][N];
int n, m, k, pn, sum, Max_v, Max, snum;
struct P {
    int x, y, v;
} p[N * N];

int cmp(P a, P b) {
    return a.v > b.v;
}

void init() {
    sum = 0; Max = 0; snum = 0;
    memset(p, 0, sizeof(p));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i ++)
        scanf("%s", g[i]);
}

void dfs1(int x, int y) {
    g[x][y] = 'X'; p[pn].v++;
    for (int i = 0; i < 4; i ++) {
        int xx = x + d[i][0];
        int yy = y + d[i][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == '.')
            dfs1(xx, yy);
    }
}

void dfs2(int x, int y) {
    if (snum == sum - k) {
        return;
    }
    g[x][y] = '.'; snum ++;
    for (int i = 0; i < 4; i ++) {
        int xx = x + d[i][0];
        int yy = y + d[i][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 'X')
            dfs2(xx, yy);
    }
}

void print() {
    for (int i = 0; i < n; i ++)
        printf("%s\n", g[i]);
}

void solve() {
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '.') {
                dfs1(i, j);
                sum += p[pn].v;
                if (Max < p[pn].v) {
                    Max_v = pn;
                    Max = p[pn].v;
                }
                p[pn].x = i; p[pn].y = j; pn++;
            }
        }
    dfs2(p[Max_v].x, p[Max_v].y);
    print();
}

int main() {
    init();
    solve();
    return 0;
}