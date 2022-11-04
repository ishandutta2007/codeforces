#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vector<pair<int, int>> ans;
vi sz;
void dfs1(int v, int p) {
	sz[v] = 1;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs1(u, v);
		sz[v] += sz[u];
	}
}

void dfs(int v, int p, int start) {
	if(g[v].size() == 1 && p != -1) {
		ans[v].first = start;
		ans[v].second = start + 1;
		return;
	}
	int now = start;
	int end = start + sz[v] * 2 - 1;
	ans[v].second = end;
	--end;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v, now);
		ans[u].second = end;
		--end;
		now += sz[u] * 2 - 1;
	}
	ans[v].first = end;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    sz.resize(n);
    dfs1(0, -1);
    dfs(0, -1, 1);
    for(int i = 0; i < n; i++) {
    	cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}