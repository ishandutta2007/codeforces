// Problem: F1. Array Shuffling
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/F1
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
		vector<vector<int>> C(n+1);
		vector<int> c(n+1);
		set<array<int, 2>> A;
		vector<int> b(n);
		auto ins = [&](int x, int y) {
			auto it = A.lower_bound(array<int, 2>{x, -1});
			b[it->at(1)] = y;
			A.erase(it);
		};
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			A.insert({t, i});
			C[c[t]++].push_back(t);
		}
		vector<int> bb;
		for(auto &v : C) {
			sort(all(v));
			for(auto i : v)
				bb.push_back(i);
		}
		for(int i = 0; i < n; i++)
			ins(bb[i], bb[(i+1)%n]);
		for(auto i : b)
			cout << i << " "; cout << '\n';
	});
	
}