#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef ld realt;

realt dp[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	n -= x; // x je slobodno
	y -= 1;

	if (m <= 2) {
		cout << (m+1)*n << ".00000\n";
		return 0;
	}

	for (int i=1; i<=n; i++) {
		realt lo = dp[i-1][0] + 1;
		realt hi = lo + 5;
		int steps = 90;
		while (steps--) {
			double mid = (lo+hi) / 2;
			dp[i][0] = mid;
			dp[i][1] = 2*mid - dp[i-1][0] - 2;

			int dir = 0;

			for (int j=2; j<m; j++) {
				dp[i][j] = dp[i][j-1]*3 - dp[i][j-2] - dp[i-1][j-1] - 3;
				if (dp[i][j] < dp[i-1][j] + 1) {
					dir = -1;
					break;
				} else if (dp[i][j] > dp[i-1][j] + 10) {
					dir = 1;
					break;
				}
			}

			if (dir == 0) {
				if (dp[i][m-1] > mid) {
					dir = 1;
				} else {
					dir = -1;
				}
			}

			for (int x=0, y=m-1; x<y; x++, y--) {
				dp[i][y] = dp[i][x];
			}

			
				

			// for (int j=0; j<m; j++)
			// 	cerr << dp[i][j] << ' ';
			// cerr << '\n';

			if (dir == 1) {
				hi = mid;
			} else {
				lo = mid;
			}
		}

		// refine
		int refinements = 50;
		while (refinements--) {
			for (int j=0; j<m; j++) {
				if (j == 0) {
					dp[i][j] = (dp[i-1][j] + dp[i][j+1]) / 2 + 1;
				} else if (j == m-1) {
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) / 2 + 1;
				} else {
					dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i][j+1]) / 3 + 1;
				}
			}
		}

		// cerr << "~~~~~~~~\n";
	}

	// previse je velika koincidencija da ne bi bilo tacno
	cout << setprecision(20) << fixed << (n + dp[n][y]) << '\n';
}