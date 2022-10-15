#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 6;

int cur = 0;
bool pass[maxn];
vector<vector<int>> g;
map<int, vector<int>> com;

void dfs(int u){
	if(pass[u]) return;
	pass[u] = 1;
	com[cur].push_back(u);
	for(int v : g[u]) dfs(v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	g.resize(n + 1);

	while(m--){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i) if(!pass[i]){
		dfs(i);
		++cur;
	}

	int ans = 0;
	for(auto i : com){
		bool ok = 1;
		for(int j : i.second) ok &= (g[j].size() == 2);
		ans += ok;
	}

	cout << ans;
}