//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll tof = 450;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, st[maxn], ft[maxn], cnt[tof][maxn], a[maxn], b[maxn], t;
vector<ll> g[maxn];
vector<pll> h[maxn];
bool vis[maxn];
map<ll, bool> used[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dfs(u);
			h[v].pb(Mp(ft[u], u));
		}
	}
	ft[v] = t;
	return;
}

void upd(ll r, ll x){
	ll i = 0;
	while(i + tof < r){
		a[i / tof] += x;
		i += tof;
	}
	for(; i < r; i++){
		cnt[i / tof][b[i]]--;
		b[i] += x;
		cnt[i / tof][b[i]]++;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(ll i = 0; i * tof < n; i++){
		y += cnt[i][x - a[i]];
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(ll i = 0; i * tof < n; i++){
		cnt[i][0] = min(tof, n - i * tof);
	}
	dfs(1);
	t = 0;
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		if(st[v] > st[u]) swap(v, u);
		ll z = 1;
		if(used[v][u]) z = -1, t--;
		else t++;
		used[v][u] = !used[v][u];
		if(st[u] < ft[v]){
			ll p = lower_bound(h[v].begin(), h[v].end(), Mp(ft[u], -inf)) -> S;
			upd(n, z);
			upd(ft[p], -z);
			upd(st[p], z);
			upd(ft[u], z);
			upd(st[u], -z);
		}
		else{
			upd(ft[u], z);
			upd(st[u], -z);
			upd(ft[v], z);
			upd(st[v], -z);
		}
		cout << get(t) << '\n';
	}
	
	return 0;
}