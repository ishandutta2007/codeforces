// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, l;
string s, t;

int dp[2][205][205];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> l >> s >> t;

	memset(dp[0], 192, sizeof dp[0]);
	dp[0][0][0] = 0;
	for (int i=0; i<n; i++) {
		auto ol = dp[i%2];
		auto nu = dp[1-i%2];
		memset(nu, 192, sizeof dp[0]);

		for (int j=0; j<=i; j++) {
			for (int k=0; k<=i; k++) {
				for (char c : t+s[i]) {
					mx(nu[j + (c != s[i])][k + (c == t[0])], ol[j][k] + k*(c == t[1]));
				}
			}
		}
	}

	int sol = 0;
	for (int j=0; j<=l; j++) {
		for (int k=0; k<=n; k++) {
			mx(sol, dp[n%2][j][k]);
		}
	}
	cout << sol << '\n';
}