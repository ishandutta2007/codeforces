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
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005;
int a[3][maxn];

int main() {
	int n = read, q = read;

	int tot = 0;
	while(q --) {
		int x = read, y = read, z = 3 - x;
		int t = a[z][y - 1] + a[z][y] + a[z][y + 1];

		if(a[x][y]) {
			a[x][y] = 0;
			tot -= t;
		} else {
			a[x][y] = 1;
			tot += t;
		}

		if(tot) puts("No");
		else puts("Yes");
	}
}