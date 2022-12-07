#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[N];
vector<int> g[N];
long long dp[N][3][2], tmp[3][2];

void dfs(int u, int p) {
    int flag = 1;
    long long Max = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        flag = 0;
        dfs(v, u);
        memcpy(tmp, dp[u], sizeof(tmp));
        for (int x = 0; x < 3; x++) {
            for (int y = x; y >= 0; y--) {
                if (x - y - 1 >= 0) dp[u][x][0] = max(dp[u][x][0], dp[v][y][1] + tmp[x - y - 1][1]);
                dp[u][x][0] = max(dp[u][x][0], dp[v][y][0] + tmp[x - y][0]);
                if (x < 2) {
                    dp[u][x][1] = max(dp[u][x][1], tmp[x - y][1] + dp[v][y][0]);
                    if (x == 1 && y == 0) dp[u][x][1] = max(dp[u][x][1], dp[v][y][1] + a[u] + Max);
                    else dp[u][x][1] = max(dp[u][x][1], dp[v][y][1] + a[u]);
                }
            }
        }
        Max = max(Max, dp[v][1][0]);
    }
    if (flag) dp[u][0][1] = dp[u][1][0] = a[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    long long ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            ans = max(ans, dp[1][i][j]);
    printf("%lld\n", ans);
    return 0;
}