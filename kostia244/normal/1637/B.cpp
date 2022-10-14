// Problem: B. MEX  
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/B
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
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		ll cur = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			cur = 0;
			for(int j = i; j < n; j++) {
				cur += 1+(a[j]==0);
				ans += cur;
			}
		}
		cout << ans << '\n';
	});
	
}