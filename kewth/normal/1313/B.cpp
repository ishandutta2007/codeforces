#if 0
date


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
	int q = read;
	while(q --) {
		int n = read, a = read, b = read;
		
		int x = std::min(a - 1, std::max(n - b - 1, 0));
		int y = std::min(b - 1, std::max(n - a - 1, 0));
		// int x = std::min(a - 1, n - b - 1);
		// int y = std::min(b - 1, n - a - 1);

		int a0 = a - 1 - x;
		int a1 = n - a - y;
		int b0 = b - 1 - y;
		int b1 = n - b - x;
		int ans1 = n - (x + y + std::min(a1, b1));

		x = std::min(a - 1, n - b);
		y = std::min(b - 1, n - a);

		a0 = a - 1 - x;
		a1 = n - a - y;
		b0 = b - 1 - y;
		b1 = n - b - x;
		int ans2 = x + y + 1 + std::min(a0, b0);

		printf("%d %d\n", ans1, ans2);
	}
}