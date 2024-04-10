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

const int N = 105;
// dp[i][j][k] -> i, j, match k

int n, m, p, dp[N][N][N], pi[N], aut[N][26];
tuple<int, int, int> tr[N][N][N];
char s[N], t[N], f[N];

inline bool chkmax(int &a, int b) {
	return a < b ? a = b, 1 : 0;
}

void solve_case() {
	cin >> (s + 1) >> (t + 1) >> (f + 1);

	n = strlen(s + 1);
	m = strlen(t + 1);
	p = strlen(f + 1);

	pi[1] = 0;
	for (int i = 2; i <= p; i++) {
		int j = pi[i - 1];
		while (j && f[j + 1] != f[i])
			j = pi[j];
		pi[i] = j + (f[j + 1] == f[i]);
	}

	for (int i = 0; i < p; i++) {
		for (int j = 0; j < 26; j++) {
			if (i && j + 'A' != f[i + 1])
				aut[i][j] = aut[pi[i]][j];
			else
				aut[i][j] = i + (j + 'A' == f[i + 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			for (int k = 0; k < p; k++) {
				if (s[i] == t[j])
					if (chkmax(dp[i][j][ aut[k][s[i] - 'A'] ], dp[i - 1][j - 1][k] + 1))
						tr[i][j][ aut[k][s[i] - 'A'] ] = {-1, -1, k};
				
				if (chkmax(dp[i][j][k], dp[i - 1][j][k]))
					tr[i][j][k] = {-1, 0, k};
				if (chkmax(dp[i][j][k], dp[i][j - 1][k]))
					tr[i][j][k] = {0, -1, k};
			}
	}

	int i = n, j = m, k = max_element(dp[n][m], dp[n][m] + p) - dp[n][m];
	string res = "";

	if (dp[i][j][k]) {

		for (int ni, nj; i && j && dp[i][j][k]; ) {
			tie(ni, nj, k) = tr[i][j][k];
			if (ni < 0 && nj < 0)
				res += s[i];
			i += ni, j += nj;
		}

		reverse(res.begin(), res.end());
		cout << res;

	} else {
		cout << 0;
	}

}