// Problem: B. New Year Permutation
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/B
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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	dsu d(n);
	vector<int> p(n), res(n);
	vector<vector<int>> f(n), g(n);
	for(auto &i : p) cin >> i;
	char t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> t;
			if(t-'0') d.join(i, j);
		}
	}
	for(int i = 0; i < n; i++) {
		f[d.find(i)].push_back(p[i]);
		g[d.find(i)].push_back(i);
	}
	for(int i = 0; i < n; i++) if(d.find(i) == i) {
		sort(all(f[i]));
		for(int j = 0; j < f[i].size(); j++)
			res[g[i][j]] = f[i][j];
	}
	for(auto i : res) cout << i << " "; cout << '\n';
}