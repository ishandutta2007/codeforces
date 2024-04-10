#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 600005;
const long long INF = 0x3f3f3f3f3f3f3f;

int n, k;
long long a[N];
long long dp[5055][5055];
long long sum[N];
int main() {
    scanf("%d%d", &n, &k);
    int cnt = n / k;
    int up = n - cnt * k;
    int down = k - up;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i] - a[i - 1];
    for (int i = 0; i <= up; i++)
        for(int j= 0; j <= down; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 0; i <= up; i++) {
        for (int j = 0; j <= down; j++) {
            int len = i * (cnt + 1) + j * cnt;
            if (len + cnt + 1 <= n) dp[i + 1][j] = min(dp[i +1][j], dp[i][j] + sum[len + cnt + 1] - sum[len + 1]);
            if (len + cnt <= n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + sum[len + cnt] - sum[len + 1]);
           // printf("%d %d %d %d %lld %lld\n", i + 1, j, i, j + 1, dp[i + 1][j], dp[i][j + 1]);
        }
    }
    printf("%lld\n",dp[up][down]);
    return 0;
}