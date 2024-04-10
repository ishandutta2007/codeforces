#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

int n, q, dis, far, ans;
vector<int> g[MAXN];
bool visited[MAXN];

void dfs(int v, int d){
	int u;
	visited[v] = 1;
	if(d > dis){
		dis = d;
		far = v;
	}
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			dfs(u, d + 1);
		}
	}
	return;
}

int main(){
	file_io;
	fast_io;
	int u, v;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		for(int i = 0; i < n - 1; i++){
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		fill(visited, visited + n + 1, 0);
		dis = -1;
		dfs(1, 0);
		fill(visited, visited + n + 1, 0);
		dis = -1;
		dfs(far, 0);
		ans += dis;
	}
	cout << ans;
	
	return 0;
}