#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150000 + 100;

#define magic_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back

long long n, m, k, r;
vector<int> g[MAXN];
bool visited[MAXN];

void dfs(int v){
	int u;
	visited[v] = 1;
	k++;
	r += g[v].size();
	for(int i = 0 ; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			dfs(u);
		}
	}
}

int main(){
	magic_io;
	int u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			r = 0;
			k = 0;
			dfs(i);
			if(r != k * (k - 1)){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}