// Problem: Scuza
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1742/problem/E
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		vector<ll> b{0};
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b.push_back(b.back() + a[i]);
			if(i) a[i] = max(a[i], a[i-1]);
		}
		for(int k; q--;) {
			cin >> k;
			cout << b[upper_bound(all(a), k) - a.begin()] << ' ';
		}
		cout << '\n';
	});
	
}