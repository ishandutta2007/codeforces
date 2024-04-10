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

ll n, k, a[maxn], gc[maxn], cnt[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll g){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		gc[id] = g;
		cnt[id] = e - s;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, g);
	upd(id * 2 + 1, mid, e, l, r, g);
	gc[id] = __gcd(gc[id * 2], gc[id * 2 + 1]);
	cnt[id] = 0;
	if(gc[id] == gc[id * 2]) cnt[id] += cnt[id * 2];
	if(gc[id] == gc[id * 2 + 1]) cnt[id] += cnt[id * 2 + 1];
	return;
}

pll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return {0, 0};
	if(l <= s && e <= r){
		return {gc[id], cnt[id]};
	}
	ll mid = (s + e) / 2;
	pll p1, p2, p3;
	p1 = get(id * 2, s, mid, l, r);
	p2 = get(id * 2 + 1, mid, e, l, r);
	p3.F = __gcd(p1.F, p2.F);
	p3.S = 0;
	if(p3.F == p1.F) p3.S += p1.S;
	if(p3.F == p2.F) p3.S += p2.S;
	return p3;
}

int main(){
	ll l, r;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		upd(1, 0, n, i, i + 1, a[i]);
	}
	
	cin >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> l >> r;
		cout << r - l + 1 - get(1, 0, n, l - 1, r).S << '\n';
	}
	
	return 0;
}