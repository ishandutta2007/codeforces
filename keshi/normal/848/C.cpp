//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll tof = 1024;
const ll tof2 = 101;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, fen[tof2][maxn], nxt[maxn], lst[maxn], a[maxn];
set<ll> s[maxn];

void add(ll id, ll x, ll y){
	for(; x < maxn; x += x & -x){
		fen[id][x] += y;
	}
	return;
}
ll num(ll id, ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += fen[id][x];
	}
	return y;
}

void upd(ll l, ll r, ll x){
	if(l == 0) return;
	l--;
	add(l >> 10, r, (r - l - 1) * x);
	return;
}
ll get(ll l, ll r){
	ll e = r;
	ll x = 0;
	l--;
	while(l & 1023 && l < r){
		l++;
		if(nxt[l] <= e) x += nxt[l] - l;
	}
	while(r & 1023 && l < r){
		if(nxt[r] <= e) x += nxt[r] - r;
		r--;
	}
	while(l < r){
		x += num(l >> 10, e);
		l += tof;
	}
	return x;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		s[i].insert(0);
		s[i].insert(n + 1);
		s[a[i]].insert(i);
		nxt[lst[a[i]]] = i;
		nxt[i] = n + 1;
		lst[a[i]] = i;
	}
	for(ll i = 1; i <= n; i++){
		upd(i, nxt[i], 1);
	}
	for(ll i = 0; i < m; i++){
		ll t, l, r;
		cin >> t >> l >> r;
		if(t == 2) cout << get(l, r) << '\n';
		else if(a[l] != r){
			set<ll>::iterator it;
			it = s[a[l]].upper_bound(l);
			it--;
			it--;
			nxt[*it] = nxt[l];
			upd(l, nxt[l], -1);
			upd(*it, l, -1);
			upd(*it, nxt[l], 1);
			s[a[l]].erase(l);
			a[l] = r;
			it = s[a[l]].upper_bound(l);
			nxt[l] = *it;
			it--;
			nxt[*it] = l;
			upd(*it, nxt[l], -1);
			upd(l, nxt[l], 1);
			upd(*it, l, 1);
			s[a[l]].insert(l);
		}
	}
	
	return 0;
}