#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

struct KEKSUM {
	ll ks[1000005];
	int m;

	void init(ll *a, int n, int _m) {
		m = _m;
		for (int i = 0; i < n; i++) {
			ks[i+1] = a[i];
			if (i % m != 0) ks[i+1] += ks[i];
		}
	}

	ll qu(int s, int e) {
		ll res = ks[e]-ks[s];
		for (int i = 0; i < e; i += m) {
			if (s <= i) res += ks[i];
		}
		return res;
	}
};

ll y[1000005], x[1000005], v[1000005], sy[1000005], sx[1000005], tsv[1000005], ssv[1000005];
KEKSUM sv;
int n;

int main() {
	scanf("%d", &n);
	FO(i,0,n) {
		scanf("%lld %lld", y+i, x+i);
		y[i+n] = y[i]; x[i+n] = x[i];
	}
	y[2*n] = y[0]; x[2*n] = x[0];
	for (int i = 0; i < 2*n; i++) {
		v[i] = y[i+1]*x[i] - x[i+1]*y[i];
		sy[i+1] = sy[i] + y[i]; sx[i+1] = sx[i] + x[i];
		tsv[i+1] = (tsv[i] + v[i]) % MOD;
	}
	sv.init(v, 2*n, n);
	for (int i = 0; i <= 2*n; i++) ssv[i+1] = (tsv[i] + ssv[i]) % MOD;
	ll ta = sv.qu(0,n);
	ll ans = 0;

	FO(i,0,n) {
		int s = i+2, e = i+n-2;
		while (s <= e) {
			int k = (s+e)/2;
			ll ca = sv.qu(i,k) + y[i]*x[k]-x[i]*y[k];
			if (ca <= ta/2) s = k+1;
			else e = k-1;
		}
		ll A = (ssv[s] - ssv[i+2]) % MOD, B = tsv[i] * (s-i-2) % MOD, C = (sx[s] - sx[i+2]) % MOD, D = (sy[s] - sy[i+2]) % MOD, E = ta % MOD * (s-i-2) % MOD, r = (E - 2 * (A-B + y[i]*C - x[i]*D)) % MOD;
		ans += r;
		ans %= MOD;
	}
	printf("%lld\n", (ans+MOD)%MOD);
}