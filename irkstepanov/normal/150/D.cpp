#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;

const int nmax = 160;

int dp[nmax][nmax][nmax];
int ans[nmax][nmax];

int main()
{

	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> cost(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}

	string s;
	cin >> s;

	for (int l = 0; l < nmax; ++l) {
		for (int r = 0; r < nmax; ++r) {
			for (int x = 0; x < nmax; ++x) {
				dp[l][r][x] = -1;
			}
		}
	}

	for (int l = 0; l < n; ++l) {
		dp[l][l][1] = 0;
		if (cost[1] != -1) {
			dp[l][l][0] = cost[1];
		}
	}

	for (int len = 2; len <= n; ++len) {
		for (int l = 0; l + len - 1 < n; ++l) {
			int r = l + len - 1;
			for (int x = 0; x <= len; ++x) {
				for (int m = l + 1; m <= r; ++m) {
					if (dp[l][m - 1][0] != -1 && dp[m][r][x] != -1) {
						dp[l][r][x] = max(dp[l][r][x], dp[l][m - 1][0] + dp[m][r][x]);
					}
				}
				for (int m = r - 1; m >= l; --m) {
					if (dp[l][m][x] != -1 && dp[m + 1][r][0] != -1) {
						dp[l][r][x] = max(dp[l][r][x], dp[l][m][x] + dp[m + 1][r][0]);
					}
				}
				if (s[l] != s[r]) {
					continue;
				}
				if (x >= 2 && dp[l + 1][r - 1][x - 2] != -1) {
					dp[l][r][x] = max(dp[l][r][x], dp[l + 1][r - 1][x - 2]);
				}
				if (x == 2 && len == 2) {
					dp[l][r][x] = max(dp[l][r][x], 0);
				}
				if (x == 0) {
					if (len == 2) {
						if (cost[2] != -1) {
							dp[l][r][x] = max(dp[l][r][x], cost[2]);
						}
						continue;
					}
					for (int y = 2; y <= len; ++y) {
						if (cost[y] != -1 && dp[l + 1][r - 1][y - 2] != -1) {
							dp[l][r][x] = max(dp[l][r][x], dp[l + 1][r - 1][y - 2] + cost[y]);
						}
					}
				}
			}
		}
	}

	for (int l = 0; l < nmax; ++l) {
		for (int r = 0; r < nmax; ++r) {
			ans[l][r] = 0;
		}
	}

	for (int l = 0; l < n; ++l) {
		if (cost[1] != -1) {
			ans[l][l] = max(ans[l][l], cost[1]);
		}
	}

	//cout << dp[1][3][0] << "\n";

	for (int len = 2; len <= n; ++len) {
		for (int l = 0; l + len - 1 < n; ++l) {
			int r = l + len - 1;
			for (int m = l; m < r; ++m) {
				ans[l][r] = max(ans[l][r], ans[l][m] + ans[m + 1][r]);
			}
			if (s[l] != s[r]) {
				continue;
			}
			if (len == 2 && cost[2] != -1) {
				ans[l][r] = max(ans[l][r], cost[2]);
			}
			for (int x = 0; x <= len - 2; ++x) {
				if (cost[x + 2] != -1 && dp[l + 1][r - 1][x] != -1) {
					ans[l][r] = max(ans[l][r], dp[l + 1][r - 1][x] + cost[x + 2]);
				}
			}
		}
	}

	cout << ans[0][n - 1] << '\n';

}