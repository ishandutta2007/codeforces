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

const int N = 2e4 + 5;

int n, m, k, dp[2][N], pr[N], pre_mx[N], suf_mx[N];

int dq[N], val[N], qh = 1, qt = 0;

void solve_case() {
	cin >> n >> m >> k;
	for (int j = 1, a; j <= m; j++)
		cin >> a, pr[j] = pr[j - 1] + a;

	for (int j = k; j <= m; j++)
		dp[1][j] = pr[j] - pr[j - k];

	for (int i = 2; i <= n; i++) {
		
		for (int j = 1, a; j <= m; j++)
			cin >> a, pr[j] = pr[j - 1] + a;

		for (int j = k; j <= m; j++)
			pre_mx[j] = max(pre_mx[j - 1], dp[i & 1 ^ 1][j] + pr[j] - pr[j - k]);
		for (int j = m; j >= k; j--)
			suf_mx[j] = max(suf_mx[j + 1], dp[i & 1 ^ 1][j] + pr[j] - pr[j - k]);

		for (int j = k; j <= m; j++) {
			if (j - k >= 0) dp[i & 1][j] = max(dp[i & 1][j], pre_mx[j - k]);
			if (j + k <= m) dp[i & 1][j] = max(dp[i & 1][j], suf_mx[j + k]);

			dp[i & 1][j] += pr[j] - pr[j - k];
		}

		qh = 1, qt = 0;
		for (int j = k; j <= m; j++) {
			while (qh <= qt && dq[qh] < j - k) 
				qh ++;

			val[j] = dp[i & 1 ^ 1][j] - pr[j - k];
			while (qh <= qt && val[dq[qt]] < val[j])
				qt --;
			dq[++ qt] = j;

			dp[i & 1][j] = max(dp[i & 1][j], val[dq[qh]] + pr[j]);
		}

		qh = 1, qt = 0;
		for (int j = m; j >= k; j--) {
			while (qh <= qt && dq[qh] > j + k)
				qh ++;

			val[j] = dp[i & 1 ^ 1][j] + pr[j];
			while (qh <= qt && val[dq[qt]] < val[j])
				qt --;
			dq[++ qt] = j;

			dp[i & 1][j] = max(dp[i & 1][j], val[dq[qh]] - pr[j - k]);
		}

	}
	cout << * max_element(dp[n & 1] + k, dp[n & 1] + m + 1) << '\n';
}