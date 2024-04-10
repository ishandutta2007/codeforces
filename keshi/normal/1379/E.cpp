//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, a[maxn];

bool isp[maxn];

bool ok(ll x, ll y){
	if(x == 1 && y == 0) return 1;
	if(x % 2 == 0) return 0;
	if(y > (x - 3) / 2) return 0;
	if(x == 9 && y == 2) return 0;
	if(y < 0) return 0;
	if(y == 0) return isp[x + 1];
	if(y == 1) return !isp[x + 1];
	return 1;
}
void tr(ll v, ll x){
	if(x == 0) return;
	ll u = ++t;
	a[u] = v;
	tr(u, x / 2);
	tr(u, x / 2);
	return;
}
void solve(ll v, ll x, ll y){
	ll u = ++t;
	a[u] = v;
	for(ll i = 1; i < x - 1; i = i * 2 + 1){
		ll z = y - (2 * i <= x - 1 - i || i >= (x - 1 - i) * 2);
		if(ok(x - 1 - i, z)){
			tr(u, i);
			solve(u, x - i - 1, z);
			return;
		}
	}
	return;
}

int main(){
	fast_io;
	ll x = 1;
	while(x < maxn){
		isp[x] = 1;
		x <<= 1;
	}
	ll n, k;
	cin >> n >> k;
	if(!ok(n, k)){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	solve(0, n, k);
	for(ll i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}