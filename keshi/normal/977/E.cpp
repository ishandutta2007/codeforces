#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> g[200100], c;
int n, m, ans;
bool visited[200100], f;

void dfs(int v){
	int u;
	visited[v] = 1;
	c.pb(v);
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			dfs(u);
		}
	}
}

int main(){
	int u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			c.clear();
			dfs(i);
			f = 1;
			for(int j = 0; j < c.size(); j++){
				v = c[j];
				if(g[v].size() != 2){
					f = 0;
				}
			}
			ans += f;
		}
	}
	cout << ans;
	return 0;
}