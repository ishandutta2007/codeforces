#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 80;
const int inf = 1e9;

int dp[nmax][3][nmax][nmax];
int ptr[3][nmax];

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < nmax; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < nmax; ++k) {
				for (int l = 0; l < nmax; ++l) {
					dp[i][j][k][l] = inf;
				}
			}
		}
	}

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < nmax; ++j) {
			ptr[i][j] = inf;
		}
	}

	int last[3] = {0, 0, 0};
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'V') {
			ptr[0][last[0]] = i;
			++last[0];
		} else if (s[i] == 'K') {
			ptr[1][last[1]] = i;
			++last[1];
		} else {
			ptr[2][last[2]] = i;
			++last[2];
		}
	}

	dp[0][2][0][0] = 0;
	for (int alive = 0; alive < n; ++alive) {
		for (int c = 0; c < 3; ++c) {
			for (int x = 0; x <= alive; ++x) {
				for (int y = 0; y + x <= alive; ++y) {
					for (int d = 0; d < 3; ++d) {
						if (c == 0 && d == 1) {
							continue;
						}
						int pos;
						int z = alive - x - y;
						if (d == 0) {
							pos = ptr[d][x];
						} else if (d == 1) {
							pos = ptr[d][y];
						} else {
							pos = ptr[d][z];
						}
						if (pos == inf) {
							continue;
						}
						int val = dp[alive][c][x][y];
						for (int t = 0; t < x; ++t) {
							if (ptr[0][t] > pos) {
								++val;
							}
						}
						for (int t = 0; t < y; ++t) {
							if (ptr[1][t] > pos) {
								++val;
							}
						}
						for (int t = 0; t < z; ++t) {
							if (ptr[2][t] > pos) {
								++val;
							}
						}

						if (d == 0) {
							dp[alive + 1][d][x + 1][y] = min(dp[alive + 1][d][x + 1][y], val);
						} else if (d == 1) {
							/*if (alive + 1 == 6 && d == 1 && x + 1 == 3 && y == 2) {
								cout << "!" << alive << " " << c << " " << x << " " << y << " " << val << "\n";
							}*/
							dp[alive + 1][d][x][y + 1] = min(dp[alive + 1][d][x][y + 1], val);
						} else {
							dp[alive + 1][d][x][y] = min(dp[alive + 1][d][x][y], val);
						}
					}
				}
			}
		}
	}

	int ans = inf;
	for (int c = 0; c < 3; ++c) {
		ans = min(ans, dp[n][c][last[0]][last[1]]);
		//cout << dp[n][c][last[0]][last[1]] << "\n";
	}
	cout << ans << '\n';

}