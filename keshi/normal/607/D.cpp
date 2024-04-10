//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, q, a[maxn], b[maxn], c[maxn], p[maxn], st[maxn], ft[maxn], seg1[maxn], seg2[maxn], lz2[maxn];

vector<pll> vec;

vector<ll> g[maxn];

void dfs(ll v){
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		dfs(g[v][i]);
	}
	ft[v] = t;
	return;
}

//this is only for this situation it doesn't work in real life :joy:

void upd1(ll id, ll s, ll e, ll l, ll r, ll x){
	//cout << "   OL " << id << " " << l << " " << r << '\n';
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg1[id] = (seg1[id] * x) % mod;
		//cout << "   G " << id << " " << seg1[id] << '\n';
		return;
	}
	ll mid = (s + e) / 2;
	//cout << "   E " << id << " " << seg1[id] << '\n';
	seg1[id * 2] = (seg1[id] * seg1[id * 2]) % mod;
	seg1[id * 2 + 1] = (seg1[id] * seg1[id * 2 + 1]) % mod;
	seg1[id] = 1;
	upd1(id * 2, s, mid, l, r, x);
	upd1(id * 2 + 1, mid, e, l, r, x);
	return;
}

ll get1(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 1;
	if(l <= s && e <= r) {
		//cout << "W " << id << " " << seg1[id] << '\n';
		return seg1[id];
	}
	ll mid = (s + e) / 2;
	seg1[id * 2] = (seg1[id] * seg1[id * 2]) % mod;
	seg1[id * 2 + 1] = (seg1[id] * seg1[id * 2 + 1]) % mod;
	seg1[id] = 1;
	return get1(id * 2, s, mid, l, r) * get1(id * 2 + 1, mid, e, l, r);
}

void upd21(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg2[id] = (seg2[id] * x) % mod;
		lz2[id] = (lz2[id] * x) % mod;
		return;
	}
	ll mid = (s + e) / 2;
	seg2[id * 2] = (seg2[id * 2] * lz2[id]) % mod;
	seg2[id * 2 + 1] = (seg2[id * 2 + 1] * lz2[id]) % mod;
	lz2[id * 2] = (lz2[id] * lz2[id * 2]) % mod;
	lz2[id * 2 + 1] = (lz2[id] * lz2[id * 2 + 1]) % mod;
	lz2[id] = 1;
	upd21(id * 2, s, mid, l, r, x);
	upd21(id * 2 + 1, mid, e, l, r, x);
	seg2[id] = (seg2[id * 2] + seg2[id * 2 + 1]) % mod;
	return;
}

void upd22(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg2[id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	seg2[id * 2] = (seg2[id * 2] * lz2[id]) % mod;
	seg2[id * 2 + 1] = (seg2[id * 2 + 1] * lz2[id]) % mod;
	lz2[id * 2] = (lz2[id] * lz2[id * 2]) % mod;
	lz2[id * 2 + 1] = (lz2[id] * lz2[id * 2 + 1]) % mod;
	lz2[id] = 1;
	upd22(id * 2, s, mid, l, r, x);
	upd22(id * 2 + 1, mid, e, l, r, x);
	seg2[id] = (seg2[id * 2] + seg2[id * 2 + 1]) % mod;
	return;
}

ll get2(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg2[id];
	ll mid = (s + e) / 2;
	seg2[id * 2] = (seg2[id * 2] * lz2[id]) % mod;
	seg2[id * 2 + 1] = (seg2[id * 2 + 1] * lz2[id]) % mod;
	lz2[id * 2] = (lz2[id] * lz2[id * 2]) % mod;
	lz2[id * 2 + 1] = (lz2[id] * lz2[id * 2 + 1]) % mod;
	lz2[id] = 1;
	return (get2(id * 2, s, mid, l, r) + get2(id * 2 + 1, mid, e, l, r)) % mod;
}

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	ll v, u;
	fast_io;
	
	fill(lz2, lz2 + maxn, 1);
	fill(seg1, seg1 + maxn, 1);
	
	c[0] = 1;
	cin >> a[n++] >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> t >> v;
		v--;
		if(t == 1){
			cin >> a[n];
			vec.pb({n, 1});
			g[v].pb(n);
			p[n] = v;
			n++;
		}
		else{
			vec.pb({v, 0});
		}
	}
	
	t = 0;
	
	dfs(0);
	
	upd22(1, 0, n, 0, 1, a[0]);
	
	for(ll i = 0; i < q; i++){
		v = vec[i].F, u = vec[i].S;
		if(u){
			u = get1(1, 0, n, st[p[v]], st[p[v]] + 1);
			c[v]++;
			//cout << "# " << p[v] << " " << u << '\n';
			upd22(1, 0, n, st[v], st[v] + 1, (u * a[v]) % mod);
			u = (pw(c[p[v]]++, mod - 2) * c[p[v]]) % mod;
			upd21(1, 0, n, st[p[v]], ft[p[v]], u);
			upd1(1, 0, n, st[p[v]], ft[p[v]], u);
			//cout << "? " << st[p[v]] << " " << ft[p[v]] << " " << p[v] << " " << u << '\n';
		}
		else{
			if(v == 0) cout << get2(1, 0, n, st[v], ft[v]) << '\n';
			else cout << (get2(1, 0, n, st[v], ft[v]) * pw(get1(1, 0, n, st[p[v]], st[p[v]] + 1), mod - 2)) % mod << '\n';
		}
	}
	
	return 0;
}