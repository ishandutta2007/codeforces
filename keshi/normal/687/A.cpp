#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
bool color[MAXN], visited[MAXN], f;
int n, m, cnt;
vector< int > g[MAXN];
void dfs(int v, bool c){
	int u;
	visited[v] = 1;
	color[v] = c;
	if(c){
		cnt++;
	}
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			dfs(u, !c);
		}
		else{
			if(color[v] == color[u]){
				f = 1;
				return;
			}
		}
	}
	return;
}
int main(){
	int u, v;
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, 1);
		}
	}
	if(f){
		cout << -1;
		return 0;
	}
	cout << cnt << endl;
	for(int i = 1; i <= n; i++){
		if(color[i]){
			cout << i << ' ';
		}
	}
	cout << endl << n - cnt << endl;
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			cout << i << ' ';
		}
	}
	return 0;
}