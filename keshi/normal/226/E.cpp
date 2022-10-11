//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll maxm = 5e6 + 100;
const ll lg = 19;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, lc[maxm], rc[maxm], nt, t, st[maxn], ft[maxn], pr[lg][maxn], d[maxn], root[maxn], vis[maxn];
ll seg[maxm];
vector<ll> g[maxn];

ll bld(ll s, ll e){
	ll nd = nt++;
	if(e - s == 1) return nd;
	ll mid = (s + e) >> 1;
	lc[nd] = bld(s, mid);
	rc[nd] = bld(mid, e);
	return nd;
}
ll upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return id;
	ll nd = nt++;
	seg[nd] = seg[id];
	if(l <= s && e <= r){
		seg[nd]++;
		lc[nd] = lc[id];
		rc[nd] = rc[id];
		return nd;
	}
	ll mid = (s + e) >> 1;
	lc[nd] = upd(lc[id], s, mid, l, r);
	rc[nd] = upd(rc[id], mid, e, l, r);
	return nd;
}
ll get(ll id, ll s, ll e, ll x){
	if(x < s || e <= x) return 0;
	if(e - s == 1) return seg[id];
	ll mid = (s + e) >> 1;
	return seg[id] + get(lc[id], s, mid, x) + get(rc[id], mid, e, x);
}

void dfs(ll v){
	st[v] = t++;
	for(ll u : g[v]){
		d[u] = d[v] + 1;
		dfs(u);
	}
	ft[v] = t;
}

ll par(ll v, ll x){
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) v = pr[i][v];
	}
	return v;
}
ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	v = par(v, d[v] - d[u]);
	for(ll i = lg; i--;){
		if(d[v] >= (1 << i) && pr[i][v] != pr[i][u]){
			v = pr[i][v];
			u = pr[i][u];
		}
	}
	if(v != u) v = pr[0][v];
	return v;
}
ll get(ll v, ll l, ll r){
	return d[v] - get(root[r], 0, n + 1, st[v]) + get(root[l], 0, n + 1, st[v]);
}

int main(){
    fast_io;

	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> pr[0][i];
		g[pr[0][i]].pb(i);
	}
	dfs(0);
	for(ll j = 1; j < lg; j++){
		for(ll i = 0; i <= n; i++){
			if(d[i] >= (1 << j)) pr[j][i] = pr[j - 1][pr[j - 1][i]];
		}
	}
	cin >> m;
	root[0] = bld(0, n + 1);
	fill(vis, vis + n + 1, -1);
	for(ll i = 1; i <= m; i++){
		ll f, v, u, k, y;
		cin >> f;
		root[i] = root[i - 1];
		if(f == 1){
			cin >> v;
			vis[v] = i;
			root[i] = upd(root[i], 0, n + 1, st[v], ft[v]);
		}
		else{
			cin >> v >> u >> k >> y;
			if(vis[v] <= y) k++;
			ll x = lca(v, u);
			ll o = get(v, y, i);
			ll oo = get(pr[0][x], y, i);
			ll ans = -1;
			if(o - oo < k){
				k -= o - oo;
				oo = get(x, y, i);
				if(get(u, y, i) - oo >= k){
					ll l = 0, r = d[u] - d[x];
					while(r - l > 1){
						ll mid = (l + r) >> 1;
						if(get(par(u, mid), y, i) - oo >= k) l = mid;
						else r = mid;
					}
					ans = par(u, l);
				}
			}
			else{
				ll l = 0, r = d[v] - d[x] + 1;
				while(r - l > 1){
					ll mid = (l + r) >> 1;
					if(o - get(par(v, mid), y, i) >= k) r = mid;
					else l = mid;
				}
				ans = par(v, l);
			}
			if(ans == u) ans = -1;
			cout << ans << "\n";
		}
	}

    return 0;
}