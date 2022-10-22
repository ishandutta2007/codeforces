#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 5050;
ll f[maxn], g[maxn];
int x[maxn];
int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
	int n = read, s = read, t = read;

	for(int i = 1; i <= n; i ++) x[i] = read;
	for(int i = 1; i <= n; i ++) a[i] = read + x[i];
	for(int i = 1; i <= n; i ++) b[i] = read - x[i];
	for(int i = 1; i <= n; i ++) c[i] = read + x[i];
	for(int i = 1; i <= n; i ++) d[i] = read - x[i];

	for(int j = 0; j <= n; j ++)
		f[j] = 1000000000000000000;
	f[0] = 0;

	for(int i = 1; i <= n; i ++) {
		std::swap(f, g);
		for(int j = 0; j <= n; j ++)
			f[j] = 1000000000000000000;

		for(int j = 1; j <= i; j ++) {
			auto update = [&](ll x) { f[j] = std::min(f[j], x); };

			if(i == s) {
				update(g[j] + c[i]);
				update(g[j - 1] + d[i]);
			} else if(i == t) {
				update(g[j] + a[i]);
				update(g[j - 1] + b[i]);
			}

			else {
				if(j > (i > t))
					update(g[j] + a[i] + d[i]);
				update(g[j + 1] + a[i] + c[i]);
				if(j > (i > s))
					update(g[j] + b[i] + c[i]);
				if(i < s or i < t or j > 2)
					update(g[j - 1] + b[i] + d[i]);
			}
		}

		// for(int j = 0; j <= n; j ++)
			// if(f[j] < 1000000000000000000)
				// debug("f[%d][%d] = %lld\n", i, j, f[j]);
	}

	printf("%lld\n", f[1]);
}