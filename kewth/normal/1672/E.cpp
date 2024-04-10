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

const int maxn = 2020, Max = 2000, inf = 1000000000;

int query (int w) {
	printf("? %d\n", w);
	fflush(stdout);
	int h = read;
	return h == 0 ? inf : h;
}

/* int H[maxn]; */
/* void solve (int h1, int h2, int w1, int w2) { */
/* 	int hmid = (h1 + h2) >> 1; */
/* 	int wmid = (w1 + w2) >> 1; */
/* 	int h = query(wmid); */
/* 	/1* H[h] = wmid; *1/ */
/* } */

int main () {
	int n = read;

	int l = 1, r = 1000000000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (query(mid) > 1)
			l = mid + 1;
		else
			r = mid;
	}
	int W = l;

	int ans = 1000000000;
	for (int h = 1; h <= n; h ++) {
		int w = W / h;
		int _h = query(w);
		if (_h <= h)
			ans = std::min(ans, _h * w);
	}
	printf("! %d\n", ans);
}