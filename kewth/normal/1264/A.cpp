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

const int maxn = 400005;
int a[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++)
			a[i] = read;
		a[n + 1] = -1;
		int m = 1;
		while (a[m + 1] == a[1])
			++ m;
		int k = m + m + 1;
		if (k > n) {
			puts("0 0 0");
			continue;
		}
		while (a[k + 1] == a[m + m + 1])
			++ k;
		int q = k + m + 1;
		if (q > n) {
			puts("0 0 0");
			continue;
		}
		while (a[q + 1] == a[k + m + 1])
			++ q;
		if (q > n / 2) {
			puts("0 0 0");
			continue;
		}
		while (1) {
			int p = q + 1;
			while (a[p + 1] == a[q + 1])
				++ p;
			if (p <= n / 2)
				q = p;
			else
				break;
		}
		printf("%d %d %d\n", m, k - m, q - k);
	}
}