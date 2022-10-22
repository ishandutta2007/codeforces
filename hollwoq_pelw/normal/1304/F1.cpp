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

int n, m, k, dp[55][N], pr[55][N], pre_mx[N], suf_mx[N];

int dq[N], val[N], qh = 1, qt = 0;

void solve_case() {
	cin >> n >> m >> k;
	for (int i = 1, a; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a, pr[i][j] = pr[i][j - 1] + a;
	}

	for (int j = k; j <= m; j++)
		dp[1][j] = pr[1][j] - pr[1][j - k];

	for (int i = 2; i <= n; i++) {

		for (int j = k; j <= m; j++)
			pre_mx[j] = max(pre_mx[j - 1], dp[i - 1][j] + pr[i][j] - pr[i][j - k]);
		for (int j = m; j >= k; j--)
			suf_mx[j] = max(suf_mx[j + 1], dp[i - 1][j] + pr[i][j] - pr[i][j - k]);

		for (int j = k; j <= m; j++) {
			if (j - k >= 0) dp[i][j] = max(dp[i][j], pre_mx[j - k]);
			if (j + k <= m) dp[i][j] = max(dp[i][j], suf_mx[j + k]);

			dp[i][j] += pr[i][j] - pr[i][j - k];
		}

		qh = 1, qt = 0;
		for (int j = k; j <= m; j++) {
			while (qh <= qt && dq[qh] < j - k) 
				qh ++;

			val[j] = dp[i - 1][j] - pr[i][j - k];
			while (qh <= qt && val[dq[qt]] < val[j])
				qt --;
			dq[++ qt] = j;

			dp[i][j] = max(dp[i][j], val[dq[qh]] + pr[i][j]);
		}

		qh = 1, qt = 0;
		for (int j = m; j >= k; j--) {
			while (qh <= qt && dq[qh] > j + k)
				qh ++;

			val[j] = dp[i - 1][j] + pr[i][j];
			while (qh <= qt && val[dq[qt]] < val[j])
				qt --;
			dq[++ qt] = j;

			dp[i][j] = max(dp[i][j], val[dq[qh]] - pr[i][j - k]);
		}

		// for (int j = k; j <= m; j++)
		// 	cout << dp[i][j] << " \n"[j == m];

	}
	cout << * max_element(dp[n] + k, dp[n] + m + 1) << '\n';
}