#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second

int n, color[MAXN], ans;
bool visited[MAXN], vis[MAXN], f;
vector<int> g[MAXN];

bool dfs2(int v){
	int u;
	vis[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			if(!dfs2(u) || color[u] != color[v]){
				return 0;
			}
		}
	}
	return 1;
}

bool check(int v){
	f = 0;
	int u;
	fill(vis, vis + n + 10, 0);
	vis[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!dfs2(u)){
			return 0;
		}
	}
	return 1;
}

void dfs(int v){
	int u;
	visited[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		if(ans){
			return;
		}
		u = g[v][i];
		if(!visited[u]){
			if(color[u] != color[1]){
				if(check(v)){
					ans = v;
					return;
				}
				if(check(u)){
					ans = u;
					return;
				}
				ans = -1;
				return;
			}
			dfs(u);
		}
	}
	return;
}


int main(){
	int u, v;
	fast_io;
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	f = 1;
	
	dfs(1);
	
	if(f){
		ans = 1;
	}
	
	if(ans > 0){
		cout << "YES" << endl << ans;
	}
	else{ 
		cout << "NO";
	}
	return 0;
}