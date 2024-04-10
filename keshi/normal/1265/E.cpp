//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, x, y, p, z;

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> n;
	
	z = pw(100, mod - 2);
	
	p = 1;
	
	for(ll i = 1; i <= n; i++){
		cin >> a;
		a = (a * z) % mod;
		x = (x + (p * (1 - a)) % mod) % mod;
		y = (y + (((p * (1 - a)) % mod) * i) % mod) % mod;
		p = (p * a) % mod;
	}
	
	y = (y + (p * n) % mod) % mod;
	
	cout << ((y * pw(1 - x, mod - 2)) % mod + mod) % mod;
	
	return 0;
}