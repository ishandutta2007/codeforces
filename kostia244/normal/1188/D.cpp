// Problem: D. Make Equal
// Contest: Codeforces - Codeforces Round #572 (Div. 1)
// URL: https://codeforces.com/contest/1188/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
int main() {
	cin.tie(0)->sync_with_stdio(0);
	const ll inf = 1ll<<60;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	ll M = *max_element(all(a));
	for(auto &i : a) i = M-i;
	vector<int> ord(n), pos(n);
	iota(all(ord), 0);
	pos = ord;
	vector<ll> dp(n+1, inf);
	dp[0] = 0;
	auto get = [&](int i, int b) {
		return (a[i]>>b)&1;
	};
	for(int b = 0; b < 60; b++) {
		array<int, 2> c{0, 0};
		vector<array<int, 2>> trans(n);
		for(auto i : ord) {
			c[get(i, b)]++;
			trans[i] = c;
		}
		for(int i = 0; i < n; i++) {
			if(get(i, b))
				pos[i] = trans[i][1]-1;
			else
				pos[i] = c[1]+trans[i][0]-1;
		}
		vector<ll> ndp(n+1, inf);
		for(int i = 0; i <= n; i++) {
			auto [x, y] = i?trans[ord[i-1]]:array<int, 2>{0, 0};
			int xcnt = (c[1]-y)+x;//XOR
			//don't add, AND
			ndp[y] = min(ndp[y], dp[i]+xcnt);
			//add, OR
			ndp[c[1]+x] = min(ndp[c[1]+x], dp[i]+n-xcnt);
		}
		for(int i = 0; i < n; i++)
			ord[pos[i]] = i;
		dp = ndp;
	}	
	cout << dp[0] << '\n';
}