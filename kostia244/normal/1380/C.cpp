#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	sort(begin(a), end(a), greater<>());
	vector<int> dp(n);
	for(int i = 0; i < n; i++) {
		ll jmp = (x+a[i]-1)/a[i];
		if(i) dp[i] = dp[i-1];
		if(i-jmp == -1) dp[i] = max(dp[i], 1);
		if(i-jmp >= 0) dp[i] = max(dp[i-jmp]+1, dp[i]);
	}
	cout << dp.back() << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}