#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
const int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
const char v[5] = {"^v><"};
const int N = 2005;
int n, m, max1, max2, num, dp[N][N];
char g[N][N];

void init() {
    num = max1 = max2 = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);
}

void Max(int M) {
    if (M > max1) {
        max2 = max1; max1 = M;
    }
    else if (M > max2) max2 = M;
}

int dfs(int x, int y, char c) {
    if (x < 0 || x >= n || y < 0 || y >= m || c != g[x][y]) return 0;
    num++;
    if (dp[x][y] != -1) return dp[x][y];
    int Max = 0;
    for (int i = 0; i < 4; i++) {
        int t = dfs(x + d[i][0], y + d[i][1], v[i]);
        Max = max(Max, t);
    }
    dp[x][y] = Max + 1;
    return Max + 1;
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                num++;
                for (int k = 0; k < 4; k++) {
                    Max(dfs(i + d[k][0], j + d[k][1], v[k]));
                }
            }
        }
    if (num < n * m) printf("-1\n");
    else printf("%d\n", (max1 == max2 ? max1 + max2 : max1 + max(max1 - 1, max2)));
}

int main() {
    init();
    solve();
    return 0;
}