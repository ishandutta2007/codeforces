#if 0
date +%Y.%m.%d


        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
struct shit {
	int x, y;
} a[maxn], b[maxn];
ll ans[maxn << 1];
int c[maxn];

bool cmp (shit A, shit B) { return A.x < B.x; }

int main () {
	int m = read, n = read;
	for (int i = 1; i <= n; i ++) a[i] = {read, i};
	for (int i = 1; i <= n; i ++) b[i] = {read, i};

	std::sort(a + 1, a + n + 1, cmp);
	std::sort(b + 1, b + n + 1, cmp);
	int s = m >> 1;

	auto add1 = [n] (int i, int l, int r, int x) {
		l += n - i;
		r += n - i;
		if (l > r) return;
		ans[l] += x;
		ans[r + 1] -= x;
	};

	for (int i = 1, l = 1, r = 0, R = 0; i <= n; i ++) {
		while (l <= n and a[l].x < b[i].x - s)
			++ l;
		while (r < n and a[r + 1].x <= b[i].x)
			++ r;
		while (R < n and a[R + 1].x <= b[i].x + s)
			++ R;
		add1(i, 1, l - 1, m - b[i].x);
		add1(i, l, r, b[i].x);
		add1(i, r + 1, R, - b[i].x);
		add1(i, R + 1, n, b[i].x);
		/* debug("%d %d %d\n", l, r, R); */
	}

	auto add2 = [n] (int i, int l, int r, int x) {
		l = i + n - l;
		r = i + n - r;
		std::swap(l, r);
		if (l > r) return;
		ans[l] += x;
		ans[r + 1] -= x;
	};

	for (int i = 1, l = 1, r = 0, R = 0; i <= n; i ++) {
		while (l <= n and b[l].x < a[i].x - s)
			++ l;
		while (r < n and b[r + 1].x < a[i].x)
			++ r;
		while (R < n and b[R + 1].x <= a[i].x + s)
			++ R;
		add2(i, 1, l - 1, m - a[i].x);
		add2(i, l, r, a[i].x);
		add2(i, r + 1, R, - a[i].x);
		add2(i, R + 1, n, a[i].x);
		/* debug("%d %d %d\n", l, r, R); */
	}

	for (int i = 1; i <= n * 2; i ++)
		ans[i] += ans[i - 1];
	for (int i = 1; i <= n; i ++)
		ans[i] += ans[n + i];

	/* for (int i = 1; i <= n; i ++) */
	/* 	debug("%lld\n", ans[i]); */

	int of = 1;
	for (int i = 1; i <= n; i ++)
		if (ans[i] < ans[of])
			of = i;

	for (int i = 1; i <= n; i ++)
		c[a[(of + i - 1) % n + 1].y] = b[i].y;
		/* c[b[i].y] = a[(of + i - 1) % n + 1].y; */

	printf("%lld\n", ans[of]);
	for (int i = 1; i <= n; i ++)
		printf("%d ", c[i]);
	puts("");
}