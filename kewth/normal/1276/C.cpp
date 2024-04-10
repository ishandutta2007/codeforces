#if 0
date +%Y.%m.%d

 C  AB  /kk 
 X * Y  X <= Y 
 X 
 X  X  k  Y  k / X 
 X * Y  X 

#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 400005;
int a[maxn];
int b[maxn], c[maxn];
int ans[maxn];
par pr[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	std::sort(a + 1, a + n + 1);

	for (int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while (a[r + 1] == a[l]) ++ r;
		int len = r - l + 1;
		for (int i = 1; i <= len; i ++)
			b[i] += i;
		c[len + 1] += len;
	}

	for (int i = 1; i <= n; i ++) c[i] += c[i - 1];
	for (int i = 1; i <= n; i ++) b[i] += c[i];

	int X = 1, Y = b[X];
	for (int x = 2; x <= n; x ++) {
		int y = b[x] / x;
		if(y >= x and x * y > X * Y)
			X = x, Y = y;
	}

	int pp = 0;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while (a[r + 1] == a[l]) ++ r;
		pr[++ pp] = par(std::min(r - l + 1, X), a[l]);
	}

	std::sort(pr + 1, pr + pp + 1);

	int ap = 0;
	for (int i = pp; i; i --)
		for (int k = 0; k < pr[i].first and ap < X * Y; k ++)
			ans[ap ++] = pr[i].second;

/* 	for(int i = 0; i < ap; i ++) */
/* 		debug(" %d", ans[i]); */
/* 	debug("\n"); */

	printf("%d\n", X * Y);
	printf("%d %d\n", Y, X);
	for (int i = 0; i < Y; i ++) {
		for (int j = 0; j < X; j ++)
			printf("%d ", ans[((i + Y - j) % Y) * X + j]);
		puts("");
	}
}