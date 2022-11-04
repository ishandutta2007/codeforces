#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g, gr, g1;
vector<bool> used;
vvi components;
vi cmp;
vi order;

void dfs1(int v) {
	used[v] = true;
	for(int u : g[v]) {
		if(used[u]) continue;
		dfs1(u);
	}
	order.push_back(v);
}

void dfs2(int v) {
	components[components.size() - 1].push_back(v);
	cmp[v] = components.size() - 1;
	//cout << v << ' ' << components.size() - 1 << endl;
	used[v] = true;
	for(int u : gr[v]) {
		if(used[u]) continue;
		dfs2(u);
	}
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
    	gr.assign(n, vi(0));
    	used.assign(n, false);
    	for(int i = 0; i < m; i++) {
    		int v, u;
    		cin >> v >> u;
    		if(v == u) continue;
    		--v;
    		--u;
    		g[v].push_back(u);
    		gr[u].push_back(v);
    	}
    	components.clear();
    	cmp.resize(n);
    	order.clear();
    	for(int i = 0; i < n; i++) {
    		if(used[i]) continue;
    		dfs1(i);
    	}
    	used.assign(n, false);
    	for(int i = n - 1; i >= 0; i--) {
    		int v = order[i];
    		if(used[v]) continue;
    		components.push_back({});
    		dfs2(v);
    	}
    	if(components.size() == 1) {
    		cout << "No\n";
    		continue;
    	}
    	g1.assign(components.size(), vi(0));
    	for(int i = 0; i < n; i++) {
    		for(int u : g[i]) {
    			if(cmp[u] == cmp[i]) continue;
    			g1[cmp[i]].push_back(cmp[u]);
    		}
    	}
    	int now = 0;
    	while(g1[now].size() > 0) {
    		now = g1[now][0];
    	}
    	cout << "Yes\n";
    	cout << components[now].size() << ' ' << n - components[now].size() << '\n';
    	for(int u : components[now]) {
    		cout << u + 1 << ' ';
    	}
    	cout << '\n';
    	for(int i = 0; i < n; i++) {
    		if(cmp[i] != now) {
    			cout << i + 1 << ' ';
    		}
    	}
    	cout << '\n';
    }
}