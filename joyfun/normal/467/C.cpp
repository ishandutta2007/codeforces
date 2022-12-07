#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5005;
const long long INF = 0x3f3f3f3f3f3f3f;

long long dp[N][N];

int n, m, k;
long long num[N], pre[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &num[i]);
        pre[i] = pre[i - 1] + num[i];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j && i >= m)
                dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + pre[i] - pre[i - m]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}