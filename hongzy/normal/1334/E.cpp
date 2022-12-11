#include <bits/stdc++.h>
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 500 + 10;
const int mod = 998244353;
 
ll qpow(ll a, ll b) {
	ll ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int pc;
ll p[N], d, fac[N] = {1ll}, fav[N] = {1ll}, a[N], b[N];
int main() {
	for(int i = 1; i < N; i ++) {
		fac[i] = fac[i - 1] * i % mod;
		fav[i] = qpow(fac[i], mod - 2);
	}
	scanf("%lld", &d);
	for(ll i = 2; i * i <= d; i ++) {
		if(d % i == 0) {
			p[++ pc] = i;
			while(d % i == 0) d /= i;
//			printf("%d!\n", i);
		}
	}
	if(d > 1) p[++ pc] = d;
	int t; scanf("%d", &t);
	while(t --) {
		ll u, v;
		scanf("%lld%lld", &u, &v); a[0] = b[0] = 0;
//		ll g = __gcd(u, v);
		for(int i = 1; i <= pc; i ++) {
			ll tu = u, tv = v, cu = 0, cv = 0;
//			printf("%l")
			while(tu % p[i] == 0) {
				tu /= p[i]; cu ++;
			}
			while(tv % p[i] == 0) {
				tv /= p[i]; cv ++;
			}
			if(cu == cv) continue ;
			if(cu < cv) {
				a[++ a[0]] = cv - cu;
			} else {
				b[++ b[0]] = cu - cv;
			}
		}
		ll a1 = 0, b1 = 0, x = 1, y = 1;
		for(int i = 1; i <= b[0]; i ++) b1 += b[i], x = x * fav[b[i]] % mod;
		x = x * fac[b1] % mod;
		for(int i = 1; i <= a[0]; i ++) a1 += a[i], y = y * fav[a[i]] % mod;
		y = y * fac[a1] % mod;
		printf("%lld\n", x * y % mod);
	} 
	return 0;
}