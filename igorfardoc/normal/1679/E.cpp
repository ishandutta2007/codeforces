#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;
int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = (ll)res * res % mod;
	if(b & 1) res = (ll)res * a % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vi> am(18, vi(1 << 17, 0));
	int total = 0;
	for(int i = 0; i < n; i++) total += (s[i] == '?');
	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
	for(int len = 1; len <= n; len++) {
		for(int l = 0; l + len <= n; l++) {
			int r = l + len - 1;
			if(len == 1) {
				dp[l][r] = {0, total};
			} else {
				int mask = 0;
				int ans = total;
				if(len != 2) {
					mask = dp[l + 1][r - 1].first;
					ans = dp[l + 1][r - 1].second;
				}
				if(s[l] == '?' && s[r] == '?') {
					--ans;
				} else if(s[l] == '?') {
					--ans;
					mask = mask | (1 << (s[r] - 'a'));
				} else if(s[r] == '?') {
					--ans;
					mask = mask | (1 << (s[l] - 'a'));
				} else if(s[l] != s[r]) {
					ans = -1;
				}
				if(ans < -1) ans = -1;
				dp[l][r] = {mask, ans};
			}
			if(dp[l][r].second == -1) continue;
			int msk = dp[l][r].first;
			int val = dp[l][r].second;
			for(int i = 0; i <= 17; i++) {
				am[i][msk] = (am[i][msk] + bin_pow(i, val)) % mod;
			}
		}
	}
	vi ans(1 << 17, 0);
	for(int mask = 0; mask < (1 << 17); mask++) {
		int here = 0;
		int p = __builtin_popcount(mask);
		for(int mask1 = mask;; mask1 = (mask1 - 1) & mask) {
			here = (here + am[p][mask1]) % mod;
	 		if(mask1 == 0) break;
	 	}
	 	ans[mask] = here;
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int mask = 0;
		string s;
		cin >> s;
		for(const auto& el : s) {
			mask = mask | (1 << (el - 'a'));
		}
		cout << ans[mask] << '\n';
	}

}