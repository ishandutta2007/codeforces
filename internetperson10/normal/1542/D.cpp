#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector<ll> nums;
vector<pair<ll, int>> sorted;
vector<pair<bool, int>> ops;

ll pow2[501];
ll dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pow2[0] = 1;
	for(int i = 1; i <= 500; i++) {
		pow2[i] = (2 * pow2[i-1])%MOD;
	}
	int t, minuses = 0, pluses = 0;
	cin >> t;
	ll ans = 0, seq = 1;
	for(int i = 0; i < t; i++) {
		char c;
		ll n;
		cin >> c;
		if(c == '+') {
			cin >> n;
			nums.push_back(n);
			ops.push_back({true, n});
			dp[pluses][0] = 1;
			for(int j = 0; j < i; j++) {
				if(ops[j].first) {
					if(ops[j].second < n) {
						for(int k = 499; k >= 0; k--) {
							dp[pluses][k+1] += dp[pluses][k];
							dp[pluses][k+1] %= MOD;
						}
					}
					else {
						for(int k = 500; k >= 0; k--) {
							dp[pluses][k] *= 2;
							dp[pluses][k] %= MOD;
						}
					}
				}	
				else {
					dp[pluses][0] *= 2;
					dp[pluses][0] %= MOD;
					for(int k = 0; k < 500; k++) {
						dp[pluses][k] += dp[pluses][k+1];
						dp[pluses][k] %= MOD;
					}
				}
			}
			for(int j = 0; j < pluses; j++) {
				if(nums[j] < n) {
					for(int k = 500; k >= 0; k--) {
						dp[j][k] *= 2;
						dp[j][k] %= MOD;
					}
					continue;
				}
				for(int k = 499; k >= 0; k--) {
					dp[j][k+1] += dp[j][k];
					dp[j][k+1] %= MOD;
				}
			}
			pluses++;
		}
		else {
			ops.push_back({false, 0});
			for(int j = 0; j < pluses; j++) {
				for(int k = 0; k < 500; k++) {
					dp[j][k] += dp[j][k+1];
					dp[j][k] %= MOD;
				}
			}
		}
	}
	for(int j = 0; j < pluses; j++) {
		for(int k = 0; k <= 500; k++) {
			// if(k < 5 && j < 5) cout << dp[j][k] << ' ';
			ans += nums[j] * dp[j][k];
			ans %= MOD;
			// if(k == 5 && j < 5) cout << '\n';
		}
	}
	cout << ans << '\n';
}