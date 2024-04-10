//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 5010;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int n, m, c[maxn], t;
int dis[maxn][maxn];
bool vis[maxn];
vector<int> vec, vv[maxn];
vector<int> g[maxn], gp[maxn];

void dfs(int v){
	vis[v] = 1;
	for(int u : g[v]){
		if(!vis[u]) dfs(u);
	}
	vec.pb(v);
	return;
}
void sfd(int v){
	vis[v] = 0;
	c[v] = t;
	vv[t].pb(v);
	for(int u : gp[v]){
		if(vis[u]) sfd(u);
	}
	return;
}
queue<int> q;
void bfs(int v){
	memset(dis[v], -1, sizeof dis[v]);
	dis[v][v] = 0;
	q.push(v);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int x : g[u]){
			if(dis[v][x] == -1){
				dis[v][x] = dis[v][u] + 1;
				q.push(x);
			}
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		gp[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		bfs(i);
		if(!vis[i]) dfs(i);
	}
	reverse(all(vec));
	for(int i : vec){
		if(vis[i]){
			sfd(i);
			t++;
		}
	}
	int ans = n;
	for(int i = 0; i < t; i++){
		bool ok = (Sz(vv[i]) == 1);
		for(int v : vv[i]){
			for(int u : g[v]){
				if(c[v] != c[u]) ok = 1;
			}
		}
		if(ok) continue;
		int x = n + 10;
		for(int v : vv[i]){
			for(int u : vv[i]){
				if(v != u) x = min(x, dis[v][u] + dis[u][v]);
			}
		}
		ans += 998 * x + 1;
	}
	cout << ans;
	
	return 0;
}