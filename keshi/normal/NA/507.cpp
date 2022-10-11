//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], t, ans;
int h[maxn], g[2][maxn];

void upd(ll id, ll x){
	if(h[id] == -1) return;
	if(g[(x >> h[id]) & 1][id] == 0){
		g[(x >> h[id]) & 1][id] = t;
		h[t++] = h[id] - 1;
	}
	upd(g[(x >> h[id]) & 1][id], x);
	return;
}

ll get(ll id, ll x){
	if(h[id] == -1) return 0;
	if(g[1 - (x >> h[id]) & 1][id]) return (1ll << h[id]) + get(g[1 - (x >> h[id]) & 1][id], x);
	return get(g[(x >> h[id]) & 1][id], x);
}

int main(){
	fast_io;
	ll x = 0;
	h[t++] = 40;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
	}
	ll y = x;
	x = 0;
	for(ll i = 0; i <= n; i++){
		upd(0, x);
		ans = max(ans, get(0, y));
		x ^= a[i];
		y ^= a[i];
	}
	cout << ans;
	
	return 0;
}