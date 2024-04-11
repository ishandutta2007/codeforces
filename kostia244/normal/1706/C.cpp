// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/C
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
		vector<ll> A{0}, B{0};
		for(int i = 1; i+1 < n; i += 2) {
			A.push_back(A.back() + max(0, max(a[i-1], a[i+1]) + 1 - a[i]));
		}
		reverse(all(a));
		for(int i = 1; i+1 < n; i += 2) {
			B.push_back(B.back() + max(0, max(a[i-1], a[i+1]) + 1 - a[i]));
		}
		n = (n-1)/2;
		ll ans = min(A.back(), B.back());
		for(int i = 0; i <= n; i++) ans = min(ans, A[i]+B[n-i]);
		cout << ans << '\n';
	});
	
}