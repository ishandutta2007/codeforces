#if 0
date +%Y.%m.%d


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
	{ x = *this; this -> operator () (a...); }
} read;

ll solve (ll x, ll y, ll len, ll prelen) {
	if (len == 1) return y;
	/* debug("%lld %lld %lld %lld\n", x, y, len, prelen); */
	ll nlen = len >> 2;
	if (x <= nlen) {
		ll k = solve(x, y, nlen, prelen - len) - nlen * y;
		return k + len * y;
	}
	if (x <= nlen * 2) {
		ll k = solve(x - nlen, y, nlen, prelen - len) - nlen * y;
		if (y == 1) return nlen * 1 + k + len * y;
		if (y == 2) return nlen * 2 + k + len * y;
		if (y == 3) return nlen * 3 + k + len * y;
	}
	if (x <= nlen * 3) {
		ll k = solve(x - nlen * 2, y, nlen, prelen - len) - nlen * y;
		if (y == 1) return nlen * 2 + k + len * y;
		if (y == 2) return nlen * 3 + k + len * y;
		if (y == 3) return nlen * 1 + k + len * y;
	}
	if (x <= nlen * 4) {
		ll k = solve(x - nlen * 3, y, nlen, prelen - len) - nlen * y;
		if (y == 1) return nlen * 3 + k + len * y;
		if (y == 2) return nlen * 1 + k + len * y;
		if (y == 3) return nlen * 2 + k + len * y;
	}
	return 0;
}

int main () {
	int T = read;
	while (T --) {
		ll n = read;
		ll len = 1, prelen = 1;
		ll x = (n - 1) / 3 + 1, y = (n - 1) % 3 + 1;
		while (x > prelen) prelen += (len *= 4);
		printf("%lld\n", solve(x - (prelen - len), y, len, prelen));
	}
}