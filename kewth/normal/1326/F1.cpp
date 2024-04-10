#pragma GCC optimize(2)
#if 0
2020.03.25



 A  B  A 
 B[S] 

B[S] 
 B[S], B[T]  S, T  B[S] = B[T] 
 n  B[S] 

 f[S]  S 
 f 
 f 
 n 


 O(K 2^n n + 2^n n^2)  K  n 
 O(K 2^n + 2^n n^2) 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator bool () {
		int c = getchar(); while (c != '0' and c != '1') c = getchar();
		return c == '1';
	}
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 19;
bool link[maxn][maxn];
ll Ans[1 << maxn], f[maxn][1 << maxn], g[1 << maxn][maxn], tmp[1 << maxn];

void FWT_or (ll *a, int n, int x) {
	for (int m = 1; m < n; m <<= 1)
		for (int i = 0; i < n; i += m << 1)
			for (int k = i; k < i + m; k ++)
				a[k + m] += a[k] * x;
}

void iFMT (ll *a, int n) {
	for (int m = 1; m < n; m <<= 1)
		for (int i = 0; i < n; i += m << 1)
			for (int k = i; k < i + m; k ++)
				a[k] -= a[k + m];
}

int a[maxn];

ll solve (int n, int p) {
	/* debug("solve"); */
	/* for (int i = 0; i < p; i ++) debug(" %d", a[i]); */
	/* debug("\n"); */
	std::fill(tmp, tmp + (1 << n), 1);
	for (int i = 0; i < p; i ++)
		for (int S = 0; S < (1 << n); S ++)
			tmp[S] *= f[a[i]][S];
	FWT_or(tmp, 1 << n, -1);
	/* debug("get %lld\n", tmp[(1 << n) - 1]); */
	return tmp[(1 << n) - 1];
}

int main () {
	int n = read;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			read(link[i][j]);

	f[0][0] = 1;
	for (int S = 0; S < (1 << n); S ++) {
		int tot = 0;
		for (int i = 0; i < n; i ++) tot += S >> i & 1;
		for (int i = 0; i < n; i ++)
			if (S >> i & 1) {
				int T = S ^ (1 << i);
				if (T == 0)
					g[S][i] = 1;
				for (int j = 0; j < n; j ++)
					if (T >> j & 1 and link[i][j])
						g[S][i] += g[T][j];
				f[tot][S] += g[S][i];
			}
		/* debug("f[%d] = %lld\n", S, f[tot][S]); */
	}

	for (int i = 0; i < n; i ++)
		FWT_or(f[i], 1 << n, 1);

	for (int S = 0; S < (1 << n >> 1); S ++) {
		int p = 1;
		a[0] = 1;
		for (int i = 0; i < n - 1; i ++)
			S >> i & 1 ? ++ a[p - 1] : a[p ++] = 1;
		bool first = 1;
		for (int i = 0; i < p - 1; i ++)
			first &= a[i] >= a[i + 1];
		if (first) Ans[S] = solve(n, p);
		else {
			std::sort(a, a + p, [] (int x, int y) { return x > y; });
			int T = (1 << n) - 1, pre = 0;
			for (int i = 0; i < p; i ++)
				T ^= 1 << (pre += a[i]) >> 1;
			/* debug("%d -> %d\n", S, T); */
			Ans[S] = Ans[T];
		}
	}

	iFMT(Ans, 1 << n >> 1);
	for (int S = 0; S < (1 << n >> 1); S ++)
		printf("%lld ", Ans[S]);
	puts("");
}