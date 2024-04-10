#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

int main() {
	int t = read;
	while(t --) {
		int n = read, a = read, b = read;
		ll l = n, r = 1000000000000000000;
		while(l < r) {
			ll m = (l + r) >> 1;
			ll x = m / (a + b), y = m % (a + b);
			if(x * a + std::min(y, ll(a)) >= (n + 1) / 2)
				r = m;
			else
				l = m + 1;
		}
		printf("%lld\n", l);
	}
}