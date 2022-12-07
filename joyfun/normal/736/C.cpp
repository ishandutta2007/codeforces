#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int MOD = 1000000007;

void pp(int &x, int y){
    x += y;
    if (x >= MOD) x -= MOD;
}

int dp[N][25][25], tmp[25][25];
vector<int> g[N];

int n, k;

void dfs(int u, int p) {
    memset(dp[u], 0, sizeof(dp[u]));
    dp[u][0][k + 1] = 1;
    dp[u][k + 1][0] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        memset(tmp, 0, sizeof(tmp));
        for (int x = 0; x <= k + 1; x++) {
            for (int y = 0; y <= k + 1; y++) {
                if (dp[u][x][y] == 0)continue;
                for (int xx = 0; xx <= k + 1; xx++) {
                    for (int yy = 0; yy <= k + 1; yy++) {
                        if (dp[v][xx][yy] == 0)continue;
                        int d = min(x, xx + 1);
                        int yu = k - d;
                        int sb;
                        if (y == k + 1 && yy == k + 1) sb = k + 1;
                        else if (y == k + 1) {
                            sb = yy + 1;
                            if (sb == k + 1) continue;
                        }
                        else if (yy == k + 1) sb = y;
                        else {
                            sb = max(y, yy + 1);
                            if (sb == k + 1) continue;
                            //printf("sb\n");
                        }
                        //printf("%d %d %d %d %d %d\n", yu, sb, x, y, xx, yy);
                        if (sb == k +1 || yu >= sb)
                            pp(tmp[d][k + 1], 1LL * dp[u][x][y] * dp[v][xx][yy] % MOD);
                        else pp(tmp[d][sb], 1LL * dp[u][x][y] * dp[v][xx][yy] %MOD);
                    }
                }
            }
        }
        for (int x = 0; x <= k + 1; x++)
            for (int y = 0; y <= k + 1; y++)
                dp[u][x][y] = tmp[x][y];
    }
    /*
     for (int x = 0; x <= k + 1; x++)
            for (int y = 0; y <= k + 1; y++)
                printf("%d %d %d %d\n", u, x, y, dp[u][x][y]);
                */
}

int main() {
    scanf("%d%d", &n, &k);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 0; i <= k; i++)
        pp(ans, dp[1][i][k + 1]);
    printf("%d\n", ans);
    return 0;
}