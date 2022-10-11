//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a, h, l, r, b, z, c, d[maxn];

ld p, ans, seg[maxn];

vector<pair<ll, pll> > vec;

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x / 100.0;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = seg[id * 2] * seg[id * 2 + 1];
	return;
}

int main(){
	fast_io;
	fill(seg, seg + maxn, 1);
	
	cout << setprecision(10) << fixed;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a >> h >> l >> r;
		d[i * 2] = 100 - l;
		d[i * 2 + 1] = 100 - r;
		vec.pb(Mp(a - h, Mp(0, i * 2))), vec.pb(Mp(a - 1, Mp(2, i * 2)));
		vec.pb(Mp(a + 1, Mp(0, i * 2 + 1))), vec.pb(Mp(a + h, Mp(2, i * 2 + 1)));
	}
	
	for(ll i = 0; i < m; i++){
		cin >> b >> z;
		vec.pb(Mp(b, Mp(1, z)));
	}
	
	sort(vec.begin(), vec.end());
	
	p = 1;
	
	for(ll i = 0; i < vec.size(); i++){
		if(vec[i].S.F == 0) upd(1, 0, 2 * n, vec[i].S.S, vec[i].S.S + 1, d[vec[i].S.S]);
		if(vec[i].S.F == 1) ans += seg[1] * vec[i].S.S;
		if(vec[i].S.F == 2) upd(1, 0, 2 * n, vec[i].S.S, vec[i].S.S + 1, 100);
	}
	
	cout << ans;
	
	return 0;
}