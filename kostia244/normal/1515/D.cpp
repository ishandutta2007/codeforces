// Problem: D. Phoenix and Socks
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/D
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
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> cl(n), cr(n);
		for(int t, i = 0; i < n; i++) {
			cin >> t;t--;
			(i < l ? cl : cr)[t]++;
		}
		if(l < r) {
			swap(l, r);
			for(int i = 0; i < n; i++) swap(cl[i], cr[i]);
		}
		int pairs = 0, op = 0;
		for(int i = 0; i < n; i++) {
			while(l > r && cl[i] > cr[i] && abs(cl[i]-cr[i])>1) {
				cl[i]--, cr[i]++;
				l--, r++;
				op++;
			}
		}
		for(int i = 0; i < n; i++) {
			while(l > r && cl[i] > cr[i]) {
				cl[i]--, cr[i]++;
				l--, r++;
				op++;
			}
			pairs += min(cl[i], cr[i]);
		}
		assert(l == r);
		cout << n/2 - pairs + op << '\n';
		
	});
	
}