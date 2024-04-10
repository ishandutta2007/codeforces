//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

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

ll n, k, d, a[maxn], seg[maxn << 2], lz[maxn << 2], b[maxn];
vector<ll> vec, cev;

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		lz[id] += x;
		return;
	}
	seg[lc] += lz[id];
	lz[lc] += lz[id];
	seg[rc] += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}
ll get(ll id, ll s, ll e){
	if(seg[id] > k) return -1;
	if(e - s == 1) return s;
	seg[lc] += lz[id];
	lz[lc] += lz[id];
	seg[rc] += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) >> 1;
	ll x = get(lc, s, mid);
	if(~x) return x;
	return get(rc, mid, e);
}
map<ll, ll> ls;

ll f(ll x){
	ll y = x % d;
	if(y < 0) y += d;
	return (x - y) / d;
}

int main(){
	fast_io;
	
	cin >> n >> k >> d;
	if(d == 0){
		ll l = 0;
		cin >> a[0];
		pll ans = Mp(1, 1);
		for(ll i = 1; i < n; i++){
			cin >> a[i];
			if(a[i] != a[i - 1]){
				if(ans.S - ans.F < i - l - 1){
					ans = Mp(l + 1, i);
				}
				l = i;
			}
		}
		if(ans.S - ans.F < n - l - 1){
			ans = Mp(l + 1, n);
		}
		cout << ans.F << " " << ans.S;
		return 0;
	}
	ll l = 0;
	vec.pb(-1);
	cev.pb(-1);
	pll ans = Mp(1, 1);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(i && (a[i] % d + d) % d != (a[i - 1] % d + d) % d){
			while(l < i){
				upd(1, 0, n, l, l + 1, inf);
				l++;
			}
		}
		{
			ll x = ls[a[i]];
			while(l < x){
				upd(1, 0, n, l, l + 1, inf);
				l++;
			}
			ls[a[i]] = i + 1;
		}
		b[i] = f(a[i]);
		while(Sz(vec) > 1 && a[vec.back()] > a[i]){
			ll x = vec.back();
			vec.pop_back();
		 	upd(1, 0, n, vec.back() + 1, x + 1, -b[i] + b[x]);
		}
		vec.pb(i);
		while(Sz(cev) > 1 && a[cev.back()] < a[i]){
			ll x = cev.back();
			cev.pop_back();
		 	upd(1, 0, n, cev.back() + 1, x + 1, b[i] - b[x]);
		}
		cev.pb(i);
		upd(1, 0, n, 0, i, -1);
		{
			ll l = get(1, 0, n);
			if(ans.S - ans.F < i - l){
				ans = Mp(l + 1, i + 1);
			}
		}
	}
	cout << ans.F << " " << ans.S << "\n";
	
	return 0;
}