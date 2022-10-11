//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

struct node{
	ll mx, sl, sr, ml, mr, sz;
	node(){
		sz = 0;
		return;
	}
};

ll n, q;
node seg[2][maxn * 4];
node ndnl = node();
bool lz[maxn * 4];
string st;

node mrg(node l, node r){
	node a;
	if(l.sz == 0) return r;
	if(r.sz == 0) return l;
	a.sz = l.sz + r.sz;
	a.mx = max(max(l.mx, r.mx), max(l.mr + r.sl, l.sr + r.ml));
	a.sr = r.sr;
	if(r.sr == r.sz) a.sr += l.sr;
	a.sl = l.sl;
	if(l.sl == l.sz) a.sl += r.sl;
	a.ml = l.ml;
	if(l.ml == l.sz) a.ml += r.sl;
	if(l.sr == l.sz) a.ml = max(a.ml, l.sr + r.ml);
	a.mr = r.mr;
	if(r.mr == r.sz) a.mr += l.sr;
	if(r.sl == r.sz) a.mr = max(a.mr, r.sl + l.mr);
	return a;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[0][id].sz = 1;
		seg[0][id].mx = 1;
		seg[0][id].ml = 1;
		seg[0][id].mr = 1;
		seg[1][id].sz = 1;
		seg[1][id].mx = 1;
		seg[1][id].ml = 1;
		seg[1][id].mr = 1;
		if(st[s] == '<'){
			seg[0][id].sl = 1;
			seg[0][id].sr = 0;
			seg[1][id].sl = 0;
			seg[1][id].sr = 1;
		}
		else{
			seg[1][id].sl = 1;
			seg[1][id].sr = 0;
			seg[0][id].sl = 0;
			seg[0][id].sr = 1;
		}
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	seg[0][id] = mrg(seg[0][id * 2], seg[0][id * 2 + 1]);
	seg[1][id] = mrg(seg[1][id * 2], seg[1][id * 2 + 1]);
	//cout << s << " " << e << " -> " << seg[0][id].mr << '\n';
	return;
}

void upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		swap(seg[0][id], seg[1][id]);
		lz[id] = !lz[id];
		return;
	}
	ll mid = (s + e) / 2;
	if(lz[id]){
		swap(seg[0][id * 2], seg[1][id * 2]);
		lz[id * 2] = !lz[id * 2];
		swap(seg[0][id * 2 + 1], seg[1][id * 2 + 1]);
		lz[id * 2 + 1] = !lz[id * 2 + 1];
		lz[id] = 0;
	}
	upd(id * 2, s, mid, l, r);
	upd(id * 2 + 1, mid, e, l, r);
	seg[0][id] = mrg(seg[0][id * 2], seg[0][id * 2 + 1]);
	seg[1][id] = mrg(seg[1][id * 2], seg[1][id * 2 + 1]);
	return;
}

node get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l){
		return ndnl;
	}
	if(l <= s && e <= r){
		//cout << "!! " << s << " " << e << " -> " << seg[0][id].mr << " " << seg[0][id].sl << '\n';
		return seg[0][id];
	}
	ll mid = (s + e) / 2;
	if(lz[id]){
		swap(seg[0][id * 2], seg[1][id * 2]);
		lz[id * 2] = !lz[id * 2];
		swap(seg[0][id * 2 + 1], seg[1][id * 2 + 1]);
		lz[id * 2 + 1] = !lz[id * 2 + 1];
		lz[id] = 0;
	}
	node p = mrg(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
	//cout << "! " << s << " " << e << " -> " << p.mr << " " << p.sl << '\n';
	return p;
}

int main(){
	fast_io;
	ll l, r;
	
	cin >> n >> q >> st;
	bld(1, 0, n);
	for(ll i = 0; i < q; i++){
		cin >> l >> r;
		//*
		upd(1, 0, n, l - 1, r);
		cout << get(1, 0, n, l - 1, r).mx << '\n';
		//*/
		/*
		for(ll j = l - 1; j < r; j++){
			st[j] = '<' + '>' - st[j];
		}
		cout << st << '\n';
		//*/
	}
	
	
	return 0;
}