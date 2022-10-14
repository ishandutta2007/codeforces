// Problem: F. Antennas
// Contest: Codeforces - SWERC 2021-2022 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1662/problem/F
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
const int inf = 1<<30;
struct seg {
	int n;
	vector<pair<int, int>> tree;
	vector<set<pair<int, int>>> ps;
	seg(int N) : n(N), tree(2*N, {-inf, -1}), ps(N) {}
	void upd(int i, int x, int del) {
		if(del) ps[i].erase(ps[i].find({x, i}));
		else ps[i].insert({x, i});
		tree[n+i] = ps[i].empty()?pair{-inf, -1}:*ps[i].rbegin();
		for(i += n; i/=2;)
			tree[i] = max(tree[2*i], tree[2*i+1]);
	}
	pair<int, int> get(int l, int r) {
		l = max(l, 0); r = min(r, n);
		pair<int, int> ans {-inf, -1};
		for(l += n, r += n; l < r; l/=2, r/=2) {
			if(l&1) ans = max(ans, tree[l++]);
			if(r&1) ans = max(ans, tree[--r]);
		}
		return ans;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> p(n), d(n);
		for(auto &i : p) cin >> i;
		seg A(n), B(n);
		for(int i = 0; i < n; i++) {
			A.upd(i, p[i]+i, 0);
			B.upd(i, p[i]-i, 0);
		};
		queue<int> q;
		auto add = [&](int i, int D) {
			A.upd(i, p[i]+i, 1);
			B.upd(i, p[i]-i, 1);
			q.push(i);
			d[i] = D;
		};
		add(a-1, 0);
		while(!q.empty()) {
			int v = q.front();
			// cout << v << " " << d[v] << endl;
			q.pop();
			auto [di, i] = A.get(0, n);
			for(auto [di, i] = A.get(v-p[v], v); di >= v;
				tie(di, i) = A.get(v-p[v], v)) {
				add(i, d[v]+1);
			}
			for(auto [di, i] = B.get(v, v+p[v]+1); di >= -v;
				tie(di, i) = B.get(v, v+p[v]+1)) {
				add(i, d[v]+1);
			}
		}
		cout << d[b-1] << '\n';
	});
	
}