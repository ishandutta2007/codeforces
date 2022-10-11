//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn], cost[maxn], d, par[maxn], t[maxn], des;

bool vis[maxn], f;

vector<pll> g[maxn];

vector<ll> q1, q2, ans;

queue<ll> q;

string s;

void dfs(ll v){
	ll u, c;
	vis[v] = 1;
	if(des > t[v]){
		des = t[v];
		q1.clear();
	}
	if(des == t[v]){
		q1.pb(v);
	}
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(c == 0 && !vis[u]){
			par[u] = v;
			dfs(u);
		}
	}
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		g[u].pb({v, c});
		g[v].pb({u, c});
	}
	
	q.push(0);
	vis[0] = 1;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			if(!vis[u]){
				vis[u] = 1;
				t[u] = t[v] + 1;
				q.push(u);
			}
		}
	}
	fill(vis, vis + n, 0);
	des = inf;
	
	q.push(n - 1);
	vis[n - 1] = 1;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(des > t[v]){
			des = t[v];
			q1.clear();
		}
		if(des == t[v]){
			q1.pb(v);
		}
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(c == 0 && !vis[u]){
				par[u] = v;
				vis[u] = 1;
				q.push(u);
			}
		}
	}
	
	while(!vis[0]){
		d = 10;
		for(ll i = 0; i < q1.size(); i++){
			v = q1[i];
			for(ll j = 0; j < g[v].size(); j++){
				u = g[v][j].F;
				c = g[v][j].S;
				if(!vis[u] && t[u] + dis[v] + 1 == des){
					vis[u] = 1;
					dis[u] = dis[v] + 1;
					cost[u] = 10;
					q2.pb(u);
				}
				if(dis[u] == dis[v] + 1 && cost[u] > c){
					cost[u] = c;
					d = min(d, c);
					par[u] = v;
				}
			}
		}
		q1.clear();
		for(ll i = 0; i < q2.size(); i++){
			u = q2[i];
			if(cost[u] == d){
				q1.pb(u);
			}
		}
		q2.clear();
	}
	
	v = 0;
	while(v != n - 1){
		s += char('0' + cost[v]);
		ans.pb(v);
		v = par[v];
	}
	ans.pb(n - 1);
	reverse(s.begin(), s.end());
	for(ll i = 0; i < s.size(); i++){
		if(f ||i + 1 == s.size() || s[i] != '0'){
			cout << s[i];
			f = 1;
		}
	}
	cout << endl << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}