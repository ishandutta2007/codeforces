#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll dp[4010];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	dp[0] = 0;
	for(ll i = 1; i <= n; i++) {
		dp[i] = LLONG_MIN;
		if(i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
		if(i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
		if(i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
	}
	cout << dp[n] << endl;
}