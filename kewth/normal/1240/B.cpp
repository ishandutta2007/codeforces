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

const int maxn = 300005;
int l[maxn], r[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		std::fill(l, l + n + 1, 0);
		std::fill(r, r + n + 1, 0);

		for (int i = 1; i <= n; i ++) {
			int x = read;
			if (!l[x]) l[x] = i;
			r[x] = i;
		}

		int ans = 0, max = 0;
		for (int x = 1, y = 0, now = 0; x <= n; x ++)
			if (l[x]) {
				if (r[y] < l[x]) ++ now;
				else now = 1;
				++ ans;
				max = std::max(max, now);
				y = x;
			}
		ans -= max;
		printf("%d\n", ans);
	}
}