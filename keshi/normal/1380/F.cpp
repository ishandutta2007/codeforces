//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, seg[2][2][maxn], a[maxn];

ll cal(ll x, ll y){
	return (x == 1 ? 9 - y : 0);
}

void upd(ll id, ll s, ll e, ll i){
	if(i < s || e <= i) return;
	if(e - s == 1){
		seg[0][0][id] = a[i] + 1;
		seg[0][1][id] = 1;
		seg[1][0][id] = 1;
		seg[1][1][id] = 0;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, i);
	upd(id * 2 + 1, mid, e, i);
	for(ll j = 0; j < 2; j++){
		for(ll k = 0; k < 2; k++){
			seg[j][k][id] = (seg[j][0][id * 2] * seg[0][k][id * 2 + 1] + ((seg[j][1][id * 2] * seg[1][k][id * 2 + 1]) % mod) * cal(a[mid - 1], a[mid])) % mod;
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
		upd(1, 0, n, i);
	}
	for(ll i = 0; i < m; i++){
		ll j;
		cin >> j;
		cin >> a[j - 1];
		upd(1, 0, n, j - 1);
		cout << seg[0][0][1] << '\n';
	}
	
	return 0;
}