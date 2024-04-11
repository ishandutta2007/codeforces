// Problem: F. Equate Multisets
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/F
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
	multitest([&](){
		int n;
		cin >> n;
		vector<int> _a(n), _b(n);
		auto uh = [&](int x) { return x ? (x >> __builtin_ctz(x)) : 0; };
		for(auto &i : _a) cin >> i, i = uh(i);
		for(auto &i : _b) cin >> i, i = uh(i);
		auto cmp = [&](auto x, auto y) {
			return pair<int, int>{__builtin_popcount(x), x}
				 > pair<int, int>{__builtin_popcount(y), y};
		};
		multiset<int, decltype(cmp)> a(all(_a), cmp);
		multiset<int, decltype(cmp)> b(all(_b), cmp);
		while(!a.empty()) {
			int x = *a.begin();
			a.erase(a.begin());
			int bits = __builtin_popcount(x);
			while(__builtin_popcount(*b.begin()) > bits) {
				int y = *b.begin();
				b.erase(b.begin());
				y = uh(y/2);
				b.insert(y);
			}
			auto it = b.find(x);
			if(it == b.end()) {
				cout << "NO\n";
				return;
			}
			b.erase(it);
		}
		cout << "YES\n";
	});
	
}