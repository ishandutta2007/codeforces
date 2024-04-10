#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3005;
typedef long long ll;

int n;
ll a[N], b[N], dp[2][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] -= i; b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int now = 0, pre = 1;
	for (int i = 1; i <= n; i++) dp[now][i] = max(a[1] - b[i], b[i] - a[1]);
	for (int i = 2; i <= n; i++) dp[now][i] = min(dp[now][i - 1], dp[now][i]);
	for (int i = 2; i <= n; i++) {
		swap(pre, now);
		for (int j = 1; j <= n; j++)
			dp[now][j] = dp[pre][j] + max(a[i] - b[j], b[j] - a[i]);
		for (int j = 2; j <= n; j++) dp[now][j] = min(dp[now][j - 1], dp[now][j]);
	}
	long long ans = dp[now][1];
	for (int i = 1; i <= n; i++) ans = min(ans, dp[now][i]);
	printf("%lld\n", ans);
	return 0;
}