#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 5e5 + 5;

int n, k, d, a[N], dp[N], pre[N];

void solve_case() {
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	dp[0] = pre[0] = 1;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j < i && a[i] - a[j + 1] > d) j ++;
		// j -> i - k
		dp[i] = j > i - k ? 0 : pre[i - k] > (j ? pre[j - 1] : 0);
		pre[i] = pre[i - 1] + dp[i];
	}

	cout << (dp[n] ? "YES" : "NO");
}