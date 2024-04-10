#if 0
date +%Y.%m.%d

 ((((((....)))))) 


 p  p 
 p 

 l x  r y 

 sum(C(a, i) * C(b, c - i)) = C(a + b, c) 
#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 1000005, mod = 998244353;
char s[maxn];
ll fac[maxn], ifac[maxn];

inline ll power(ll x, int k) {
	if(k < 0) k += mod - 1;
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

inline ll C(int n, int m) {
	if (m < 0 or m > n) return 0;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int X[maxn], Y[maxn], L[maxn], R[maxn];

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = power(fac[n], -1);
	for (int i = n; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;

	for (int i = 1; i < n; i ++) X[i] = X[i - 1] + (s[i] == '?');
	for (int i = 1; i < n; i ++) L[i] = L[i - 1] + (s[i] == '(');
	for (int i = n; i > 1; i --) Y[i - 1] = Y[i] + (s[i] == '?');
	for (int i = n; i > 1; i --) R[i - 1] = R[i] + (s[i] == ')');

	ll ans = 0;
	for (int i = 1; i < n; i ++)
		(ans += L[i] * C(X[i] + Y[i], Y[i] + R[i] - L[i]) +
			X[i] * C(X[i] + Y[i] - 1, Y[i] + R[i] - L[i] - 1)) %= mod;
	printf("%lld\n", ans);
}