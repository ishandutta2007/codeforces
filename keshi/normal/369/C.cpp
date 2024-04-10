#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int, int>
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 1e5 + 100;
int n;
bool visited[MAXN];
map< pii, bool > problem;
vector< int > g[MAXN], ans;

bool dfs(int v, bool c){
	int u;
	bool f = 0;
	visited[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			if(dfs(u, problem[{v, u}])){
				f = 1;
			}
		}
	}
	if(c == 1 && f == 0){
		ans.pb(v);
	}
	if(c){
		f = 1;
	}
	return f;
}

int main(){
	fast_io;
	int u, v, c;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> c;
		g[u].pb(v);
		g[v].pb(u);
		if(c == 2){
			problem[{u, v}] = 1;
			problem[{v, u}] = 1;
		}
	}
	dfs(1, 0);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
	return 0;
}