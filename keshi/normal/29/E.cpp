//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 550;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn][maxn][2], v, u, f, x;

pll par[maxn][maxn][2];

queue<pair<pll, ll> > q;

vector<ll> v1, v2;

vector<ll> g[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			dis[i][j][0] = inf;
			dis[i][j][1] = inf;
		}
	}
	
	dis[1][n][0] = 0;
	q.push({{1, n}, 0});
	
	while(!q.empty()){
		v = q.front().F.F;
		u = q.front().F.S;
		f = q.front().S;
		q.pop();
		if(f){
			for(ll i = 0; i < g[u].size(); i++){
				x = g[u][i];
				if(dis[v][x][0] > dis[v][u][1] + 1){
					dis[v][x][0] = dis[v][u][1] + 1;
					par[v][x][0] = {v, u};
					q.push({{v, x}, 0});
				}
			}
		}
		else{
			if(v == u) continue;
			for(ll i = 0; i < g[v].size(); i++){
				x = g[v][i];
				if(dis[x][u][1] > dis[v][u][0] + 1){
					dis[x][u][1] = dis[v][u][0] + 1;
					par[x][u][1] = {v, u};
					q.push({{x, u}, 1});
				}
			}
		}
	}
	
	if(dis[n][1][0] >= inf){
		cout << -1;
		return 0;
	}
	
	cout << dis[n][1][0] / 2 << '\n';
	
	v = n;
	u = 1;
	f = 0;
	
	while(v){
		if(f == 0){
			v2.pb(v);
			v1.pb(u);
		}
		x = v;
		v = par[v][u][f].F;
		u = par[x][u][f].S;
		f = 1 - f;
	}
	
	for(ll i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	
	cout << '\n';
	
	for(ll i = 0; i < v2.size(); i++){
		cout << v2[i] << " ";
	}
	
	return 0;
}