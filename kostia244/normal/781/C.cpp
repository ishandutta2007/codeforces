#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19;
vector<vector<int>> f;
int n, k, m, M;
void add(int x) {
	if(f.empty() || f.back().size() == M) f.push_back({});
	f.back().push_back(x);
}
vector<int> g[maxn];
int vis[maxn];
void dfs(int v) {
	vis[v] = 1;
	for(auto i : g[v]) if(!vis[i]) {
		add(v);
		dfs(i);
	}
	add(v);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	M = (2*n + k - 1)/k;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
		
	}
	dfs(1);
	while(f.size() < k) f.push_back({});
	for(auto &i : f) {
		if(i.empty()) cout << "1 1\n";
		else {
			cout << i.size() << " ";
			for(auto j : i) cout << j << " "; cout << endl;
		}
	}
}