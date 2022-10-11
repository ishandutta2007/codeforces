//In the name of God
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
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

ll n, a[maxn], b[maxn], c[maxn], ans, seg[maxn << 2];
vector<pll> vec;
vector<ll> g[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = max(seg[id], x);
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = max(seg[lc], seg[rc]);
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	return max(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	vec.pb(Mp(a[i], i));
	}
	sort(all(vec));
	ll t = 0;
	for(ll i = 0; i < n; i++){
		if(i != 0 && vec[i].F != vec[i - 1].F) t++;
		a[vec[i].S] = t;
	}
	vec.clear();
	for(ll i = 0; i < n; i++){
    	cin >> b[i];
    	vec.pb(Mp(b[i], i));
	}
	sort(all(vec));
	t = 0;
	for(ll i = 0; i < n; i++){
		if(i != 0 && vec[i].F != vec[i - 1].F) t++;
		b[vec[i].S] = t;
	}
	vec.clear();
	for(ll i = 0; i < n; i++){
    	cin >> c[i];
    	vec.pb(Mp(c[i], i));
	}
	sort(all(vec));
	t = 0;
	for(ll i = 0; i < n; i++){
		if(i != 0 && vec[i].F != vec[i - 1].F) t++;
		c[vec[i].S] = t;
	}
	vec.clear();
	for(ll i = 0; i < n; i++){
		g[a[i]].pb(i);
	}
	for(ll i = n; i--;){
		for(ll j : g[i]){
			if(get(1, 0, n, b[j] + 1, n) > c[j]) ans++;
		}
		for(ll j : g[i]){
			upd(1, 0, n, b[j], b[j] + 1, c[j]);
		}
	}
	cout << ans;
 
    return 0;
}