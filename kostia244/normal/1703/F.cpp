// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n), L, R;
		for(auto &i : a) cin >> i, i--;
		for(int i = 0; i < n; i++) {
			if(a[i] < i) L.push_back(i), R.push_back(a[i]);
		}
		ll ans = 0;
		sort(all(L));
		for(auto i : R)
			ans += lower_bound(all(L), i) - L.begin();
		cout << ans << '\n';
	});
	
}