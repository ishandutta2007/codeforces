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

const int MOD = 1'000'000'007;

int f[10005], finv[10005];

int pw(int x, int b) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return x;
	}
	int tmp = pw(x, b/2);
	tmp = 1ll * tmp * tmp % MOD;
	if (b % 2) {
		tmp = 1ll * tmp * x % MOD;
	}
	return tmp;
}

int inv(int x) {
	return pw(x, MOD-2);
}

void init() {
	f[0] = 1;
	finv[0] = 1;
	for (int i=1; i<10005; i++) {
		f[i] = 1ll * i * f[i-1] % MOD;
		finv[i] = inv(f[i]);
	}
}

int u[5005];
int dp[5005][27];

int binom(int n, int k) {
	return 1ll * f[n] * finv[k] % MOD * finv[n-k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (char& x : s) {
		x -= 'a';
	}

	// DP START

	dp[0][26] = 1;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j>=1; j--) {

			dp[j][s[i]] = 0;

			for (int x=0; x<27; x++) {
				if (x != s[i]) {
					dp[j][s[i]] += dp[j-1][x];

					if (dp[j][s[i]] >= MOD) {
						dp[j][s[i]] -= MOD;
					}
				}
			}

		}
	}

	for (int j=1; j<=n; j++) {
		for (int x=0; x<26; x++) {
			u[j] += dp[j][x];
			if (u[j] >= MOD) {
				u[j] -= MOD;
			}
		}
	}

	// DP END
	
	for (int j=1; j<=n; j++) {
		cerr << j << ' ' << u[j] << '\n';
	}
	cerr << '\n';

	int sol = 0;
	for (int i=1; i<=n; i++) {
		sol += binom(n-1, i-1) * 1ll * u[i] % MOD;
		if (sol >= MOD) {
			sol -= MOD;
		}
	}

	cout << sol;

}