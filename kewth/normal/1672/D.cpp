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
int a[maxn], b[maxn];
int tmp[maxn];
int nxt[maxn];
int head[maxn];
int valpointer[maxn];

/* int AD = 0; */
bool solve () {
	int n = read;
	std::fill(tmp, tmp + n + 2, 0);
	std::fill(nxt, nxt + n + 2, 0);
	std::fill(head, head + n + 2, 0);
	std::fill(valpointer, valpointer + n + 2, 0);
	for (int i = 1; i <= n; i ++) tmp[i] = a[i] = read;
	for (int i = 1; i <= n; i ++) read(b[i]);
	std::sort(tmp + 1, tmp + n + 1);
	for (int i = 1; i <= n; i ++)
		a[i] = int(std::lower_bound(tmp + 1, tmp + n + 1, a[i]) - tmp);
	for (int i = n; i; i --) {
		nxt[i] = valpointer[a[i]];
		head[a[i]] = valpointer[a[i]] = i;
	}
	int begin = 1;
	for (int i = 1; i <= n; i ++) {
		int x = int(std::lower_bound(tmp + 1, tmp + n + 1, b[i]) - tmp);
		if (x == n + 1 or tmp[x] != b[i]) return 0;
		if (!valpointer[x]) return 0;
		int h = head[x];
		if (!h) return 0;
		for (int &k = begin; k < h; k ++) {
			if (!nxt[k]) return 0;
			head[a[k]] = nxt[k];
		}
		if (valpointer[x] == h) {
			valpointer[x] = nxt[valpointer[x]];
			head[x] = nxt[head[x]];
			begin ++;
		}
		else {
			valpointer[x] = nxt[valpointer[x]];
		}
	}
	return 1;
}

int main () {
	int T = read;
	while (T --) {
		puts(solve() ? "YES" : "NO");
	}
}