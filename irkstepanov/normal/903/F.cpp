#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int inf = 1e9;

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	//n = 1000;
	vector<int> cost(5);
	for (int i = 1; i < 5; ++i) {
		cin >> cost[i];
		//cost[i] = 1;
	}

	vector<vector<char> > t(4, vector<char>(n));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t[i][j];
			//t[i][j] = '*';
		}
	}

	vector<vector<int> > dp(n + 1, vector<int>(1 << 12, inf));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << 12); ++mask) {
			if (dp[i][mask] == inf) {
				continue;
			}
			for (int a = 0; a < 5; ++a) {
				int nx = (mask >> 4);
				for (int i = 0; i < a - 1; ++i) {
					for (int j = 0; j < a; ++j) {
						nx |= (1 << (0 + j + 4 * i));
					}
				}
				if (a == 0 && t[0][i] == '*' && !bit(mask, 0)) {
					continue;
				}
				for (int b = 0; b < 4; ++b) {
					/*if (a >= 2 && b > 0) {
						continue;
					}*/
					if (b == 0 && a <= 1 && t[1][i] == '*' && !bit(mask, 1)) {
						continue;
					}
					int nxx = nx;
					for (int i = 0; i < b - 1; ++i) {
						for (int j = 0; j < b; ++j) {
							nxx |= (1 << (1 + j + 4 * i));
						}
					}
					for (int c = 0; c < 3; ++c) {
						/*if (c > 0 && (a >= 3 || b >= 2)) {
							continue;
						}*/
						if (c == 0 && b <= 1 && a <= 2 && t[2][i] == '*' && !bit(mask, 2)) {
							continue;
						}
						int nxxx = nxx;
						for (int i = 0; i < c - 1; ++i) {
							for (int j = 0; j < c; ++j) {
								nxxx |= (1 << (2 + j + 4 * i));
							}
						}
						for (int d = 0; d < 2; ++d) {
							/*if (d > 0 && (a >= 4 || b >= 3 || c >= 2)) {
								continue;
							}*/
							if (d == 0 && c <= 1 && b <= 2 && a <= 3 && t[3][i] == '*' && !bit(mask, 3)) {
								continue;
							}
							int nxxxx = nxxx;
							for (int i = 0; i < d - 1; ++i) {
								for (int j = 0; j < d; ++j) {
									nxxxx |= (1 << (3 + j + 4 * i));
								}
							}
							dp[i + 1][nxxxx] = min(dp[i + 1][nxxxx], dp[i][mask] + cost[a] + cost[b] + cost[c] + cost[d]);
						}
					}
				}
			}
		}
	}

	int ans = inf;
	for (int mask = 0; mask < (1 << 12); ++mask) {
		ans = min(ans, dp[n][mask]);
	}
	cout << ans << "\n";

}