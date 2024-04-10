//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 8e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

struct da{
	ll c0, c1, l01, l10, lz;
};

ll n, m;
string st;
da seg[maxn];

da mrg(da l, da r){
	da s;
	s.c0 = l.c0 + r.c0;
	s.c1 = l.c1 + r.c1;
	s.l01 = max(l.c0 + r.l01, l.l01 + r.c1);
	s.l10 = max(l.c1 + r.l10, l.l10 + r.c0);
	s.lz = 0;
	return s;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		if(st[s] == '4') seg[id].c0 = 1, seg[id].c1 = 0;
		else seg[id].c0 = 0, seg[id].c1 = 1;
		seg[id].l01 = seg[id].l10 = 1;
		seg[id].lz = 0;
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	seg[id] = mrg(seg[id * 2], seg[id * 2 + 1]);
	return;
}
void rev(ll id){
	swap(seg[id].c0, seg[id].c1);
	swap(seg[id].l01, seg[id].l10);
	seg[id].lz = 1 - seg[id].lz;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		rev(id);
		return;
	}
	ll mid = (s + e) / 2;
	if(seg[id].lz){
		rev(id * 2);
		rev(id * 2 + 1);
		seg[id].lz = 0;
	}
	upd(id * 2, s, mid, l, r);
	upd(id * 2 + 1, mid, e, l, r);
	seg[id] = mrg(seg[id * 2], seg[id * 2 + 1]);
	return;
}

int main(){
	fast_io;
	ll l, r;
	
	cin >> n >> m >> st;
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		cin >> st;
		if(st == "count") cout << seg[1].l01 << '\n';
		else{
			cin >> l >> r;
			upd(1, 0, n, l - 1, r);
		}
	}
	
	return 0;
}