#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MT make_tuple
#define PB push_back
typedef long long ll;

ll N, C, ans, p=1;

#define MOD 1000003

ll fac[1100100];

ll inv (ll a) {
	ll r = 1, e = MOD-2;
	while (e) {
		if (e&1) r = r * a % MOD;
		e /= 2, a = a * a % MOD;
	}
	return r;
}

ll comb (ll n, ll k) {
	ll res = fac[n];
	res = (res * inv(fac[k])) % MOD;
	res = (res * inv(fac[n-k])) % MOD;
	return res;
}

int main () {
	fo(i, 0, 1100100) fac[i] = i ? fac[i-1] * i % MOD : 1;
	cin >> N >> C;
	for (ll u = 1; u <= N; u++) {
		ans = (ans + comb(u + C - 1, u)) % 1000003;
	}
	printf("%lld\n", ans);
	return 0;
}