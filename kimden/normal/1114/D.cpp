#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int dp[5432][5432];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	vector<int> c;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (!c.empty() && c.back() == x) {
			continue;
		}
		c.push_back(x);
	}
	n = c.size();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (c[i - 1] == c[n - j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i][n - 1 - i]);
	}
	cout << n - 1 - ans << endl;
}