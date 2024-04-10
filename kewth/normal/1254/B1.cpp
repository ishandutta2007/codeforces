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

const int maxn = 1000005;
ll a[maxn];

ll ans = 1000000000000000000;
void force (int, ll x, ll sum) {
	ll res = 0;
	for (int l = 1, r; sum; l = r + 1) {
		ll now = a[l];
		r = l;
		while (now < x) now += a[++ r];
		sum -= x;
		int p = l;
		ll pre = a[l];
		while (pre < x - pre) pre += a[++ p];
		for (int i = l; i <= r; i ++)
			res += a[i] * std::abs(i - p);
	}
	ans = std::min(ans, res);
}

int main () {
	int n = read;
	ll sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += a[i] = read;

	if (sum == 1) return puts("-1"), 0;

	for (ll d = 1; d * d <= sum; d ++)
		if (sum % d == 0) {
			if (d > 1) force(n, d, sum);
			if (d * d < sum) force(n, sum / d, sum);
		}

	printf("%lld\n", ans);
}