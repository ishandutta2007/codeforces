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

int main() {
	int t = read;
	while(t --) {
		int x = read, y = read, a = read, b = read;
		if((y - x) % (a + b) == 0)
			printf("%d\n", (y - x) / (a + b));
		else
			puts("-1");
	}
}