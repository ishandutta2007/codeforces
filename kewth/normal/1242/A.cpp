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

int main () {
	ll n = read, x = n, las = 1;
	for (ll d = 2; d * d <= x; d ++)
		if (x % d == 0) {
			debug("%lld\n", d);
			if (las > 1) return puts("1"), 0;
			las = d;
			while (x % d == 0)
				x /= d;
		}
	if (x > 1) {
		if (las > 1) return puts("1"), 0;
		las = x;
	}
	printf("%lld\n", las);
}