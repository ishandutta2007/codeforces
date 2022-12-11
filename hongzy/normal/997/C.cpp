#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MOD = 998244353;
const int N = 1e6 + 10;

int n;
LL fac[N], fav[N];

LL qpow(LL a, LL b) {
	LL ans = 1;
	for(; b; b >>= 1, a = a * a % MOD)
		if(b & 1) ans = ans * a % MOD;
	return ans;
}

void init(int n) {
	fac[0] = 1;
	for(LL i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for(LL i = n; i >= 1; i --)
		fav[i - 1] = fav[i] * i % MOD;
}

LL C(LL n, LL m) {
	return fac[n] * fav[m] % MOD * fav[n - m] % MOD;
}
LL pw(LL x) { return x & 1 ? -1ll : 1ll; }

int main() {
	scanf("%d", &n);
	init(n);
	LL ans = 0, ans2 = 0;
	for(LL i = 1; i <= n; i ++) {
		ans = (ans + C(n, i) * pw(i + 1) * qpow(3, n * (n - i) + i) % MOD) % MOD;
	}
	ans = ans * 2ll % MOD;
	for(LL i = 0; i < n; i ++) {
		LL x = (1 - qpow(3, i) + MOD) % MOD;
		LL y = ((qpow(x, n) - qpow(- qpow(3, i), n)) % MOD + MOD) % MOD;
		ans2 = (ans2 + C(n, i) * pw(i + 1) * y % MOD) % MOD; 
	}
	ans2 = ans2 * 3ll % MOD;
	printf("%lld\n", ((ans + ans2) % MOD + MOD) % MOD);
	return 0;
}