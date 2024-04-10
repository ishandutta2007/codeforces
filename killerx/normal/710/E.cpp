#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, x, y;
ll dp[10 << 20];

int main() {
	scanf("%d %d %d", &n, &x, &y);
	rep(i, n + 1) if (i) {
		if (!(i & 1)) dp[i] = min(dp[i >> 1] + y, dp[i - 1] + x);
		else dp[i] = min(dp[(i + 1) >> 1] + y + x, dp[i - 1] + x);
	}
	printf("%lld\n", dp[n]);
	return 0;
}