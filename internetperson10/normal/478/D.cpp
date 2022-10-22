#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

ll dp[2][200001];

int main() {
	int r, g;
	cin >> r >> g;
	int n = r+g;
	int h = 1, x = 0;
	for(; x <= n; h++) {
		x += h;
	}
	h--;
	x -= h;
	h--;
	for(int i = x - g; i <= r; i++) dp[1][i] = 1;
	for(int i = h; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			dp[0][j] += dp[1][j];
		}
		for(int j = i; j <= r; j++) {
			dp[0][j] += dp[1][j];
			dp[0][j-i] += dp[1][j];
		}
		for(int j = 0; j <= r; j++) {
			dp[1][j] = dp[0][j];
			if(dp[1][j] > MOD) dp[1][j] %= MOD;
			if(i > 1) dp[0][j] = 0;
		}
	}
	cout << dp[0][0]%MOD << '\n';
}