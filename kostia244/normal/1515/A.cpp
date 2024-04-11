// Problem: A. Phoenix and Gold
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/A
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
		int n, w;
		cin >> n >> w;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int cur = 0;
		for(int i = 0; i < n; i++) {
			cur += a[i];
			if(cur == w) {
				if(i+1 < n)
					swap(a[i], a[i+1]);
				else {
					report(0);
					return;
				}
			}
		}
		report(1);
		for(auto i : a) cout << i << " "; cout << '\n';
	});
	
}