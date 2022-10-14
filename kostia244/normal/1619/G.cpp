// Problem: G. Unusual Minesweeper
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/G
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
	multitest([&](){
		int n, m;
		cin >> n >> m;
		dsu d(n);
		map<int, vector<array<int, 2>>> xv, yv;
		vector<int> t(n);
		for(int x, y, i = 0; i < n; i++) {
			cin >> x >> y >> t[i];
			xv[x].push_back({y, i});
			yv[y].push_back({x, i});
		}
		auto merge = [&](vector<array<int, 2>> &a) {
			sort(all(a));
			for(int i = 1; i < a.size(); i++)
				if(a[i][0]-a[i-1][0] <= m)
					d.join(a[i][1], a[i-1][1]);
		};
		for(auto &[_, v] : xv) 
			merge(v);
		for(auto &[_, v] : yv) 
			merge(v);
		for(int i = 0; i < n; i++)
			t[d.find(i)] = min(t[i], t[d.find(i)]);
		vector<int> tops;
		for(int i = 0; i < n; i++)
			if(d.find(i) == i)
				tops.push_back(t[i]);
		tops.push_back(0);
		sort(all(tops));
		int ans = 1<<30;
		for(int i = 0; i < tops.size(); i++) {
			int T = tops[i];
			ans = min(ans, max(T, int(tops.size())-i-2));
		}
		cout << ans << '\n';
	});
	
}