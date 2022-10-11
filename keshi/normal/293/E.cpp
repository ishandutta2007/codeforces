//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, L, W, p[maxn], w[maxn], ans, sz[maxn], hide[maxn], h[maxn], d[maxn], fen[maxn];
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

void dfs(ll v, ll par = -1){
	sz[v] = 1;
	for(ll u : g[v]){
		if(hide[u] || u == par) continue;
		h[u] = h[v] + (u > v ? w[u] : w[v]);
		d[u] = d[v] + 1;
		dfs(u, v);
		sz[v] += sz[u];
	}
	return;
}
ll centroid(ll v, ll s, ll par = -1){
	for(ll u : g[v]){
		if(!hide[u] && u != par && sz[u] * 2 > s) return centroid(u, s, v);
	}
	return v;
}

vector<pair<pll, ll> > vec;

void dfs2(ll v, ll par = -1){
	vec.pb(Mp(Mp(h[v], 0), d[v]));
	vec.pb(Mp(Mp(W - h[v], 1), L - d[v]));
	for(ll u : g[v]){
		if(!hide[u] && u != par){
			dfs2(u, v);
		}
	}
	return;
}

ll cal(ll v){
	vec.clear();
	dfs2(v);
	sort(all(vec));
	ll s = 0;
	for(auto i : vec){
		if(!i.F.S){
			upd(i.S, 1);
		}
		else{
			s += get(i.S);
		}
	}
	for(auto i : vec){
		if(!i.F.S){
			upd(i.S, -1);
		}
	}
	return s;
}

void solve(ll v){
	d[v] = h[v] = 0;
	dfs(v);
	v = centroid(v, sz[v]);
	hide[v] = 1;
	d[v] = h[v] = 0;
	dfs(v);
	ans += cal(v) - 1;
	for(ll u : g[v]){
		if(!hide[u]) ans -= cal(u);
	}
	for(ll u : g[v]){
		if(!hide[u]) solve(u);
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> L >> W;
    for(ll i = 2; i <= n; i++){
    	cin >> p[i] >> w[i];
    	g[p[i]].pb(i);
    	g[i].pb(p[i]);
	}
	solve(1);
	cout << ans / 2;
 
    return 0;
}