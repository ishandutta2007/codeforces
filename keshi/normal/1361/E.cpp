//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

mt19937 rng(time(0));

ll t, n, m, a[maxn], d[maxn];
pll mn[maxn];
bool vis[maxn], val[maxn], f;
vector<ll> g[maxn], gr[maxn], vec;

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) d[u] = d[v] + 1, dfs(u);
	}
	for(ll i = 0; i < gr[v].size(); i++){
		u = gr[v][i];
		if(!vis[u] || d[u] < d[v] - 1) f = 0;
	}
	return;
}
void sfd(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			sfd(u);
			if(mn[v].F >= mn[u].F) mn[v] = Mp(mn[u].F, mn[v].F);
			else if(mn[v].S >= mn[u].F) mn[v] = Mp(mn[v].F, mn[u].F);
			if(mn[v].F >= mn[u].S) mn[v] = Mp(mn[u].S, mn[v].F);
			else if(mn[v].S >= mn[u].S) mn[v] = Mp(mn[v].F, mn[u].S);
		}
		else{
			if(mn[v].F >= d[u]) mn[v] = Mp(d[u], mn[v].F);
			else if(mn[v].S >= d[u]) mn[v] = Mp(mn[v].F, d[u]);
		}
	}
	return;
}
void solve(ll v){
	ll u;
	vis[v] = 1;
	vec.pb(v);
	if(mn[v].S < d[v]) val[v] = 1;
	else if(val[vec[mn[v].F]]) val[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) solve(u);
	}
	vec.pop_back();
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(n == 1){
			cout << "1\n";
			continue;
		}
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			gr[i].clear();
			a[i] = i;
		}
		for(ll i = 0; i < m; i++){
			cin >> v >> u;
			g[v].pb(u);
			gr[u].pb(v);
		}
		shuffle(a + 1, a + n + 1, rng);
		for(ll i = 1; i <= min(n, 50); i++){
			v = a[i];
			f = 1;
			fill(vis + 1, vis + n + 1, 0);
			d[v] = 0;
			dfs(v);
			if(f) break;
		}
		if(!f){
			cout << "-1\n";
			continue;
		}
		d[v] = 0;
		fill(vis + 1, vis + n + 1, 0);
		fill(val + 1, val + n + 1, 0);
		fill(mn + 1, mn + n + 1, Mp(inf, inf));
		sfd(v);
		fill(vis + 1, vis + n + 1, 0);
		vec.clear();
		solve(v);
		ll c = 0;
		for(ll i = 1; i <= n; i++){
			if(!val[i]) c++;
		}
		if(5 * c < n){
			cout << "-1\n";
			continue;
		}
		for(ll i = 1; i <= n; i++){
			if(!val[i]) cout << i << " ";
		}
		cout << '\n';
	}
	
	return 0;
}