// Problem: G. Subsequences Galore
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/G
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
const int mod = 998244353;
int n, dp[1<<23], sid[1<<23], f[1<<23], c[26][26];
inline __attribute__((always_inline)) void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(auto cv : s)
			c[i][cv-'a']++;
	}
	for(int i = 0; i < n; i++)
		sid[1<<i] = i+1;
	for(int i = 1; i < 1<<n; i++) {
		int j = i&(i-1);
		sid[i] = sid[j]+sid[i^j];
	}
	memset(dp, 1, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i < 1<<n; i++) {
		dp[i] = __builtin_popcount(i)%2 ? 1 : mod-1;
	}
	for(int ch = 0; ch < 26; ch++) {
		for(int i = 0; i < 1<<n; i++)
			f[i] = 1<<30;
		for(int i = 0; i < n; i++)
			f[1<<i] = c[i][ch];
		for(int i = 1; i < 1<<n; i++) {
			int j = i&(i-1);
			f[i] = min(f[j], f[i^j]);
		}
		for(int i = 1; i < 1<<n; i++)
			dp[i] = dp[i]*1ll*(f[i]+1)%mod;
	}
	for(int j = 1; j < 1<<n; j*=2)
	for(int i = 0; i < 1<<n; i++)
		if(i&j)
			add(dp[i], dp[i^j]);
	ll ans = 0;
	for(int i = 0; i < 1<<n; i++) {
		ans ^= dp[i]*1ll*sid[i]*__builtin_popcount(i);
		// cout << i << " - " << dp[i] << " " << sid[i] << endl;
	}
	cout << ans << '\n';
}