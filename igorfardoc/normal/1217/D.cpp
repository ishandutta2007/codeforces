#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi ans;
int ans1 = 1;
vector<int> c;
vector<vector<pair<int, int>>> g;

void dfs(int v) {
	c[v] = 0;
	for(auto& el : g[v]) {
		int u = el.first;
		int id1 = el.second;
		if(c[u] == 1) {
			ans[id1] = 1;
			continue;
		}
		if(c[u] == 0) {
			ans[id1] = 2;
			ans1 = 2;
		} else {
			ans[id1] = 1;
			dfs(u);
		}
	}
	c[v] = 1;
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
    int n, m;
    cin >> n >> m;
    ans.resize(m);
    g.resize(n);
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back({u, i});
    }
    c.assign(n, -1);
    for(int i = 0; i < n; i++) {
    	if(c[i] == -1) {
    		dfs(i);
    	}
    }
    cout << ans1 << '\n';
    for(const auto& el : ans) {
    	cout << el << ' ';
    }
}