//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 420;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, h, t, r, dis[maxn][maxn], v, u, k, deg[maxn][maxn], dis2[maxn][maxn], ans, st[maxn][maxn];

bool vis[maxn][maxn], d;

pll a[maxn], b[maxn], w[maxn];

vector<pll> g[maxn][maxn], vec, go[maxn][maxn];

queue<pll> q;

set<pair<ll, pll> > s;

map<pll, bool> mp[maxn][maxn];

bool dfs(ll x, ll y){
	st[x][y] = 1;
	for(ll i = 0; i < go[x][y].size(); i++){
		if(st[go[x][y][i].F][go[x][y][i].S] == 1) return 1;
		if(st[go[x][y][i].F][go[x][y][i].S] == 0){
			if(dfs(go[x][y][i].F, go[x][y][i].S)) return 1;
		}
	}
	st[x][y] = 2;
	return 0;
}

int main(){
	fast_io;
	
	cin >> h >> t >> r;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F >> a[i].S;
	}
	
	cin >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> b[i].F >> b[i].S;
	}
	
	q.push({h, t});
	vis[h][t] = 1;
	
	while(!q.empty()){
		v = q.front().F;
		u = q.front().S;
		q.pop();
		vec.pb({v, u});
		if(v + u > r) continue;
		if(v == 0 && u == 0){
			cout << "Ivan\n" << dis[v][u];
			return 0;
		}
		for(ll i = 1; i <= min(v, n); i++){
			if(!vis[v - i + a[i].F][u + a[i].S]){
				vis[v - i + a[i].F][u + a[i].S] = 1;
				dis[v - i + a[i].F][u + a[i].S] = dis[v][u] + 1;
				q.push({v - i + a[i].F, u + a[i].S});
			}
			if(!mp[v][u][{v - i + a[i].F, u + a[i].S}]){
				g[v - i + a[i].F][u + a[i].S].pb({v, u});
				deg[v][u]++;
				mp[v][u][{v - i + a[i].F, u + a[i].S}] = 1;
				go[v][u].pb({v - i + a[i].F, u + a[i].S});
			}
		}
		for(ll i = 1; i <= min(u, m); i++){
			if(!vis[v + b[i].F][u - i + b[i].S]){
				vis[v + b[i].F][u - i + b[i].S] = 1;
				dis[v + b[i].F][u - i + b[i].S] = dis[v][u] + 1;
				q.push({v + b[i].F, u - i + b[i].S});
			}
			if(!mp[v][u][{v + b[i].F, u - i + b[i].S}]){
				g[v + b[i].F][u - i + b[i].S].pb({v, u});
				deg[v][u]++;
				mp[v][u][{v + b[i].F, u - i + b[i].S}] = 1;
				go[v][u].pb({v + b[i].F, u - i + b[i].S});
			}
		}
	}
	
	k = vec.size();
	
	if(dfs(h, t)){
		cout << "Draw";
		return 0;
	}
	
	for(ll i = 0; i < k; i++){
		v = vec[i].F;
		u = vec[i].S;
		s.insert({deg[v][u], {v, u}});
	}
	
	for(ll i = 0; i < k; i++){
		v = (s.begin() -> S).F;
		u = (s.begin() -> S).S;
		w[k - i - 1] = {v, u};
		s.erase(s.begin());
		for(ll j = 0; j < g[v][u].size(); j++){
			s.erase({deg[g[v][u][j].F][g[v][u][j].S], {g[v][u][j].F, g[v][u][j].S}});
			deg[g[v][u][j].F][g[v][u][j].S]--;
			s.insert({deg[g[v][u][j].F][g[v][u][j].S], {g[v][u][j].F, g[v][u][j].S}});
		}
	}
	
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			dis2[i][j] = -inf;
		}
	}
	
	dis2[h][t] = 0;
	
	cout << "Zmey" << endl;
	
	for(ll i = 0; i < k; i++){
		v = w[i].F;
		u = w[i].S;
		for(ll j = 0; j < g[v][u].size(); j++){
			dis2[v][u] = max(dis2[v][u], dis2[g[v][u][j].F][g[v][u][j].S] + 1);
		}
		if(v + u > r){
			ans = max(ans, dis2[v][u]);
		}
	}
	
	cout << ans;
	
	return 0;
}