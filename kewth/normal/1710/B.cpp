/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
   __  __                  __   __
  |  |/  |.-----.--.--.--.|  |_|  |--.
  |     < |  -__|  |  |  ||   _|     |
  |__|\__||_____|________||____|__|__|

 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005;
int x[maxn], y[maxn];
int a[maxn * 3];
ll H[maxn * 3];
/* struct point { */
/* 	int x, y, i; */
/* } p[maxn]; */
int L[maxn], P[maxn], R[maxn];
ll sum[maxn * 3], num[maxn * 3];

/* inline bool fcmp (FUCK f1, FUCK f2) { */
/* 	return f1.b < f2.b; */
/* } */
/* inline bool pcmp (point p1, point p2) { */
/* 	return p1.x < p2.x; */
/* } */


void merge (ll x0, ll y0, ll x1, ll y1, ll &x, ll &y) {
	if (x0 > x1) std::swap(x0, x1), std::swap(y0, y1);
	if (y1 >= y0 + (x1 - x0)) { x = x1, y = y1; return; }
	if (y1 <= y0 - (x1 - x0)) { x = x0, y = y0; return; }
	x = x1 - (y0 + x1 - x0 - y1) / 2;
	y = y0 + x1 - x0 - (y0 + x1 - x0 - y1) / 2;
}

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read, ap = 0;
		for (int i = 1; i <= n; i ++) {
			/* read(p[i].x, p[i].y); */
			/* p[i].i = i; */
			read(x[i], y[i]);
			a[++ ap] = x[i] - y[i];
			a[++ ap] = x[i];
			a[++ ap] = x[i] + y[i];
		}
		std::sort(a + 1, a + ap + 1);
		ap = int(std::unique(a + 1, a + ap + 1) - a - 1);
		/* std::sort(p + 1, p + n + 1, pcmp); */

		for (int i = 1; i <= n; i ++) {
			L[i] = int(std::lower_bound(a + 1, a + ap + 1, x[i] - y[i]) - a);
			P[i] = int(std::lower_bound(a + 1, a + ap + 1, x[i]) - a);
			R[i] = int(std::lower_bound(a + 1, a + ap + 1, x[i] + y[i]) - a);
		}

		std::fill(sum, sum + ap + 1, 0);
		std::fill(num, num + ap + 1, 0);
		for (int i = 1; i <= n; i ++) {
			sum[L[i]] += x[i] - y[i];
			num[L[i]] ++;
			sum[P[i] + 1] -= x[i] - y[i];
			num[P[i] + 1] --;
		}
		for (int i = 1; i <= ap; i ++) {
			sum[i] += sum[i - 1], num[i] += num[i - 1];
			H[i] = a[i] * num[i] - sum[i];
		}

		std::fill(sum, sum + ap + 1, 0);
		std::fill(num, num + ap + 1, 0);
		for (int i = 1; i <= n; i ++) {
			sum[P[i] + 1] += x[i] + y[i];
			num[P[i] + 1] ++;
			sum[R[i] + 1] -= x[i] + y[i];
			num[R[i] + 1] --;
		}
		for (int i = 1; i <= ap; i ++) {
			sum[i] += sum[i - 1], num[i] += num[i - 1];
			H[i] += sum[i] - a[i] * num[i];
			/* debug("%d : %lld\n", a[i], H[i]); */
		}

		ll x0 = -1, y0 = -1;
		bool begin = 1;
		for (int i = 1; i <= ap; i ++)
			if (H[i] > m) {
				ll x1 = a[i] * 2, y1 = (H[i] - m) * 2;
				/* debug("%lld %lld\n", x1, y1); */
				if (begin) x0 = x1, y0 = y1, begin = 0;
				else merge(x0, y0, x1, y1, x0, y0);
				/* debug("-> %lld %lld\n", x0, y0); */
			}
		for (int i = 1; i <= n; i ++) {
			ll tx, ty;
			if (begin) putchar('1');
			else {
				merge(x0, y0, x[i] * 2, y[i] * 2, tx, ty);
				/* debug("%d %d -> %lld %lld\n", x[i] * 2, y[i] * 2, tx, ty); */
				if (tx == x[i] * 2 and ty == y[i] * 2)
					putchar('1');
				else
					putchar('0');
			}
		}
		puts("");
	}
}