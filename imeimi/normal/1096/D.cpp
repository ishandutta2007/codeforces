#include <cstdio>
#include <algorithm>

using namespace std;

int n;
const long long inf = 1e18;
const char h[] = "hard";
char str[100001];
long long dp[100001][5];
int a[100001];

int main() {
scanf("%d%s", &n, str);
for (int i=1; i<=n; ++i){
scanf("%d", &a[i]);
for (int j = 0; j < 5; ++j)
dp[i][j] = inf;
for (int j = 0; j < 4; ++j) {
dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]);
if (str[i-1]==h[j]) dp[i][j+1]=min(dp[i][j+1], dp[i-1][j]);
else dp[i][j]=min(dp[i][j], dp[i-1][j]);
}
}
long long ans = inf;
for (int i = 0; i < 4; ++i) ans = min(ans, dp[n][i]);
printf("%lld", ans);
}