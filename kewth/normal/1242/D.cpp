#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

ll key (ll p, ll k) {
	if (p == 1) return k * (k + 1) >> 1;
	ll np = (p - 1) / k + 1;
	ll l = (np - 1) * (k * k + 1) + ((p - 1) % k) * k + 1, r = l + k - 1;
	/* debug("  %lld %lld\n", l, r); */
	ll ke = key(np, k);
	ll res = (l + r) * k >> 1;
	if (l <= ke and ke <= r)
		return res - ke + r + 1;
	if (ke <= l)
		return res + k;
	return res;
}

int main () {
	int T = read;
	while (T --) {
		ll n = read, k = read;
		ll p = (n - 1) / (k * k + 1) + 1;
		ll ke = key(p, k);
		/* debug("%lld\n", ke); */
		if (n == ke)
			printf("%lld\n", (k + 1) * p);
		else {
			ll l, r;
			if (ke < n)
				l = p + 1, r = (p - 1) * k + (n - 2) % (k * k + 1) / k;
			else
				l = p, r = (p - 1) * k + (n - 1) % (k * k + 1) / k;
			/* debug("%lld %lld\n", l, r); */
			printf("%lld\n", n + (r - l + 1));
		}

		/* std::set<ll> set; */
		/* for (ll i = 1, p = 1; i <= n; p ++) { */
		/* 	ll sum = 0; */
		/* 	ll lim = k; */
		/* 	for (int j = 0; j < lim; j ++) */
		/* 		if (!set.count(i + j)) sum += i + j; */
		/* 		else ++ lim; */
		/* 	debug("%lld %lld\n", sum, key(p, k)); */
		/* 	set.insert(sum); */
		/* 	i += lim; */
		/* } */
	}
}