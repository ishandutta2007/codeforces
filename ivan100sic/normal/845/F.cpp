#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MOD = 1'000'000'007;

int n, m;
int dp[2][20][1 << 15][2][2];
string s[255];
int a[255][20];

void dod(int& x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	bool swap_ok = true;

	if (swap_ok) {
		if (n < m) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					if (s[i][j] == 'x') {
						a[j][i] = 1;
					}
				}
			}
			swap(n, m);
		} else {
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					if (s[i][j] == 'x') {
						a[i][j] = 1;
					}
				}
			}
		}
	} else {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (s[i][j] == 'x') {
					a[i][j] = 1;
				}
			}
		}
	}
		

	// prvo polje
	if (a[0][0]) {
		dp[0][0][0][0][0] = 1;
	} else {
		dp[0][0][1][1][0] = 1;
		dp[0][0][0][0][1] = 1;
	}

	// prvi red
	for (int j=1; j<m; j++) {
		// zid?
		if (a[0][j]) {
			for (int mask=0; mask < (1<<j); mask++) {
				dod(dp[0][j][mask][0][0], dp[0][j-1][mask][0][0]);
				dod(dp[0][j][mask][0][0], dp[0][j-1][mask][1][0]);
				dod(dp[0][j][mask][0][1], dp[0][j-1][mask][0][1]);
				dod(dp[0][j][mask][0][1], dp[0][j-1][mask][1][1]);
			}
		} else {
			for (int mask=0; mask < (1<<j); mask++) {
				// stavljam
				dod(dp[0][j][mask + (1 << j)][1][0], dp[0][j-1][mask][0][0]);
				dod(dp[0][j][mask + (1 << j)][1][0], dp[0][j-1][mask][1][0]);
				dod(dp[0][j][mask + (1 << j)][1][1], dp[0][j-1][mask][0][1]);
				dod(dp[0][j][mask + (1 << j)][1][1], dp[0][j-1][mask][1][1]);

				// ne stavljam
				dod(dp[0][j][mask][1][0], dp[0][j-1][mask][1][0]);
				dod(dp[0][j][mask][1][1], dp[0][j-1][mask][1][1]);

				// zaboravim da stavim
				dod(dp[0][j][mask][0][1], dp[0][j-1][mask][0][0]);
			}
		}
	}

	// naredni redovi
	for (int i=1; i<n; i++) {
		auto ol = dp[1 - i % 2];
		auto nu = dp[i % 2];
		memset(nu, 0, sizeof(dp[0]));

		// prvo polje
		if (a[i][0]) {
			for (int mask=0; mask < (1<<m); mask+=2) {
				dod(nu[0][mask][0][0], ol[m-1][mask][0][0]);
				dod(nu[0][mask][0][1], ol[m-1][mask][0][1]);
				dod(nu[0][mask][0][0], ol[m-1][mask][1][0]);
				dod(nu[0][mask][0][1], ol[m-1][mask][1][1]);
				dod(nu[0][mask][0][0], ol[m-1][mask + 1][0][0]);
				dod(nu[0][mask][0][1], ol[m-1][mask + 1][0][1]);
				dod(nu[0][mask][0][0], ol[m-1][mask + 1][1][0]);
				dod(nu[0][mask][0][1], ol[m-1][mask + 1][1][1]);
			}
		} else {
			for (int mask=0; mask < (1<<m); mask++) {
				if (mask & 1) {
					dod(nu[0][mask][1][0], ol[m-1][mask][0][0]);
					dod(nu[0][mask][1][1], ol[m-1][mask][0][1]);

					dod(nu[0][mask][1][0], ol[m-1][mask][1][0]);
					dod(nu[0][mask][1][1], ol[m-1][mask][1][1]);

					dod(nu[0][mask][1][0], ol[m-1][mask - 1][0][0]);
					dod(nu[0][mask][1][1], ol[m-1][mask - 1][0][1]);

					dod(nu[0][mask][1][0], ol[m-1][mask - 1][1][0]);
					dod(nu[0][mask][1][1], ol[m-1][mask - 1][1][1]);
				} else {
					dod(nu[0][mask + 1][0][0], ol[m-1][mask + 1][0][0]);
					dod(nu[0][mask + 1][0][1], ol[m-1][mask + 1][0][1]);

					dod(nu[0][mask + 1][0][0], ol[m-1][mask + 1][1][0]);
					dod(nu[0][mask + 1][0][1], ol[m-1][mask + 1][1][1]);

					dod(nu[0][mask][0][1], ol[m-1][mask][0][0]);
					dod(nu[0][mask][0][1], ol[m-1][mask][1][0]);
				}
			}
		}

		// sva naredna polja
		for (int j=1; j<m; j++) {
			if (a[i][j]) {
				for (int mask=0; mask < (1<<m); mask++) {
					if ((mask & (1 << j)) == 0) {
						dod(nu[j][mask][0][0], nu[j-1][mask][0][0]);
						dod(nu[j][mask][0][1], nu[j-1][mask][0][1]);

						dod(nu[j][mask][0][0], nu[j-1][mask][1][0]);
						dod(nu[j][mask][0][1], nu[j-1][mask][1][1]);

						dod(nu[j][mask][0][0], nu[j-1][mask + (1 << j)][0][0]);
						dod(nu[j][mask][0][1], nu[j-1][mask + (1 << j)][0][1]);

						dod(nu[j][mask][0][0], nu[j-1][mask + (1 << j)][1][0]);
						dod(nu[j][mask][0][1], nu[j-1][mask + (1 << j)][1][1]);
					}
				}
			} else {
				for (int mask=0; mask < (1<<m); mask++) {
					if (mask & (1 << j)) {
						// stavljam
						dod(nu[j][mask][1][0], nu[j-1][mask][0][0]);
						dod(nu[j][mask][1][1], nu[j-1][mask][0][1]);

						dod(nu[j][mask][1][0], nu[j-1][mask][1][0]);
						dod(nu[j][mask][1][1], nu[j-1][mask][1][1]);

						dod(nu[j][mask][1][0], nu[j-1][mask - (1 << j)][0][0]);
						dod(nu[j][mask][1][1], nu[j-1][mask - (1 << j)][0][1]);

						dod(nu[j][mask][1][0], nu[j-1][mask - (1 << j)][1][0]);
						dod(nu[j][mask][1][1], nu[j-1][mask - (1 << j)][1][1]);
					} else {
						// ne stavljam
						// TODO
						// ako polje nije zasticeno sleva, onda mora odozgo
						dod(nu[j][mask + (1 << j)][0][0], nu[j-1][mask + (1 << j)][0][0]);
						dod(nu[j][mask + (1 << j)][0][1], nu[j-1][mask + (1 << j)][0][1]);

						// inace moze ali i ne mora odozgo
						dod(nu[j][mask + (1 << j)][1][0], nu[j-1][mask + (1 << j)][1][0]);
						dod(nu[j][mask + (1 << j)][1][1], nu[j-1][mask + (1 << j)][1][1]);

						dod(nu[j][mask][1][0], nu[j-1][mask][1][0]);
						dod(nu[j][mask][1][1], nu[j-1][mask][1][1]);

						// ni jedno ni drugo,
						dod(nu[j][mask][0][1], nu[j-1][mask][0][0]);
					}
				}
			}
		}
	}

	int sol = 0;
	for (int mask=0; mask < (1<<m); mask++) {
		dod(sol, dp[(n - 1) % 2][m-1][mask][0][0]);
		dod(sol, dp[(n - 1) % 2][m-1][mask][0][1]);
		dod(sol, dp[(n - 1) % 2][m-1][mask][1][0]);
		dod(sol, dp[(n - 1) % 2][m-1][mask][1][1]);
	}

	cout << sol << '\n';
}