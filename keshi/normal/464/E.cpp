//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll maxm = 8e6;
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

struct node{
	ll h, x, lz;
	node(){
		h = 0;
		x = -1;
		lz = 1;
	}
};
ll n, m, ti, par[maxn], p2[maxn], lc[maxm], rc[maxm], p[maxn];
node seg[maxm];
vector<pll> g[maxn];
bool vis[maxn];

void fix(ll id, ll e){
	if(seg[id].lz == 0) return;
	seg[id].lz = 0;
	seg[id].x = e - 1;
	lc[id] = ti++;
	rc[id] = ti++;
	return;
}

ll get(ll id, ll s, ll e, ll x){
	fix(id, e);
	if(e - s == 1){
		return seg[id].x;
	}
	ll mid = (s + e) >> 1;
	if(x < mid){
		ll y = get(lc[id], s, mid, x);
		return y;
	}
	ll y = get(rc[id], mid, e, x);
	if(y == -1){
		fix(lc[id], mid);
		y = seg[lc[id]].x;
	}
	return y;
}


ll upd0(ll id, ll s, ll e, ll l, ll r){
	fix(id, e);
	if(r <= s || e <= l) return id;
	ll nd = ti++;
	if(l <= s && e <= r){
		fix(nd, e);
		return nd;
	}
	ll mid = (s + e) >> 1;
	lc[nd] = upd0(lc[id], s, mid, l, r);
	rc[nd] = upd0(rc[id], mid, e, l, r);
	seg[nd].x = max(seg[lc[nd]].x, seg[rc[nd]].x);
	seg[nd].lz = 0;
	seg[nd].h = (seg[lc[nd]].h * p[e - mid] + seg[rc[nd]].h) % mod;
	return nd;
}
ll upd1(ll id, ll s, ll e, ll x){
	fix(id, e);
	if(x < s || e <= x) return id;
	ll nd = ti++;
	if(e - s == 1){
		seg[nd].x = -1;
		seg[nd].h = 1;
		seg[nd].lz = 0;
		return nd;
	}
	ll mid = (s + e) >> 1;
	lc[nd] = upd1(lc[id], s, mid, x);
	rc[nd] = upd1(rc[id], mid, e, x);
	seg[nd].x = max(seg[lc[nd]].x, seg[rc[nd]].x);
	seg[nd].lz = 0;
	seg[nd].h = (seg[lc[nd]].h * p[e - mid] + seg[rc[nd]].h) % mod;
	return nd;
}

bool eq(ll v, ll u){
	return (seg[v].h == seg[u].h && seg[lc[v]].h == seg[lc[u]].h);
}
ll cmp(ll v, ll u, ll s = 0, ll e = maxn){
	if(eq(v, u)) return 0;
	if(seg[v].lz) return -1;
	if(seg[u].lz) return 1;
	if(e - s == 1){
		if(seg[v].h) return 1;
		else return -1;
	}
	ll mid = (s + e) >> 1;
	if(eq(lc[v], lc[u])) return cmp(rc[v], rc[u], mid, e);
	return cmp(lc[v], lc[u], s, mid);
}

struct myCmp{
	bool operator() (ll v, ll u)const {
		ll x = cmp(par[v], par[u]);
		if(x == 0) return v < u;
		return x < 0;
	}
};

set<ll, myCmp> q;

int main(){
    fast_io;
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * 2;
		if(p[i] >= mod) p[i] -= mod;
	}

	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll v, u, c;
		cin >> v >> u >> c;
		c = maxn - 1 - c;
		g[v].pb(Mp(u, c));
		g[u].pb(Mp(v, c));
	}
	ll s, e;
	cin >> s >> e;
	ti = 1;
	par[s] = ti++;
	vis[s] = 1;
	q.insert(s);
	while(!q.empty()){
		ll v = *q.begin();
		q.erase(q.begin());
		for(pll u : g[v]){
			ll x = get(par[v], 0, maxn, u.S);
			ll rt = upd0(par[v], 0, maxn, x + 1, u.S + 1);
			rt = upd1(rt, 0, maxn, x);
			if(!vis[u.F]){
				vis[u.F] = 1;
				par[u.F] = rt;
				q.insert(u.F);
				p2[u.F] = v;
			}
			else if(cmp(rt, par[u.F]) < 0){
				q.erase(u.F);
				par[u.F] = rt;
				q.insert(u.F);
				p2[u.F] = v;
			}
		}
	}
	if(!vis[e]){
		cout << -1;
		return 0;
	}
	cout << seg[par[e]].h << "\n";
	ll v = e;
	vector<ll> vec;
	while(v){
		vec.pb(v);
		v = p2[v];
	}
	cout << Sz(vec) << "\n";
	reverse(all(vec));
	for(ll i : vec){
		cout << i << " ";
	}


    return 0;
}