//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, ans, p[maxn], c[maxn], f[maxn], fp[maxn], d[maxn], a[maxn];

ll po(ll x, ll y){
	if(y == 0) return 1;
	ll z = po(x, y / 2);
	z = (z * z) % mod;
	if(y % 2) z = (z * x) % mod;
	return z;
}

ll inv(ll x){
	return po(x, mod - 2);
}

ll C(ll x, ll y){
	if(x < y) return 0;
	return (((f[x] * fp[y]) % mod) * fp[x - y]) % mod;
}

int main(){
	ll x, y;
	fast_io;
	
	for(ll i = 2; i < maxn; i++){
		if(p[i] == 0){
			p[i] = i;
			for(ll j = i * i; j < maxn; j += i){
				p[j] = i;
			}
		}
	}
	
	c[1] = 1;
	
	for(ll i = 2; i < maxn; i++){
		ll j = i;
		x = p[i];
		y = 1;
		while(j % x == 0){
			j /= x;
			y++;
		}
		c[i] = y * c[j];
	}
	
	f[0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
	}
	
	for(ll i = 0; i < maxn; i++){
		fp[i] = inv(f[i]);
	}
	
	d[1] = 1;
	for(ll i = 1; i < maxn; i++){
		a[i] += d[1];
	}
	
	for(ll i = 2; i < maxn; i++){
		d[i] = -a[i];
		for(ll j = i; j < maxn; j += i){
			a[j] += d[i];
		}
	}
	
	cin >> q;
	
	while(q--){
		cin >> n >> m;
		ans = 0;
		for(ll i = 1; i * i <= n; i++){
			if(n % i == 0){
				ans = (ans + d[i] * C(n / i - 1, m - 1)) % mod;
				if(i != n / i){
					ans = (ans + d[n / i] * C(i - 1, m - 1)) % mod;
				}
			}
		}
		cout << (ans + mod) % mod << '\n';
	}
	
	return 0;
}