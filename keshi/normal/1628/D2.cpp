//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e6;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll t, n, m, k, f[maxn], fp[maxn];

ll C(int a, int b){
	if(a < 0 || b < 0 || a < b) return 0;
	return f[a] * fp[b] % mod * fp[a - b] % mod;
}

int main(){
	fast_io;

	f[0] = fp[0] = 1;
	for(int i = 1; i < maxn; i++){
		f[i] = f[i - 1] * i % mod;
		fp[i] = pw(f[i], mod - 2);
	}

	ll p2 = pw(2, mod - 2);

	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		ll ans = 0;
		for(ll i = 1; i <= n; i++){
			ll x = (i + 1) * p2 % mod;
			ans = (ans + x * pw(p2, n - i) % mod * C(n - i, n - m)) % mod;
		}
		cout << ans * k % mod << "\n";
	}
	
	return 0;
}