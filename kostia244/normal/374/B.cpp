// Problem: B. Inna and Nine
// Contest: Codeforces - Codeforces Round #220 (Div. 2)
// URL: https://codeforces.com/contest/374/problem/B?locale=en
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
string s;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> s;
	int n = s.size()+1;
	vector<pair<int, ll>> dp(n+1);
	dp[0] = {0, 1};
	auto merge = [&](auto x, auto y) {
		if(x.first == y.first) return pair{x.first, x.second+y.second};
		return max(x, y);
	};
	for(int i = 1; i <= n; i++) {
		dp[i] = {-69696969, 0};
		dp[i] = merge(dp[i], dp[i-1]);
		if(i>1 && (s[i-1]-'0'+s[i-2]-'0')==9)
			dp[i] = merge(dp[i], pair{dp[i-2].first+1, dp[i-2].second});
		// cout << i << " " << dp[i].first << " " << dp[i].second << endl;
	}
	cout << dp.back().second << '\n';
}