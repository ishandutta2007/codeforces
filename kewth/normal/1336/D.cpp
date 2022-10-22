#if 0
2020.04.24

  

  n - 1, ...  3, 1, 2, 1  1 
 a[1] 
   1  a[2] (a[3] + 1) 
(a[2] + 1) (a[3] + 1)  a[3]  (a[3]+1>0)  a[2] 
   x  a[1]  a[x + 1] 
 x  a[x + 2] 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 105;
int a[maxn];
int ans[maxn];

int main () {
	int n = read;
	int las = read;
	read(a[n]);
	for (int i = n - 1; i >= 3; i --) {
		printf("+ %d\n", i), fflush(stdout);
		las = read;
		read(a[i]);
	}

	printf("+ %d\n", 1), fflush(stdout);
	int d1 = read - las;
	/* las += d1; */
	read(a[1]);

	printf("+ %d\n", 2), fflush(stdout);
	las = read;
	read(a[2]);

	printf("+ %d\n", 1), fflush(stdout);
	int d2 = read - las;
	/* las += d2; */
	read(a[0]);

	for (int x = 0; x <= n; x ++)
		if (x * (x - 1) / 2 == d1 and x * (x + 1) / 2 == d2)
			ans[1] = x;

	d1 = a[1] - a[3];
	d2 = a[0] - a[2];
	ans[3] = d2 - d1 - 1;
	ans[2] = d1 / (ans[3] + 1);

	int d = a[2] - a[1] - (ans[1] + 1) * (ans[3] + 1);
	ans[4] = d / (ans[3] + 1) - 1;
	for (int x = 3; x + 2 <= n; x ++) {
		d = a[x] - a[x + 1] - ans[x - 2] * ans[x - 1] - ans[x - 1] * (ans[x + 1] + 1);
		ans[x + 2] = d / (ans[x + 1] + 1) - 1;
	}
	++ ans[n];

	printf("!");
	for (int i = 1; i <= n; i ++)
		printf(" %d", ans[i]);
	puts("");
}