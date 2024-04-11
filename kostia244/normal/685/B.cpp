#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 3e5 + 10, mlg = 20, mod = 1e9 + 7;
int n, m;
vi g[maxn];
int centr[maxn], sz[maxn];
set<pi> t[maxn];
void dfs(int v) {
	sz[v] = 1;
	for(auto i : g[v]) {
		dfs(i);
		sz[v] += sz[i];
		if(t[i].size()>t[v].size()) swap(t[i], t[v]);
	}
	for(auto i : g[v]) {
		for(auto j : t[i])
			t[v].insert(j);
	}
	t[v].insert({sz[v], v});
	int X = sz[v]/2;
	while(sz[v]-t[v].begin()->first > X) t[v].erase(t[v].begin());
	centr[v] = t[v].begin()->second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int t, i = 2; i <= n; i++) {
		cin >> t;
		g[t].pb(i);
	}
	dfs(1);
	for(int t, i = 0; i < m; i++) {
		cin >> t;
		cout << centr[t] << '\n';
	}
	return 0;
}