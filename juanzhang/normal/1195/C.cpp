#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
ll dp[maxn][2];
int n, a[maxn][2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i][0]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i][0]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i][1]);
	}
	printf("%I64d", max(dp[n][0], dp[n][1]));
  return 0;
}