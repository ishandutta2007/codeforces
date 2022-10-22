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

const int N = 30, K = 50;

int dp[N + 5][N + 5][K + 5];

inline void chkmin(int &a, int b) {
	a = a < b ? a : b;
}

void solve_case() {
	// cin >> n >> m >> k;

	memset(dp, 0x3f, sizeof dp);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int lim = min(i * j, K);

			dp[i][j][0] = 0;
			if (lim == i * j)
				dp[i][j][i * j] = 0, -- lim;

			for (int C = 1; C < i; C++) {
				// dp[C][j] + dp[i - C][j]
				for (int f1 = 0; f1 <= lim; f1++)
					for (int f2 = 0; f1 + f2 <= lim; f2++)
						chkmin(dp[i][j][f1 + f2], dp[C][j][f1] + dp[i - C][j][f2] + j * j);
			}

			for (int C = 1; C < j; C++) {
				// dp[i][C] + dp[i][j - C]
				for (int f1 = 0; f1 <= lim; f1++)
					for (int f2 = 0; f1 + f2 <= lim; f2++)
						chkmin(dp[i][j][f1 + f2], dp[i][C][f1] + dp[i][j - C][f2] + i * i);
			}
		}
	}

	int test, n, m, k;
	for (cin >> test; test --; ) {
		cin >> n >> m >> k;
		cout << dp[n][m][k] << '\n';
	}
}