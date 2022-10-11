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

ll n, m, x, c, a[maxn], d[maxn], p[maxn], seg[maxn];

vector<ll> vec;

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	return get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}

int main(){
	ll l, r;
	set<ll> s;
	fast_io;
	
	for(ll i = 2; i < maxn; i++){
		if(p[i] == 0){
			p[i] = i;
			for(ll j = i * i; j < maxn; j += i){
				p[j] = i;
			}
		}
	}
	
	d[1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		ll j = i;
		x = p[i];
		c = 1;
		while(j % x == 0){
			j /= x;
			c++;
		}
		d[i] = c * d[j];
	}
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		upd(1, 0, n, i, i + 1, a[i]);
		if(a[i] > 2) s.insert(i);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> c >> l >> r;
		if(c == 2) cout << get(1, 0, n, l - 1, r) << '\n';
		else{
			vec.clear();
			set<ll>::iterator it = s.lower_bound(l - 1);
			while(it != s.end() && *it < r){
				a[*it] = d[a[*it]];
				if(a[*it] <= 2) vec.pb(*it);
				upd(1, 0, n, *it, *it + 1, a[*it]);
				it++;
			}
			for(ll j = 0; j < vec.size(); j++){
				s.erase(vec[j]);
			}
		}
	}
	
	return 0;
}