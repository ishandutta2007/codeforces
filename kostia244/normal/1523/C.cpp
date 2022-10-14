// Problem: C. Compression and Expansion
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/C
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
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		vector<array<int, 2>> c = {{1, 0}};
		cout << "1\n";
		int fi = 1;
		vector<decltype(c)> d = {c};
		for(auto i : a) {
			if(fi-- == 1) continue;
			if(i == 1) {
				while(d.back().back()[1]&1) d.pop_back();
				c = d.back();
				c.back()[1] |= 1;
				d.back() = c;
			} else {
				while(d.back().back()[0] != i-1 || (d.back().back()[1]&2)) d.pop_back();
				c = d.back();
				c.back()[1] |= 2;
				d.back() = c;
				c.pop_back();
			}
			c.push_back({i, 0});
			d.push_back(c);
			int ass = 0;
			for(auto i : c) cout << i[0] << ".\n"[++ass == c.size()];
		}
		
	});
	
}