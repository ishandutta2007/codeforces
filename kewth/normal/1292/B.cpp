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

const int maxn = 100;
ll x[maxn], y[maxn];

int main() {
	int n = 1;
	x[1] = read;
	y[1] = read;

	int ax = read, ay = read;
	ll bx = read, by = read;

	ll X = read, Y = read, T = read;
	while(x[n] <= T + X and y[n] <= Y + T) {
		x[n + 1] = x[n] * ax + bx;
		y[n + 1] = y[n] * ay + by;
		++ n;
	}

	int ans = 0;
	for(int l = 1; l <= n; l ++)
		for(int r = l; r <= n; r ++) {
			ll d = x[r] - x[l] + y[r] - y[l];
			if(d + std::abs(X - x[l]) + std::abs(Y - y[l]) <= T or
					d + std::abs(X - x[r]) + std::abs(Y - y[r]) <= T)
				ans = std::max(ans, r - l + 1);
		}

	printf("%d\n", ans);
}