#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vector<set<int>> g1;
vector<pair<int, int>> ans;
vi c;

bool dfs(int v) {
	c[v] = 1;
	for(int u : g[v]) {
		if(c[u] == 2) {
			continue;
		}
		if(c[u] == 1) {
			return false;
		}
		bool res = dfs(u);
		if(!res) {
			return false;
		}
	}
	c[v] = 2;
	for(int u : g1[v]) {
		ans.push_back({u, v});
		g1[u].erase(g1[u].find(v));
	}
	g1[v].clear();
	return true;
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
    	int n, m;
    	cin >> n >> m;
    	g.assign(n, vi(0));
    	g1.assign(n, set<int>());
    	ans.clear();
    	for(int i = 0; i < m; i++) {
    		int t, v, u;
    		cin >> t >> v >> u;
    		--v;
    		--u;
    		if(t == 0) {
    			g1[v].insert(u);
    			g1[u].insert(v);
    		} else {
    			g[v].push_back(u);
    			ans.push_back({v, u});
    		}
    	}
    	c.assign(n, 0);
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(c[i] == 0) {
    			ok = dfs(i);
    		}
    		if(!ok) {
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	for(int i = 0; i < m; i++) {
    		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    	}
    }
}