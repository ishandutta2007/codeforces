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

ll pw(ll pa, ll pb){
	ll pc = 1;
	while(pb){
		if(pb & 1) pc = pc * pa % mod;
		pa = pa * pa % mod;
		pb >>= 1;
	}
	return pc;
}

ll f(ll n, ll k){
	ll p = 1, x = 0, y = 1;
	for(ll i = k; i > 0; i--){
		x = (x + p * pw(i, n)) % mod;
		p = p * -i % mod * pw(k - i + 1, mod - 2) % mod;
		y = y * i % mod;
	}
	return x * pw(y, mod - 2) % mod;
}

int main(){
    fast_io;

	ll n, k, s = 0, a;

	cin >> n >> k;
	for(ll i = 0; i < n; i++){
		cin >> a;
		s += a;
		if(s >= mod) s -= mod;
	}
	ll x = s * (f(n, k) + (n - 1) * f(n - 1, k) % mod) % mod;
	cout << (x + mod) % mod;
	

    return 0;
}