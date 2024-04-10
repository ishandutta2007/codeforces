//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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
#define lc (id << 1)
#define rc (lc | 1)

ll n, q, dsu[maxn], sz[maxn], d[maxn], L[maxn], R[maxn], ind[maxn];
pll a[maxn];
vector<pll> vec[maxn];
pll seg[maxn << 2];

ll par(ll v){
	if(dsu[v] != v) dsu[v] = par(dsu[v]);
	return dsu[v];
}
void Union(ll v, ll u){
	v = par(v);
	u = par(u);
	if(u == v) return;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	ind[v] = min(ind[v], ind[u]);
	L[v] = min(L[v], L[u]);
	R[v] = max(R[v], R[u]);
	return;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = Mp(x, s);
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = max(seg[lc], seg[rc]);
	return;
}
pll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return Mp(0, 0);
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	return max(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}

pair<ll, pll> qq[maxn];
vector<pll> sonic;

int main(){
    fast_io;
    
    cin >> q;
    for(ll i = 0; i < q; i++){
    	cin >> qq[i].F >> qq[i].S.F >> qq[i].S.S;
    	if(qq[i].F == 1){
    		n++;
    		qq[i].S.S--;
    		sonic.pb(Mp(qq[i].S.F, n));
    		sonic.pb(Mp(qq[i].S.S, -n));
		}
	}
	sort(all(sonic));
	for(ll i = 0; i < Sz(sonic); i++){
		if(sonic[i].S > 0){
			d[sonic[i].S] = i;
		}
	}
	n = 0;
	for(ll i = 0; i < q; i++){
		ll t = qq[i].F, x = qq[i].S.F, y = qq[i].S.S;
		if(t == 1){
			n++;
			ll l = lower_bound(all(sonic), Mp(x, -inf)) - sonic.begin();
			ll r = upper_bound(all(sonic), Mp(y, inf)) - sonic.begin();
			ind[n] = d[n];
			L[n] = l;
			R[n] = r;
			dsu[n] =  n;
			sz[n] = 1;
			pll mx = get(1, 0, Sz(sonic), 0, l);
			while(mx.F > l){
				upd(1, 0, Sz(sonic), mx.S, mx.S + 1, 0);
				Union(par(sonic[mx.S].S), n);
				mx = get(1, 0, Sz(sonic), 0, l);
			}
			mx = get(1, 0, Sz(sonic), l, r);
			while(mx.F > r){
				upd(1, 0, Sz(sonic), mx.S, mx.S + 1, 0);
				Union(par(sonic[mx.S].S), n);
				mx = get(1, 0, Sz(sonic), l, r);
			}
			ll v = par(n);
			upd(1, 0, Sz(sonic), ind[v], ind[v] + 1, R[v]);
		}
		if(t == 2){
			ll v = par(x), u = par(y);
			if(L[u] <= L[v] && R[v] <= R[u]){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	
 
    return 0;
}