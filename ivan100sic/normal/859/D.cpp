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

long double a[64][64];
int n, e;

long double prob_vector[64][64][64];

long double dp[64][64][64];
bool solved[64][64][64];

void dod(long double& x, long double y) {
	if (y > x) {
		x = y;
	}
}

void solve(int l, int r, int x, int scale) {
	if (solved[l][r][x]) {
		return;
	}

	if (l+1 == r) {
		prob_vector[l][r][x] = 1.0L;
		return;
	}

	// levi ili desni deo zreba?
	int m = (l + r) / 2;

	for (int i=l; i<m; i++) {
		solve(l, m, i, scale/2);
	}
	for (int i=m; i<r; i++) {
		solve(m, r, i, scale/2);
	}

	if (x < m) {
		// drugi je neko iz druge polovine
		for (int j=m; j<r; j++) {
			prob_vector[l][r][x] += prob_vector[l][m][x] * prob_vector[m][r][j] * a[x][j];
		}

		for (int j=m; j<r; j++) {
			long double skor = dp[l][m][x] + dp[m][r][j] + scale * prob_vector[l][r][x];
			dod(dp[l][r][x], skor);		
		}

	} else {
		for (int j=l; j<m; j++) {
			prob_vector[l][r][x] += prob_vector[m][r][x] * prob_vector[l][m][j] * a[x][j];
		}

		for (int j=l; j<m; j++) {
			long double skor = dp[m][r][x] + dp[l][m][j] + scale * prob_vector[l][r][x];
			dod(dp[l][r][x], skor);		
		}
	}

	solved[l][r][x] = true;
}

long double sol = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> e;
	n = 1 << e;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int x;
			cin >> x;
			a[i][j] = x * 0.01L;
		}
	}

	for (int i=0; i<n; i++) {
		solve(0, n, i, n/2);
		sol = max(sol, dp[0][n][i]);
	}

	cout.precision(20);
	cout << fixed << sol;


}