#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const long long INF = 1e16;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector< vector<long long> > a(3, vector<long long>(n));
	vector< vector<long long> > dp(3, vector<long long>(n, -INF));
	vector< vector<long long> > dpu(3, vector<long long>(n, -INF));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	dp[0][0] = a[0][0];
	dp[1][0] = a[0][0] + a[1][0];
	dp[2][0] = a[1][0] + a[2][0] + a[0][0];
	dpu[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			dp[j][i] = dp[j][i - 1] + a[j][i];
		for (int j = 0; j < 3; j++)
			dpu[j][i] = dp[j][i];
		long long l = dp[0][i], r = dp[2][i];
		dp[0][i] = max(dp[0][i], max(dp[1][i] + a[0][i], r + a[0][i] + a[1][i]));
		dp[2][i] = max(dp[2][i], max(dp[1][i] + a[2][i], l + a[2][i] + a[1][i]));
		dp[1][i] = max(dp[1][i], max(l, r) + a[1][i]);
		long long s1 = a[0][i] + a[1][i] + a[2][i];
		long long s2 = a[0][i - 1] + a[1][i - 1] + a[2][i - 1];
		dp[0][i] = max(dp[0][i], dpu[2][i - 1] + s1 + s2 - a[2][i - 1]);
		dp[2][i] = max(dp[2][i], dpu[0][i - 1] + s1 + s2 - a[0][i - 1]);
	}
	cout << dp[2][n - 1];
	return 0;
}