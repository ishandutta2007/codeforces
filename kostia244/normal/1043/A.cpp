// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/A
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	#define int ll
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	auto can = [&](int k) -> bool {
		for(auto i : a) if(k-i < 0) return 0;
		ll A = 0, B = 0;
		for(auto i : a) {
			A += i;
			B += k-i;
		}
		return B>A;
	};
	ll ans = -1;
	for(ll z = 1ll<<30; z>>=1;)
		ans += z*!can(ans+z);
	cout << ans+1 << '\n';
}