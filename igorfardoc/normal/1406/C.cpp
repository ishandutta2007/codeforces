#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
int n;
vector<pair<int, int>> ans;

int find1(int v, int p) {
	if(g[v].size() == 1) {
		ans.push_back({v, p});
		return v;
	}
	for(int u : g[v]) {
		if(u == p) continue;
		return find1(u, v);
	}
}

int dfs(int v, int p) {
	int sz = 1;
	for(int u : g[v]) {
		if(u == p) continue;
		sz += dfs(u, v);
	}
	if(n % 2 == 0 && sz == n / 2) {
		for(int u : g[v]) {
			if(u != p) {
				int v1 = find1(u, v);
				ans.push_back({p, v1});
				break;
			}
		}
	}
	return sz;
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
    int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	g.assign(n, vi(0));
    	for(int i = 0; i < n - 1; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	ans.resize(0);
    	dfs(0, -1);
    	if(ans.empty()) {
    		ans.push_back({0, g[0][0]});
    		ans.push_back({0, g[0][0]});
    	}
    	for(auto& el : ans) {
    		cout << el.first + 1 << ' ' << el.second + 1 << '\n';
    	}
    }
}