//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll lg = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, h[maxn], st[maxn], ft[maxn], t, vis[maxn], fen[maxn], par[maxn][lg];
vector<ll> g[maxn];

void upd(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}
ll getc(ll v){
	return get(ft[v] - 1) - get(st[v] - 1);
}

void dfs(ll v){
	vis[v] = 1;
	st[v] = t++;
	for(ll i = 1; i < lg; i++){
		if(h[v] >= (1 << i)) par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for(ll u : g[v]){
		if(vis[u]) continue;
		par[u][0] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
	ft[v] = t;
	return;
}

ll lca(ll v, ll u){
	if(h[v] < h[u]) swap(v, u);
	ll x = h[v] - h[u];
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) v = par[v][i];
	}
	for(ll i = lg; i--;){
		if(h[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	if(v != u) v = par[v][0];
	return v;
}

set<pll> b;

ll cal(ll v){
	if(b.empty()){
		return 1;
	}
	ll u = lca(b.begin() -> S, b.rbegin() -> S);
	if(!(st[u] <= st[v] && st[v] < ft[u])) return h[v] + h[u] - 2 * h[lca(v, u)];
	if(getc(v)){
		return 0;
	}
	ll x = h[v] + 1;
	for(ll i = lg; i--;){
		if((1 << i) > h[v]) continue;
		if(!getc(par[v][i])) v = par[v][i];
	}
	return x - h[v];
}
void add(ll v){
	b.insert(Mp(st[v], v));
	upd(st[v], 1);
	return;
}
void rem(ll v){
	b.erase(Mp(st[v], v));
	upd(st[v], -1);
	return;
}

int main(){
    fast_io;
    
    cin >> n >> k;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	dfs(1);
	ll r = 1, s = 0, ans = 0;
	for(ll i = 1; i <= n; i++){
		while(r <= n && s + cal(r) <= k){
			s += cal(r);
			add(r++);			
		}
		ans = max(ans, r - i);
		rem(i);
		s -= cal(i);
	}
	cout << ans;
 
    return 0;
}