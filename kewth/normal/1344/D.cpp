#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
/* typedef __int128 lll; */
/* typedef std::pair<lll, int> par; */

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
int a[maxn], b[maxn], c[maxn];

/* lll f (int i, ll x) { */
/* 	return lll(x) * (a[i] - x * x); */
/* } */

ll R (int i, ll x) {
	return - 3 * x * x - 3 * x + a[i] - 1;
}

ll L (int i, ll x) {
	return + 3 * x * x - 3 * x - a[i] + 1;
}

bool check (int n, ll x, ll d) {
	if (d < 0) {
		for (int i = 1; i <= n; i ++) {
			int l = 0, r = b[i];
			while (l < r) {
				int mid = (l + r) >> 1;
				if (L(i, mid + 1) >= x) r = mid;
				else l = mid + 1;
			}
			c[i] = l;
		}
		for (int i = 1; i <= n; i ++)
			d += b[i] - c[i];
		return d >= 0;
	}
	if (d > 0) {
		for (int i = 1; i <= n; i ++) {
			int l = b[i], r = a[i];
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (R(i, mid - 1) >= x) l = mid;
				else r = mid - 1;
			}
			c[i] = r;
		}
		for (int i = 1; i <= n; i ++)
			d += b[i] - c[i];
		return d <= 0;
	}
	return 0;
}

int main () {
	int n = read;
	ll k = read;
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
		b[i] = int(sqrt(a[i] / 3));
		while (b[i] > 0 and L(i, b[i]) > 0) -- b[i];
		while (b[i] < a[i] and R(i, b[i]) > 0) ++ b[i];
		k -= b[i];
	}

	if (k == 0) {
		for (int i = 1; i <= n; i ++)
			printf("%d ", b[i]);
		puts("");
		return 0;
	}

	ll l = - 4000000000000000000, r = 0;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (check(n, mid, k)) l = mid;
		else r = mid - 1;
	}

	check(n, l, k);
	for (int i = 1; i <= n; i ++)
		k += b[i] - c[i];
	for (int i = 1; i <= n; i ++) {
		while (k < 0 and c[i] > 0 and R(i, c[i] - 1) == l)
			-- c[i], ++ k;
		while (k > 0 and c[i] < a[i] and L(i, c[i] + 1) == l)
			++ c[i], -- k;
	}

	for (int i = 1; i <= n; i ++)
		printf("%d ", c[i]);
}