#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 10;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	vector<bitset<N>> pos(n + 1);
	pos[0].set(0);
	for (int i = 0; i < n; ++i) pos[i + 1] = (pos[i] << a[i]) | (pos[i] << b[i]);
	int sm = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
	int big = (sm + 1) / 2;
	while (!pos[n].test(big)) ++big;
	vector<vector<int>> dp(n, vector<int>(N, -1));
	function<int(int, int)> solve = [&](int i, int csm) {
		if (i < 0) return 0;
		if (~dp[i][csm]) return dp[i][csm];
		int res = INT_MAX;
		if (a[i] <= csm && pos[i].test(csm - a[i])) res = solve(i - 1, csm - a[i]) + (big - a[i]) * a[i] + (sm - big - b[i]) * b[i];
		if (b[i] <= csm && pos[i].test(csm - b[i])) res = min(res, solve(i - 1, csm - b[i]) + (big - b[i]) * b[i] + (sm - big - a[i]) * a[i]);
		return dp[i][csm] = res + (n - 1) * (a[i] * a[i] + b[i] * b[i]);
	};
	cout << solve(n - 1, big) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}