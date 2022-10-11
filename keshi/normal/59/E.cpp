//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 3100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, v, u, x, dis[maxn][maxn], par[maxn][maxn];

vector<ll> g[maxn], h[maxn][maxn], ans;

queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 0; i < k; i++){
		cin >> v >> u >> x;
		h[v][u].pb(x);
	}
	g[n].pb(n);
	
	for(ll i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
		for(ll j = 1; j <= n; j++){
			sort(h[i][j].begin(), h[i][j].end());
			dis[i][j] = inf;
		}
	}
	
	dis[0][1] = 0;
	q.push({0, 1});
	
	while(!q.empty()){
		v = q.front().F;
		u = q.front().S;
		q.pop();
		ll p = 0;
		for(ll i = 0; i < g[u].size(); i++){
			x = g[u][i];
			if(p < h[v][u].size() && h[v][u][p] == x){
				p++;
				continue;
			}
			if(dis[u][x] > dis[v][u] + 1){
				dis[u][x] = dis[v][u] + 1;
				par[u][x] = v;
				q.push({u, x});
			}
		}
	}
	
	if(dis[n][n] >= inf){
		cout << -1;
		return 0;
	}
	
	cout << dis[n][n] - 1 << '\n';
	
	v = n;
	u = n;
	while(v){
		ans.pb(v);
		x = u;
		u = v;
		v = par[v][x];
	}
	
	for(ll i = ans.size() - 1; i > -1; i--){
		cout << ans[i] << " ";
	}
	
	return 0;
}