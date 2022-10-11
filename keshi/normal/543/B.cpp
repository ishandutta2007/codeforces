//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn][maxn], s1, t1, l1, s2, t2, l2, ans;

bool vis[maxn];

vector<ll> g[maxn];

void bfs(ll x){
	ll v, u;
	for(ll i = 1; i <= n; i++){
		dis[x][i] = inf;
	}
	queue<ll> q;
	q.push(x);
	dis[x][x] = 0;
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(dis[x][u] > dis[x][v] + 1){
				dis[x][u] = dis[x][v] + 1;
				q.push(u);
			}
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	
	for(ll i = 1; i <= n; i++){
		bfs(i);
	}
	
	if(dis[s1][t1] > l1 || dis[s2][t2] > l2){
		cout << -1;
		return 0;
	}
	
	ans = dis[s1][t1] + dis[s2][t2];
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(dis[i][s1] + dis[i][j] + dis[j][t1] <= l1 && dis[i][s2] + dis[i][j] + dis[j][t2] <= l2) ans = min(ans, dis[i][s1] + dis[i][s2] + dis[j][t1] + dis[j][t2] + dis[i][j]);
			if(dis[i][s1] + dis[i][j] + dis[j][t1] <= l1 && dis[i][t2] + dis[i][j] + dis[j][s2] <= l2) ans = min(ans, dis[i][s1] + dis[i][t2] + dis[j][t1] + dis[j][s2] + dis[i][j]);
		}
	}
	
	cout << m - ans;
	
	return 0;
}