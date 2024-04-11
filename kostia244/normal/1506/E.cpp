// Problem: E. Restoring the Permutation
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/E
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
		vector<int> q(n);
		vector<int> p(n, -1);
		set<int> have;
		for(auto &i : q) cin >> i;
		for(int i = 0; i < n; i++) {
			have.insert(i+1);
			if(!i || (q[i] != q[i-1])) {
				p[i] = q[i];
			}
		}
		for(auto i : q) {
			if(have.count(i)) have.erase(i);
		}
		auto h = have;
		auto lo = p;
		int cur = -1;
		for(auto &i : lo) {
			cur = max(cur, i);
			if(i == -1) {
				i = *h.begin();
				h.erase(h.begin());
			}
			cout << i << " ";
		}cout << '\n';
		auto hi = p;
		h = have;
		cur = -1;
		for(auto &i : hi) {
			cur = max(cur, i);
			if(i == -1) {
				auto it = h.upper_bound(cur);
				assert(it != h.begin()); --it;
				i = *it;
				h.erase(it);
			}
			cout << i << " ";
		}cout << '\n';
	});
	
}