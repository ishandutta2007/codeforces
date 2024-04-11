// Problem: A. Directional Increase
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/A
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
	cout << (ok?"Yes":"No") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		while(a.size() && !a.back())
			a.pop_back();
		ll ok = 1, s = 0;
		for(int i = 0; i+1 < a.size(); i++) {
			s += a[i];
			ok &= s > 0;
		}
		if(a.size()) s += a.back();
		ok &= s == 0;
		report(ok);
	});
	
}