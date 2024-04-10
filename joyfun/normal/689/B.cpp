#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;
int n, a[N];
int dp[N][2], vis[N][2];
queue<pair<int,int> > Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = 0;
    Q.push(make_pair(1, 0));
    while (!Q.empty()) {
        pair<int, int> u = Q.front(); Q.pop();
        vis[u.first][u.second] = 0;
        if (dp[a[u.first]][1] > dp[u.first][u.second] + 1) {
            dp[a[u.first]][1] = dp[u.first][u.second] + 1;
            if (!vis[a[u.first]][1]) {
                vis[a[u.first]][1] = 1;
                Q.push(make_pair(a[u.first], 1));
            }
        }
        for (int i = -1; i <= 1; i++) {
            if (i == 0) continue;
            int v = u.first + i;
            if (v <= 0 || v > n)continue;
            if (dp[v][0] > dp[u.first][u.second] + 1) {
                dp[v][0] = dp[u.first][u.second] + 1;
                if (!vis[v][0]) {
                    vis[v][0] = 1;
                    Q.push(make_pair(v, 0));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", min(dp[i][0], dp[i][1]));
    }
    printf("\n");
    return 0;
}