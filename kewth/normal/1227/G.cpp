#if 0
2020.03.24


 n + 1  (n + 1) * n 
 a  a[i]  (i, i)  1  a[i] 
 (x, y)  ((x - 1) % (n + 1), y) 

#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1010;
struct shit { int x, id; } a[maxn];
bool b[maxn][maxn];

int main () {
	int n = read;
	for (int i = 0; i < n; i++)
		a[i] = {read, i};
	std::sort(a, a + n, [] (shit x, shit y) { return x.x < y.x; });

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < a[i].x; j ++)
			b[(i - j + n + 1) % (n + 1)][a[i].id] = 1;

	printf("%d\n", n + 1);
	for (int i = 0; i < n + 1; i ++) {
		for (int j = 0; j < n; j ++)
			printf("%d", b[i][j]);
		puts("");
	}
}