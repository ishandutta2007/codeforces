//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 6e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, seg[11][11][maxn], lm[maxn], rm[maxn], lz[maxn];
string st;

void push(ll id, ll s, ll e, ll z){
	if(z == 0) return;
	for(ll i = 0; i < 11; i++){
		for(ll j = 0; j < 11; j++){
			seg[i][j][id] = 0;
		}
	}
	lm[id] = rm[id] = z;
	seg[z][z][id] = e - s - 1;
	lz[id] = z;
	return;
}
void bld(ll id, ll s, ll e){
	if(e - s == 1){
		push(id, s, e, ll(st[s] - 'a') + 1);
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	lm[id] = lm[id * 2];
	rm[id] = rm[id * 2 + 1];
	for(ll j = 0; j < 11; j++){
		for(ll i = 0; i < 11; i++){
			seg[j][i][id] = seg[j][i][id * 2] + seg[j][i][id * 2 + 1];
		}
	}
	seg[rm[id * 2]][lm[id * 2 + 1]][id]++;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		push(id, s, e, x);
		return;
	}
	ll mid = (s + e) / 2;
	push(id * 2, s, mid, lz[id]);
	push(id * 2 + 1, mid, e, lz[id]);
	lz[id] = 0;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	lm[id] = lm[id * 2];
	rm[id] = rm[id * 2 + 1];
	for(ll j = 0; j < 11; j++){
		for(ll i = 0; i < 11; i++){
			seg[j][i][id] = seg[j][i][id * 2] + seg[j][i][id * 2 + 1];
		}
	}
	seg[rm[id * 2]][lm[id * 2 + 1]][id]++;
	return;
}

int main(){
	fast_io;
	ll t, l, r;
	
	cin >> n >> m >> k;
	cin >> st;
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		cin >> t;
		if(t == 1){
			cin >> l >> r >> st;
			upd(1, 0, n, l - 1, r, ll(st[0] - 'a') + 1);
		}
		else{
			cin >> st;
			l = 1;
			for(ll i = 0; i < k; i++){
				for(ll j = 0; j <= i; j++){
					l += seg[ll(st[i] - 'a') + 1][ll(st[j] - 'a') + 1][1];
				}
			}
			cout << l << '\n';
		}
	}
	
	return 0;
}