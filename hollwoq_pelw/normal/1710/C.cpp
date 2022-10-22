#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, dp[200005][8][8];

int main(){
	string s; cin >> s;
	n = s.size();
	dp[0][0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0, F = s[i] & 1 ? 7 : j; k < 8; k++) {
				for (int l = 0; l < 8; l++) if ((l & F) == l)
					(dp[i + 1][j | (l ^ F)][k | (1 << min(l, 7 - l) >> 1)] += dp[i][j][k]) %= mod;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 8; i++)
		(res += dp[n][i][7]) %= mod;

	cout << res << '\n';
}