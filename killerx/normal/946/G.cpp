#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct BIT {
	static const int mxn = 4e5 + 5;
	int mx[mxn];

	BIT() { memset(mx, -0x3f, sizeof(mx)); }

	void update(int x, int v) { for (++ x; x < mxn; x += x & -x) mx[x] = std::max(mx[x], v); }

	int query(int x) { int ans = -0x3f3f3f3f; for (++ x; x; x -= x & -x) ans = std::max(ans, mx[x]); return ans; }
} bit[2];

const int mxn = 2e5 + 5;

int n;
int a[mxn];
std::vector <int> vec;

int dp[mxn][2];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i + 1]);
	a[0] = -1e9 - 7;
	a[n + 1] = 1e9 + 7;
	n += 2;
	rep(i, n) a[i] -= i;
	rep(i, n) vec.push_back(a[i]), vec.push_back(a[i] + 1);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	rep(i, n) a[i] = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
	// rep(i, n) eprintf("%d\n", a[i]);
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 1;
	dp[1][0] = 2;
	rep(i, n) {
		bit[0].update(a[i], dp[i][0]);
		bit[1].update(a[i] + 1, dp[i][1]);
		if (i + 1 < n) {
			dp[i + 1][0] = std::max(dp[i + 1][0], bit[0].query(a[i + 1]) + 1);
			dp[i + 1][1] = std::max(dp[i + 1][1], bit[1].query(a[i + 1] + 1) + 1);
		}
		if (i + 2 < n) {
			dp[i + 2][1] = std::max(dp[i + 2][1], bit[0].query(a[i + 2] + 1) + 1);
		}
	}
	// rep(i, n) eprintf("%d %d\n", dp[i][0], dp[i][1]);
	printf("%d\n", std::min(n - dp[n - 1][0], n - 1 - dp[n - 1][1]));
	return 0;
}