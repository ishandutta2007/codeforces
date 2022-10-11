//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn];

pll seg[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, pll p){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = p;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, p);
	upd(id * 2 + 1, mid, e, l, r, p);
	return;
}

pll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return {0, 0};
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	pll p1, p2;
	p1 = get(id * 2, s, mid, l, r);
	p2 = get(id * 2 + 1, mid, e, l, r);
	if(p1.F < p2.F) p1 = p2;
	if(p1.F < seg[id].F) p1 = seg[id];
	return p1;
}

int main(){
	ll t, x, y, k;
	pll p;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	
	for(ll i = 1; i <= m; i++){
		cin >> t;
		if(t == 1){
			cin >> x >> y >> k;
			upd(1, 0, n, y - 1, y + k - 1, {i, x - y});
		}
		else{
			cin >> x;
			p = get(1, 0, n, x - 1, x);
			if(p.F == 0) cout << b[x - 1];
			else cout << a[x - 1 + p.S];
			cout << '\n';
		}
	}
	
	return 0;
}