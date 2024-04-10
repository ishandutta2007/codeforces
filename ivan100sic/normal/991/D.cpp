#include <bits/stdc++.h>
using namespace std;

int dp[105][3];
string a, b;

void ad(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	a = string(" ") + a;
	b = string(" ") + b;

	for (char& x : a)
		if (x == '0')
			x = 1;
		else
			x = 0;

	for (char& x : b)
		if (x == '0')
			x = 1;
		else
			x = 0;

	int n = a.size() - 1;

	for (int i=1; i<=n; i++) {
		if (a[i] && a[i-1] && b[i-1])
			ad(dp[i][1], dp[i-2][0] + 1);
		ad(dp[i][1], dp[i-1][0]);

		if (b[i] && b[i-1] && a[i-1])
			ad(dp[i][2], dp[i-2][0] + 1);
		ad(dp[i][2], dp[i-1][0]);

		ad(dp[i][0], dp[i][1]);
		ad(dp[i][0], dp[i][2]);

		if (a[i] && b[i] && a[i-1])
			ad(dp[i][0], dp[i-1][2] + 1);
		if (a[i] && b[i] && b[i-1])
			ad(dp[i][0], dp[i-1][1] + 1);
	}

	cout << dp[n][0] << '\n';
}