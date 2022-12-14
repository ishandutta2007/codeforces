#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> extgcd(long long a, long long b){
    if(b == 0) return make_pair(a, b);
    pair<long long, long long> gap = extgcd(b, a % b);
    return make_pair(gap.second, gap.first - (a / b) * gap.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const long long MOD = (long long)1e9 + 7;
	long long N;
	cin >> N;
	vector<long long> a(N);
	for(long long i = 0; i < N; ++i){
		cin >> a[i];
	}
	vector<long long> gop((long long)3e5 + 4);
	for(long long i = 0; i < N; ++i){
		++gop[1], ++gop[a[i]];
		for(long long j = 2; j * j <= a[i]; ++j){
			if(a[i] % j == 0){
				++gop[j];
				if(j * j < a[i]){
					++gop[a[i] / j];
				}
			}
		}
	}
	auto comb = [&](long long N, long long k){
		long long rv = 1;
		for(long long i = N; i >= N - k + 1; --i){
			rv *= i; rv %= MOD;
		}
		for(long long i = k; i >= 1; --i){
			rv *= (extgcd(i, MOD).first + MOD) % MOD; rv %= MOD;
		}
		return rv;
	};
	for(long long k = 1; k <= 7; ++k){
		vector<long long> dp((long long)3e5 + 4);
		for(long long i = (long long)3e5 - 1; i >= 0; --i){
			if(gop[i] >= k){
				dp[i] = comb(gop[i], k);
				for(long long j = i * 2; j <= (long long)3e5; j += i){
					dp[i] = (dp[i] - dp[j] + MOD) % MOD;
				}
			}
		}
		if(dp[1]){
			cout << k;
			return 0;
		}
	}
	cout << -1;
	return 0;
}