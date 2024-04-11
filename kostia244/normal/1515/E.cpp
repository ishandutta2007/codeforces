// Problem: E. Phoenix and Computers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int n, mod;
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r=r*1ll*a%mod;
		a =a*1ll*a%mod;
		p>>=1;
	}
	return r;
}
int dp[404][404], p2[404], f[404], pf[404];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> mod;
	p2[0] = f[0] = 1;
	for(int i = 1; i < 404; i++) {
		p2[i] = (p2[i-1]+p2[i-1])%mod;
		f[i] = f[i-1]*1ll*i%mod;
		pf[i] = p2[i-1]*1ll*bp(f[i], mod-2)%mod;
	}
	dp[0][0] = 1;
	for(int p = 0; p < n; p++) {
		for(int c = 0; c < n; c++) {
			int l = n-p;
			dp[p+l][c+l] = (dp[p+l][c+l] + dp[p][c]*1ll*pf[l])%mod;
			for(l = 0; p+l+1 < n; l++) {
				dp[p+l+1][c+l] = (dp[p+l+1][c+l] + dp[p][c]*1ll*pf[l])%mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = (ans + dp[n][i]*1ll*f[i])%mod;
	}
	cout << ans << '\n';
}