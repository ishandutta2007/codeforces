#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, k, Q;
	cin >> N >> k >> Q;
	vector<long long> a(N);
	vector<long long> sum(N);
	vector<vector<long long>> dp(k + 1, vector<long long>(N));
	const long long MOD = (long long)1e9 + 7;
	for(long long i = 0; i < N; ++i){
		cin >> a[i];
		dp[0][i] = 1;
	}
	for(long long i = 0; i < k; ++i){
		for(long long j = 0; j < N; ++j){
			if(j + 1 < N){
				dp[i + 1][j + 1] += dp[i][j]; dp[i + 1][j + 1] %= MOD;
			}
			if(j - 1 >= 0){
				dp[i + 1][j - 1] += dp[i][j]; dp[i + 1][j - 1] %= MOD;
			}
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= k; ++j){
			sum[i] += dp[j][i] * dp[k - j][i]; sum[i] %= MOD;
		}
	}
	long long ans = 0;
	for(long long i = 0; i < N; ++i){
		ans += sum[i] * a[i];
		ans %= MOD;
	}
	for(long long i = 0; i < Q; ++i){
		long long x, y; cin >> x >> y;
		--x;
		ans -= (sum[x] * a[x]) % MOD; ans += MOD;
		a[x] = y;
		ans += (sum[x] * a[x]) % MOD; ans %= MOD;
		cout << ans << '\n';
	}
	return 0;
}