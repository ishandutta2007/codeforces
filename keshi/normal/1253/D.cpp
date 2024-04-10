//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, d[maxn], l[maxn], r[maxn], t, ans, c, cnt;

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	d[v] = t;
	l[t] = min(l[t], v);
	r[t] = max(r[t], v);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dfs(u);
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
	
	fill(l, l + maxn, inf);
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			t++;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(i == l[d[i]]){
			cnt++;
			c++;
		}
		if(i == r[d[i]]){
			c--;
		}
		if(c == 0){
			ans += cnt - 1;
			cnt = 0;
		}
	}
	
	cout << ans;
	
	return 0;
}