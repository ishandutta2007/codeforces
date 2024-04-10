//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 15e4 + 100;
const ll mod = 998244353;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return c;
}

ll n, q, t, st[maxn], ft[maxn], vis[maxn], a[maxn], sz[maxn], np, fen[maxn], par[maxn], hv[maxn], pp[maxn];
bool ishv[maxn];
vector<ll> g[maxn];

void upd(ll x, ll y){
	if(y < 0) y += mod;
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
		if(fen[x] >= mod) fen[x] -= mod;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
		if(y >= mod) y -= mod;
	}
	return y;
}

void dfs(ll v){
	vis[v] = 1;
	st[v] = t++;
	sz[v] = 1;
	ll mx = 0;
	for(ll u : g[v]){
		if(vis[u]) continue;
		dfs(u);
		par[u] = v;
		sz[v] += sz[u];
		if(sz[u] > sz[mx]) mx = u;
	}
	ishv[hv[v] = mx] = 1;
	ft[v] = t;
	return;
}
void dfs2(ll v){
	if(ishv[v]) pp[v] = pp[par[v]];
	else pp[v] = v;
	for(ll u : g[v]){
		if(u == par[v]) continue;
		dfs2(u);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> q;
	np = pw(n, mod - 2);
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	ishv[1] = 1;
	dfs2(1);
	while(q--){
		ll t, v, x;
		cin >> t >> v;
		if(t == 1){
			cin >> x;
			a[v] += x;
			if(a[v] >= mod) a[v] -= mod;
			x = 1ll * x * np % mod;
			upd(-1, 1ll * x * sz[v] % mod);
			upd(st[v], -1ll * x * sz[v] % mod);
			upd(ft[v], 1ll * x * sz[v] % mod);
			ll u = hv[v];
			if(u == 0) continue;
			upd(st[u], 1ll * x * (n - sz[u]) % mod);
			upd(ft[u], -1ll * x * (n - sz[u]) % mod);
		}
		else{
			x = (get(st[v]) + a[v]) % mod;
			v = pp[v];
			while(v){
				x = (x + 1ll * a[par[v]] * (n - sz[v]) % mod * np) % mod;
				v = pp[par[v]];
			}
			cout << (x + mod) % mod << "\n";
		}
	}
	
	return 0;
}