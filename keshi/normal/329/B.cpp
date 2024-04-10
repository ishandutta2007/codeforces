//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn][maxn], ans;

bool vis[maxn][maxn];

pll s, e;

queue<pll> q;

string g[maxn];

bool val(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	bool f = vis[x][y];
	vis[x][y] = 1;
	return !f;
}

int main(){
	ll x, y;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> g[i];
		for(ll j = 0; j < m; j++){
			if(g[i][j] == 'E') e = {i, j};
			if(g[i][j] == 'S') s = {i, j};
			if(g[i][j] == 'T') vis[i][j] = 1;
		}
	}
	
	dis[s.F][s.S] = inf;
	dis[e.F][e.S] = 0;
	vis[e.F][e.S] = 1;
	q.push(e);
	
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if(dis[x][y] <= dis[s.F][s.S] && g[x][y] != 'E' && g[x][y] != 'S'){
			ans += ll(g[x][y] - '0');
		}
		if(val(x - 1, y)){
			dis[x - 1][y] = dis[x][y] + 1;
			q.push({x - 1, y});
		}
		if(val(x + 1, y)){
			dis[x + 1][y] = dis[x][y] + 1;
			q.push({x + 1, y});
		}
		if(val(x, y - 1)){
			dis[x][y - 1] = dis[x][y] + 1;
			q.push({x, y - 1});
		}
		if(val(x, y + 1)){
			dis[x][y + 1] = dis[x][y] + 1;
			q.push({x, y + 1});
		}
	}
	
	cout << ans;
	
	return 0;
}