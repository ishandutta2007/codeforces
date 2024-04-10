//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll lg = 18;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, t, ans, d[maxn], st[maxn], ft[maxn], seg[maxn], ps[maxn], p[lg][maxn];
bool vis[maxn];
vector<pll> g[maxn];
set<pll> b;

void dfs(ll v){
	ll u, w;
	vis[v] = 1;
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S;
		if(!vis[u]){
			d[u] = d[v] + 1;
			p[0][u] = v;
			ps[u] = ps[v] + w;
			dfs(u);
		}
	}
	ft[v] = t;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	return get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
ll par(ll v, ll x){
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) v = p[i][v];
	}
	return v;
}
ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	v = par(v, d[v] - d[u]);
	for(ll i = lg; i--;){
		if((d[v] >= (1ll << i)) && p[i][v] != p[i][u]) v = p[i][v], u = p[i][u];
	}
	if(v != u) v = p[0][v];
	return v;
}
ll cal(ll v){
	if(b.empty()) return 0;
	ll u = lca(b.begin() -> S, b.rbegin() -> S);
	if(st[u] > st[v] || st[v] >= ft[u]) return ps[v] + ps[u] - 2 * ps[lca(v, u)];
	ll l = 0, r = d[v], mid;
	if(get(1, 0, n, st[v], ft[v])) return 0;
	while(r - l > 1){
		mid = (l + r) / 2;
		u = par(v, mid);
		if(get(1, 0, n, st[u], ft[u])) r = mid;
		else l = mid;
	}
	return ps[v] - ps[par(v, r)];
}

int main(){
	ll v, u, w;
	fast_io;
	
	cin >> n;
	for(ll i = 1; i < n; i++){
		cin >> v >> u >> w;
		g[v].pb(Mp(u, w));
		g[u].pb(Mp(v, w));
	}
	dfs(1);
	for(ll j = 1; j < lg; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1ll << j)) p[j][i] = p[j - 1][p[j - 1][i]];
		}
	}
	cin >> q;
	for(ll i = 0; i < q; i++){
		char ch;
		cin >> ch;
		if(ch == '?'){
			cout << ans << '\n';
		}
		else if(ch == '+'){
			cin >> v;
			ans += cal(v);
			b.insert(Mp(st[v], v));
			upd(1, 0, n, st[v], st[v] + 1, 1);
		}
		else{
			cin >> v;
			b.erase(Mp(st[v], v));
			upd(1, 0, n, st[v], st[v] + 1, -1);
			ans -= cal(v);
		}
	}
	
	return 0;
}