// Problem: D. New Year's Problem
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/D
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
		int n, m;
		cin >> m >> n;
		vector<vector<int>> p(m, vector<int>(n));
		for(auto &i : p)
			for(auto &j : i)
				cin >> j;
		auto can = [&](int x) {
			vector<int> tot(n);
			for(auto &v : p) {
				for(int i = 0; i < n; i++)
					tot[i] += v[i] >= x; 
			}
			for(auto i : tot) if(!i) return 0;
			for(auto &v : p) {
				int bi = 0;
				for(int i = 0; i < n; i++)
					bi += v[i] >= x; 
				if(bi > 1) 
					return 1;
			}
			return 0;
		};
		int z = 0;
		for(int x = 1<<30; x>>=1;)
			z += can(x+z)*x;
		cout << z << '\n';
	});
	
}