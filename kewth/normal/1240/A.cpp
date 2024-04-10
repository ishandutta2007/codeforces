#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <functional>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005;
int p[maxn];
int f[maxn], g[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++)
			p[i] = int(read) / 100;
		std::sort(p + 1, p + n + 1, std::greater<int> ());

		int x = read, a = read;
		int y = read, b = read;
		ll k = read;

		std::fill(f, f + n + 1, 0);
		for (int i = a; i <= n; i += a) f[i] += x;
		for (int i = b; i <= n; i += b) f[i] += y;

		int l = 1, r = n + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			std::copy(f, f + mid + 1, g);
			std::sort(g + 1, g + mid + 1, std::greater<int> ());
			ll now = 0;
			for (int i = 1; i <= mid; i ++)
				now += g[i] * p[i];
			if (now >= k)
				r = mid;
			else
				l = mid + 1;
		}

		printf("%d\n", l > n ? -1 : l);
	}
}