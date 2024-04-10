//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxm = 4e6;
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

struct node{
	ll mx, lx, rx, sz;
	node(){
		mx = lx = rx = sz = 0;
	}
};

ll n, m, t, root[maxn], lc[maxm], rc[maxm];
pll a[maxn];
node seg[maxm];

node mrg(node l, node r){
	node mid;
	mid.sz = l.sz + r.sz;
	mid.mx = max(max(l.mx, r.mx), l.rx + r.lx);
	if(l.lx == l.sz) mid.lx = l.sz + r.lx;
	else mid.lx = l.lx;
	if(r.rx == r.sz) mid.rx = r.sz + l.rx;
	else mid.rx = r.rx;
	return mid;
}

ll bld(ll s, ll e){
	ll id = t++;
	if(e - s == 1){
		seg[id].sz = 1;
		return id;
	}
	ll mid = (s + e) >> 1;
	lc[id] = bld(s, mid);
	rc[id] = bld(mid, e);
	seg[id] = mrg(seg[lc[id]], seg[rc[id]]);
	return id;
}
ll upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return id;
	ll nd = t++;
	if(l <= s && e <= r){
		seg[nd].sz = seg[nd].lx = seg[nd].rx = seg[nd].mx = 1;
		return nd;
	}
	ll mid = (s + e) >> 1;
	lc[nd] = upd(lc[id], s, mid, l, r);
	rc[nd] = upd(rc[id], mid, e, l, r);
	seg[nd] = mrg(seg[lc[nd]], seg[rc[nd]]);
	return nd;
}
node get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return node();
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	return mrg(get(lc[id], s, mid, l, r), get(rc[id], mid, e, l, r));
}

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	root[n] = bld(0, n);
	sort(a, a + n);
	for(ll i = n; i--;){
		root[i] = upd(root[i + 1], 0, n, a[i].S, a[i].S + 1);
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll s, e, w;
		cin >> s >> e >> w;
		ll l = 0, r = n, mid;
		while(r - l > 1){
			mid = (l + r) >> 1;
			if(get(root[mid], 0, n, s - 1, e).mx >= w) l = mid;
			else r = mid;
		}
		cout << a[l].F << "\n";
	}

    return 0;
}