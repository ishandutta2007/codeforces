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
#include <bitset>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 2020;
int p[maxn << 1];
int a[maxn << 1], ap;
std::bitset<maxn> f;

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n * 2; i ++) read(p[i]);
		ap = 0;
		for (int l = 1, r; l <= n * 2; l = r + 1) {
			r = l;
			while (r + 1 <= n * 2 and p[r + 1] < p[l]) ++ r;
			a[++ ap] = r - l + 1;
		}
		f.reset();
		f.set(0);
		for (int i = 1; i <= ap; i ++)
			f = f | (f << si(a[i]));
		if (f.test(si(n))) puts("YES");
		else puts("NO");
	}
}