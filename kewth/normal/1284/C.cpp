#if 0
2020.01.04


 l  x  x - l + 1  x 
 n  l  n - l + 1 
 l!  (n - l)! 
 l, x  O(n^2)  l  x 
 l  x  (n - l + 1) 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 250005;
int p[maxn];
ll fac[maxn];

int main() {
	int n = read, mod = read;

	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;

	ll ans = 0;
	for(int l = 1; l <= n; l ++)
		(ans += fac[l] * fac[n - l] % mod * (n - l + 1) % mod * (n - l + 1)) %= mod;
	printf("%lld\n", ans);
}