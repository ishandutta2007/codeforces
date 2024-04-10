#include <bits/stdc++.h>
using namespace std;

int n, m, t, a, b;
vector <int> g[500100];
bool visited[500100];
int an[500100];
int pre[500100];

int dfs(int u, int y){
	int v, ans = 1;
	
	pre[u] = y;
	visited[u] = 1;
	
	for (int i = 0; i < g[u].size(); i++){
		v = g[u][i];
		if (!visited[v]){
			ans += dfs(v, y);
		}
	}
	return ans;
}


int main(){
	cin >> n >> m;
	while (m--){
		cin >> t;
		if (t == 0){
			continue;
		}
		cin >> a;
		for (int i = 1; i < t; i++){
			cin >> b;
			g[a].push_back(b);
			g[b].push_back(a);
			a = b;
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (!pre[i]){
			an[i] = dfs(i, i);
		}
		else{
			an[i] = an[pre[i]];
		}
		cout << an[i] << ' ';
	}
	
	return 0;
}