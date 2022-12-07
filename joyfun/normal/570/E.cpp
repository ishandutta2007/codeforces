#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 505;
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
const int MOD = 1000000007;

int n, m;
char str[N][N];
int dp[2][N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    int now = 0, pre = 1;
    memset(dp[0], 0, sizeof(dp[0]));
    if (str[1][1] == str[n][m]) dp[0][1][n] = 1;
    for (int i = 0; i < (n + m - 2) / 2; i++) {
        swap(now, pre);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int x1 = 1; x1 <= n; x1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                if (!dp[pre][x1][x2]) continue;
                int y1 = i + 2 - x1;
                int y2 = (m - (i - (n - x2)));
                if (y2 < y1) continue;
                for (int j = 0; j < 2; j++) {
                    int xx1 = x1 + dir[j][0];
                    int yy1 = y1 + dir[j][1];
                    if (xx1 <= 0 || xx1 > n || yy1 <= 0 || yy1 > m) continue;
                    for (int k = 2; k < 4; k++) {
                        int xx2 = x2 + dir[k][0];
                        int yy2 = y2 + dir[k][1];
                        if (xx2 <= 0 || xx2 > n || yy2 <= 0 || yy2 > m) continue;
                        if (str[xx1][yy1] != str[xx2][yy2]) continue;
                        if (xx2 < xx1 || yy2 < yy1) continue;
                        dp[now][xx1][xx2] += dp[pre][x1][x2];
                        if (dp[now][xx1][xx2] >= MOD) dp[now][xx1][xx2] -= MOD;
                        //printf("%d %d %d %d\n", i, xx1, xx2, dp[now][xx1][xx2]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x1 = 1; x1 <= n; x1++) {
        for (int x2 = 1; x2 <= n; x2++) {
            ans += dp[now][x1][x2];
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}