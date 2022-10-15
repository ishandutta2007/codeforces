#include "bits/stdc++.h"
using namespace std;

const int maxn = 4e6 + 88;

long long n, p;
long long dp[maxn], pre[maxn];

int main(){
	cin >> n >> p;
	const long long m = p;

	dp[1] = 1;
	pre[1] = 1;

	for(long long i = 2; i <= n; ++i){
		dp[i] = pre[i - 1];
		dp[i] = (dp[i] % m) + ((i - (i / 2)) % m);
		dp[i] %= m;

		for(long long j = 2; j * j <= i; ++j){
			dp[i] = (dp[i] % m) + (dp[(i / j)] % m);
			dp[i] %= m;

			if((i / j) != j){
				long long upper = (i / j);
				long long lower = (i / (j + 1));

				dp[i] = (dp[i] % m) + (((upper - lower) % m) * dp[j]) % m;
				dp[i] %= m;
			}
		}

		pre[i] = (pre[i - 1] % m) + (dp[i] % m);
		pre[i] %= m;
	}

	cout << dp[n];
}