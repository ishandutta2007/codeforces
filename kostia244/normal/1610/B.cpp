// Problem: B.  
// Contest: Codeforces - Codeforces Global Round 17
// URL: https://codeforces.com/contest/1610/problem/B
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
		int ok = 1, pos = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] != a[n-1-i]) {
				ok = 0;
				pos = i;
			}
		}
		if(ok) {
			report(1);
			return;
		}
		auto check = [&](int x) {
			vector<int> b;
			for(auto i : a) if(i != x)
				b.push_back(i);
			auto c = b;
			reverse(all(c));
			return b==c;
		};
		report(check(a[pos])||check(a[n-1-pos]));
	});
	
}