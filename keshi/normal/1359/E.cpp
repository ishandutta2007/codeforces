//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, ans, f[maxn], fp[maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb & 1) pc = (pc * pa) % mod;
	return pc;
}

ll C(ll ca, ll cb){
	if(ca < 0 || cb > ca) return 0;
	return (((f[ca] * fp[cb]) % mod) * fp[ca - cb]) % mod;
}

int main(){
	fast_io;
	f[0] = fp[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		ans = (ans + C(n / i - 1, k - 1)) % mod;
	}
	cout << (ans + mod) % mod;
	
	return 0;
}