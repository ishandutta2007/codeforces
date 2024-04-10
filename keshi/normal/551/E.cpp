//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 6e5 + 100;
const ll tof = 720;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, q, c[maxn];
pll a[maxn], b[tof][tof];

void upd(ll r, ll x){
	if(r == -1) return;
	for(ll i = 0; i < r / tof; i++){
		c[i] += x;
	}
	ll j = r / tof;
	for(ll i = j * tof; i <= r; i++){
		a[i].F += x;
	}
	for(ll i = 0; i < tof; i++){
		b[j][i] = a[j * tof + i];
	}
	sort(b[j], b[j] + tof);
	return;
}

ll get(ll x){
	ll mn = inf, mx = -inf;
	for(ll i = 0; i <= n / tof; i++){
		ll j;
		j = lower_bound(b[i], b[i] + tof, Mp(x - c[i], -inf)) - b[i];
		if(0 <= j && j < tof && b[i][j].F == x - c[i]) mn = min(mn, b[i][j].S);
		j = upper_bound(b[i], b[i] + tof, Mp(x - c[i], inf)) - b[i] - 1;
		if(0 <= j && j < tof && b[i][j].F == x - c[i]) mx = max(mx, b[i][j].S);
	}
	if(mn == inf) return -1;
	return mx - mn;
}

int main(){
	fast_io;
	ll t, l, r, x;
	
	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
		b[i / tof][i % tof] = a[i];
	}
	for(ll i = n; i / tof == n / tof; i++){
		a[i] = Mp(inf, i);
		b[i / tof][i % tof] = a[i];
	}
	for(ll i = 0; i <= n / tof; i++){
		sort(b[i], b[i] + tof);
	}
	for(ll i = 0; i < q; i++){
		cin >> t;
		if(t == 2){
			cin >> x;
			cout << get(x) << '\n';
		}
		else{
			cin >> l >> r >> x;
			upd(r - 1, x);
			upd(l - 2, -x);
		}
	}
	
	return 0;
}