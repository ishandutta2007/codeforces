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

ll n, k, f[maxn], fp[maxn], ans, x, t;

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

ll C(ll ca, ll cb){
	if(cb < 0 || cb > ca) return 0;
	return (((f[ca] * fp[cb]) % mod) * fp[ca - cb]) % mod;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	f[0] = 1;
	fp[0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	if(k == 0){
		cout << f[n];
		return 0;
	}
	if(k >= n){
		cout << 0;
		return 0;
	}
	
	ans = 2 * C(n, k);
	t = n - k;
	x = 0;
	for(ll i = 0; i < t; i++){
		if(i % 2) x = (x - C(t, i) * pw(t - i, n)) % mod;
		else x = (x + C(t, i) * pw(t - i, n)) % mod;
	}
	x = (x + mod) % mod;
	cout << (ans * x) % mod;
	
	return 0;
}