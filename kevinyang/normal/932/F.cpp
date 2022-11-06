#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)2e18;
struct Line {
	mutable int k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(int x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const int inf = LLONG_MAX;
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int mxn = 100005;
vector<int>a(mxn);
vector<int>b(mxn);
int n;
vector<int>dp(mxn);
vector<vector<int>>adj(mxn);
LineContainer dfs(int u, int p){
	LineContainer t;
	int children = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		children++;
	}
	if(children==0){
		t.add(-b[u],0);
		return t;
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		LineContainer val = dfs(nxt,u);
		if(t.size()<val.size()){
			swap(t,val);
		}
		for(auto nxt: val){
			t.add(nxt.k,nxt.m);
		}
	}
	dp[u] = -t.query(a[u]);
	t.add(-b[u],-dp[u]);
	return t;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> b[i];
	}
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	for(int i = 1; i<=n; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";
	return 0;
}