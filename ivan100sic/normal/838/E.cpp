#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double x[2505], y[2505];
double dp[2505][2505][2];

inline double sq(double x) {
	return x*x;
}

inline double dst(int i, int j) {
	return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

double solve(int l, int r, int dir) {
	if (dp[l][r][dir] >= 0) {
		return dp[l][r][dir];
	}

	if ((l+1) % n == r) {
		return dp[l][r][dir] = 0;
	}

	if (dir == 1) {
		int lp = (l+1) % n;
		int rp = (r+n-1) % n;

		double v1 = solve(lp, r, 0) + dst(lp, r);
		double v2 = solve(l, rp, 1) + dst(r, rp);

		return dp[l][r][dir] = max(v1, v2);
	} else {
		int lp = (l+1) % n;
		int rp = (r+n-1) % n;

		double v1 = solve(lp, r, 0) + dst(lp, l);
		double v2 = solve(l, rp, 1) + dst(l, rp);

		return dp[l][r][dir] = max(v1, v2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int d=0; d<2; d++) {
				dp[i][j][d] = -1;
			}
		}
	}

	double sol = 0.0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j != i) {
				sol = max(sol, solve(i, j, 0) + dst(i, j));
				sol = max(sol, solve(i, j, 1) + dst(i, j));
			}
		}
	}

	cout.precision(20);
	cout << fixed << sol;

}