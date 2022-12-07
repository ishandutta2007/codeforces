#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1000005;
const ll INF = 0x3f3f3f3f3f3f3f;

int n;
ll a[N], dp[N][2];

int main() {
    scanf("%d", &n);
    scanf("%lld", &a[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > a[i - 1]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i] - a[i - 1]);
            dp[i][0] = max(dp[i][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        else {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i - 1] - a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 1][0]);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
    }
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}