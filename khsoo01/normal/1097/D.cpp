#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7, Z = 105;

ll n, m, dt1[Z], dt2[Z], ans = 1;

ll fac[Z] = {1}, inv[Z] = {1};

ll calc (ll A, ll B) {
	if(!B) return 1;
	ll R = calc(A, B/2);
	R = (R * R) % mod;
	if(B%2) R = (R * A) % mod;
	return R;
}

ll solve (ll A, ll B) {
	for(ll i=0;i<=B;i++) {
		dt1[i] = 0;
		dt2[i] = 1;
	}
	dt1[B] = 1;
	for(ll k=1;k<=m;k++) {
		for(ll i=0;i<=B;i++) {
			ll T = 0;
			for(ll j=i;j<=B;j++) {
				T = (T + dt1[j] * fac[B+1] % mod * inv[j+1] % mod) % mod;
			}
			dt1[i] = T;
			dt2[i] = dt2[i] * fac[B+1] % mod;
		}
	}
	ll R = 0, C = 1;
	for(ll i=0;i<=B;i++) {
		R = (R + dt1[i] * C) % mod;
		C = (C * A) % mod;
	}
	return (R * calc(dt2[0], mod-2)) % mod;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<Z;i++) {
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = calc(i, mod-2);
	}
	for(ll i=2;i*i<=n;i++) {
		ll C = 0;
		while(n%i == 0) {
			C++;
			n /= i;
		}
		if(C > 0) {
			ans = (ans * solve(i%mod, C)) % mod;
		}
	}
	ans = (ans * solve(n%mod, 1)) % mod;
	printf("%lld\n",ans);
}