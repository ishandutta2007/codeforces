//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, seg[2][maxn], lz[2][maxn], ans;
pair<pll, ll> p[maxn];
vector<ll> vec;
vector<pll> g[maxn];
map<ll, ll> mp;

void upd(ll f, ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[f][id] += x;
		lz[f][id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[f][id * 2] += lz[f][id];
	seg[f][id * 2 + 1] += lz[f][id];
	lz[f][id * 2] += lz[f][id];
	lz[f][id * 2 + 1] += lz[f][id];
	lz[f][id] = 0;
	upd(f, id * 2, s, mid, l, r, x);
	upd(f, id * 2 + 1, mid, e, l, r, x);
	seg[f][id] = max(seg[f][id * 2], seg[f][id * 2 + 1]);
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> p[i].F.F >> p[i].F.S >> p[i].S;
		vec.pb(p[i].F.F);
		vec.pb(p[i].F.S);
	}
	sort(vec.begin(), vec.end());
	m = 1;
	for(ll i = 0; i < vec.size(); i++){
		if(i == 0 || vec[i] != vec[i - 1]) mp[vec[i]] = m++;
	}
	for(ll i = 0; i < n; i++){
		p[i].F.F = mp[p[i].F.F];
		p[i].F.S = mp[p[i].F.S];
		g[p[i].F.S].pb(Mp(p[i].F.F, p[i].S));
	}
	for(ll i = 1; i < m; i++){
		for(ll j = 0; j < g[i].size(); j++){
			upd(g[i][j].S - 1, 1, 0, m, 0, g[i][j].F, 1);
		}
		ll x = max(seg[0][1], seg[1][1]);
		upd(0, 1, 0, m, i, i + 1, x);
		upd(1, 1, 0, m, i, i + 1, x);
		ans = max(ans, x);
	}
	cout << ans;
	
	return 0;
}