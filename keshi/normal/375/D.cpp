//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn], ans[maxn];
bool vis[maxn];
vector<ll> g[maxn];
vector<pll> q[maxn];
map<ll, ll> s[maxn], fen[maxn];

void upd(ll id, ll x, ll y){
	if(x == 0) return;
	for(; x < maxn; x += x & -x){
		fen[id][x] += y;
	}
	return;
}

ll get(ll id, ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += fen[id][x];
	}
	return y;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	s[v][c[v]]++;
	upd(v, 1, 1);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		dfs(u);
		if(s[u].size() > s[v].size()) s[u].swap(s[v]), fen[u].swap(fen[v]);
		for(map<ll, ll>::iterator it = s[u].begin(); it != s[u].end(); it++){
			upd(v, s[v][it -> F], -1);
			s[v][it -> F] += it -> S;
			upd(v, s[v][it -> F], 1);
		}
		s[u].clear();
		fen[u].clear();
	}
	for(ll i = 0; i < q[v].size(); i++){
		ans[q[v][i].S] = get(v, maxn - 1) - get(v, q[v][i].F - 1);
	}
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		q[v].pb(Mp(u, i));
	}
	
	dfs(1);
	
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}