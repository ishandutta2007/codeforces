//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn], t, d[maxn], e[maxn], a[maxn], ans;

bool vis[maxn], f;

vector<ll> g[maxn];

queue<ll> q;

ll bfs(ll x){
	ll v, u, b = 0;
	fill(vis, vis + n + 1, 0);
	d[x] = 0;
	vis[x] = 1;
	q.push(x);
	while(!q.empty()){
		v = q.front();
		if(c[v] == 0) c[v] = t;
		b = max(b, d[v]);
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(!vis[u]){
				vis[u] = 1;
				d[u] = d[v] + 1;
				q.push(u);
			}
			else{
				if(d[v] % 2 == d[u] % 2) f = 1;
			}
		}
	}
	return b;
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
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			t++;
		}
		a[c[i]] = max(a[c[i]], bfs(i));
	}
	
	if(f){
		cout << -1;
		return 0;
	}
	
	for(ll i = 1; i <= t; i++){
		ans += a[i];
	}
	
	cout << ans;
	
	return 0;
}