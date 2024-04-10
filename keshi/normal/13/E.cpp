//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll tof = 400;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, a[maxn], b[maxn], c[maxn];

void upd(ll l){
	l *= tof;
	ll r = min(l + tof, n);
	for(ll j = r - 1; j >= l; j--){
		if(j + a[j] < r) b[j] = b[j + a[j]], c[j] = c[j + a[j]] + 1;
		else b[j] = j, c[j] = 1;
	}
	return;
}
void get(ll l){
	ll x = 0, y = 0;
	while(l < n){
		x = b[l];
		y += c[l];
		l = x + a[x];
	}
	cout << x + 1 << " " << y << '\n';
	return;
}

int main(){
	fast_io;
	ll t, l, r;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i * tof < n; i++){
		upd(i);
	}
	for(ll i = 0; i < m; i++){
		cin >> t >> l;
		l--;
		if(t == 0){
			cin >> r;
			a[l] = r;
			upd(l / tof);
		}
		else get(l);
	}
	
	return 0;
}