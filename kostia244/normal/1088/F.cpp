// Problem: F. Ehab and a weird weight formula
// Contest: Codeforces - Codeforces Round #525 (Div. 2)
// URL: https://codeforces.com/contest/1088/problem/F
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
int n;
vector<vector<int>> g;
vector<int> a; 
ll ans = 0;
struct seg {
	int n;
	vector<int> tree;
	seg(int n = 0) : n(n), tree(2*n) {}
	void upd(int pos, int val) {
		for(tree[pos+=n]=val;pos/=2;)
			tree[pos] = min(tree[2*pos], tree[2*pos+1]);
	}
	int qry(int l, int r) {
		int ans = 1<<30;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
			if(l&1) ans = min(ans, tree[l++]);
			if(r&1) ans = min(ans, tree[--r]);
		}
		return ans;
	}
};
seg st;
int sz = 0, root;
void dfs(int v) {
	if(v != root) {
		ll cost = 1ll<<33;
		for(int l = 0; l < 20; l++) {
			cost = min(cost, a[v] + (l+1ll)*st.qry(max(0, sz-(1<<l)), sz));
		}
		ans += cost;
	}
	st.upd(sz++, a[v]);
	for(auto &i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		dfs(i);
	}
	sz--;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	a.resize(n);
	for(auto &i : a)
		cin >> i;
	g.resize(n);
	st = seg(n);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;f--,t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	root = min_element(all(a))-a.begin();
	dfs(root);
	cout << ans << '\n';
}