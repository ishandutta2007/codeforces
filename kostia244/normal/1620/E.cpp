// Problem: E. Replace the Numbers
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/E
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
	//multitest([&](){});
	int n, t, x, y, sz = 0;
	cin >> n;
	map<int, vector<int>> vals;
	auto merge = [&](vector<int> &a, vector<int> &b) {
		if(a.size() < b.size())
			swap(a, b);
		for(auto i : b)
			a.push_back(i);
		b.clear();
	};
	for(; n--;) {
		cin >> t >> x;
		if(t == 1) {
			vals[x].push_back(sz++);
		} else {
			cin >> y;
			if(x != y)
			merge(vals[y], vals[x]);
		}
	}
	vector<int> a(sz);
	for(auto [x, ids] : vals) {
		for(auto i : ids) {
			a[i] = x;
		}
	}
	for(auto &i : a) {
		cout << i << " ";
	}cout << endl;
}