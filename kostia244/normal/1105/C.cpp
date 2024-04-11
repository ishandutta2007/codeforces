#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

long long n, l, r, nd[3] = { 0, }, dp[200019][3] = { { 0, }, };

long long countDivisibles(long long A, long long B, long long M) {
	if (A % M == 0)
		return (B / M) - (A / M) + 1;
	return (B / M) - (A / M);
}

int main() {
	cin >> n >> l >> r;
	nd[0] = nd[1] = nd[2] = 0;

	if (l % 3 == 1) {
		l++;
		nd[1]++;
	}
	if (l % 3 == 2) {
		l++;
		nd[2]++;
	}
	if (r % 3 == 2) {
		r--;
		nd[2]++;
	}
	if (r % 3 == 1) {
		r--;
		nd[1]++;
	}

	nd[0] = countDivisibles(l, r, 3);
	nd[1] += nd[0] - 1;
	nd[2] += nd[0] - 1;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		dp[i + 1][0] += dp[i][0] * nd[0];
		dp[i + 1][0] %= 1000000007;
		dp[i + 1][0] += dp[i][1] * nd[2];
		dp[i + 1][0] %= 1000000007;
		dp[i + 1][0] += dp[i][2] * nd[1];
		dp[i + 1][0] %= 1000000007;

		dp[i + 1][1] += dp[i][0] * nd[1];
		dp[i + 1][1] %= 1000000007;
		dp[i + 1][1] += dp[i][1] * nd[0];
		dp[i + 1][1] %= 1000000007;
		dp[i + 1][1] += dp[i][2] * nd[2];
		dp[i + 1][1] %= 1000000007;

		dp[i + 1][2] += dp[i][0] * nd[2];
		dp[i + 1][2] %= 1000000007;
		dp[i + 1][2] += dp[i][1] * nd[1];
		dp[i + 1][2] %= 1000000007;
		dp[i + 1][2] += dp[i][2] * nd[0];
		dp[i + 1][2] %= 1000000007;
	}
	cout << dp[n][0];
}