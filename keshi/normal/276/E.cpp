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

ll n, q, r, h[maxn], p[maxn];

bool vis[maxn];

vector<ll> g[maxn], bit[maxn];

void dfs(ll v){
	ll u;
	bit[p[v]].pb(0);
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			h[u] = h[v] + 1;
			p[u] = p[v];
			dfs(u);
		}
	}
	return;
}

void upd(ll id, ll v, ll x){
	//cout << "# " << id << " " << v << " " << x << endl;
	for(ll i = max(1ll, v); i < bit[id].size(); i += i & -i){
		bit[id][i] += x;
	}
	return;
}

ll get(ll id, ll v){
	ll x = 0;
	for(ll i = v; i > 0; i -= i & -i){
		x += bit[id][i];
	}
	return x;
}

int main(){
	ll v, u, t, x, d;
	fast_io;
	
	cin >> n >> q;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 0; i <= n; i++){
		bit[0].pb(0);
	}
	
	vis[1] = 1;
	
	for(ll i = 0; i < g[1].size(); i++){
		u = g[1][i];
		h[u] = 1;
		p[u] = i + 1;
		bit[p[u]].pb(0);
		dfs(u);
	}
	
	while(q--){
		cin >> t;
		if(t == 0){
			cin >> v >> x >> d;
			if(v == 1){
				upd(0, 1, x);
				upd(0, d + 1, -x);
				r += x;
				continue;
			}
			upd(p[v], h[v] - d, x);
			upd(p[v], h[v] + d + 1, -x);
			upd(0, 1, x);
			upd(0, d - h[v] + 1, -x);
			upd(p[v], 1, -x);
			upd(p[v], d - h[v] + 1, x);
			if(h[v] <= d) r += x;
		}
		else{
			cin >> v;
			if(v == 1) cout << r << '\n';
			else cout << get(0, h[v]) + get(p[v], h[v]) << '\n';
		}
	}
	
	
	return 0;
}