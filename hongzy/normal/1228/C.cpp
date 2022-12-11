#include <algorithm>
#include <cstdio>
using namespace std;
 
typedef long long ll;
 
const int N = 4e5 + 20;
const ll mo = 1e9 + 7;
ll qpow(ll a, ll b) {
	ll ans = 1;
	for( ; b >= 1; b >>= 1, a = a * a % mo)
		if(b & 1) ans = ans * a % mo;
	return ans;
}
ll x, n, p[N], c;
int main() {
	scanf("%I64d%I64d", &x, &n);
	for(ll i = 2; i * i <= x; i ++) {
		if(x % i == 0) {
			p[++ c] = i;
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) p[++ c] = x;
	ll res = 1;
	for(int i = 1; i <= c; i ++) {
		ll pn = p[i];
		for(int j = 1; j <= 64; j ++) {
			ll now = n / pn;
			if(pn <= n / p[i]) now -= n / (p[i] * pn);
			res = res * qpow(pn % mo, now) % mo;
			if(pn > n / p[i]) break ;
			pn *= p[i];
		}
		
	}
	printf("%I64d\n", ((res % mo) + mo) % mo);
	return 0;
}