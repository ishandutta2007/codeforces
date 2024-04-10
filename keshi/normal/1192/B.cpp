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
#define lc (id << 1)
#define rc (lc | 1)

struct node{
	ll a, b, c, ab, bc, abc, lz;
	node(){
		a = b = c = ab = bc = abc = lz = 0;
	}
};

ll n, q, w, f[maxn], c[maxn], st[maxn], ft[maxn];
bool vis[maxn];
vector<pll> g[maxn];
vector<ll> vec;
node seg[maxn << 2];

void dfs(ll v){
	vis[v] = 1;
	st[v] = ft[v] = Sz(vec);
	vec.pb(v);
	for(pll u : g[v]){
		if(!vis[u.F]){
			f[u.S] = u.F;
			dfs(u.F);
			ft[v] = Sz(vec);
			vec.pb(v);
		}
	}
	return;
}

void Do(ll id, ll x){
	seg[id].a += x;
	seg[id].b += -2 * x;
	seg[id].c += x;
	seg[id].ab += -x;
	seg[id].bc += -x;
	seg[id].lz += x;
	return;
}

node mrg(node l, node r){
	node m;
	m.a = max(l.a, r.a);
	m.b = max(l.b, r.b);
	m.c = max(l.c, r.c);
	m.ab = max(l.a + r.b, max(l.ab, r.ab));
	m.bc = max(l.b + r.c, max(l.bc, r.bc));
	m.abc = max(max(l.abc, l.ab + r.c), max(l.a + r.bc, r.abc));
	return m;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		Do(id, x);
		return;
	}
	ll mid = (s + e) >> 1;
	Do(lc, seg[id].lz);
	Do(rc, seg[id].lz);
	seg[id].lz = 0;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}

int main(){
    fast_io;

	cin >> n >> q >> w;
	for(ll i = 0; i < n - 1; i++){
		ll v, u;
		cin >> v >> u >> c[i];
		g[v].pb(Mp(u, i));
		g[u].pb(Mp(v, i));
	}
	dfs(1);
	for(ll i = 0; i < n - 1; i++){
		upd(1, 0, Sz(vec), st[f[i]], ft[f[i]] + 1, c[i]);
	}
	ll ls = 0;
	for(ll i = 0; i < q; i++){
		ll v, x;
		cin >> v >> x;
		v = (v + ls) % (n - 1);
		x = (x + ls) % w;
		upd(1, 0, Sz(vec), st[f[v]], ft[f[v]] + 1, x - c[v]);
		c[v] = x;
		cout << seg[1].abc << "\n";
		ls = seg[1].abc;
	}

    return 0;
}