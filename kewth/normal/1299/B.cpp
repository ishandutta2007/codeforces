#if 0
date


#endif
#include <cstdio>
#include <algorithm>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

struct Num {
	int a, b;
	Num(int _a, int _b): a(_a), b(_b) {
		if(a < 0 or (a == 0 and b < 0)) {
			a = -a;
			b = -b;
		}
		// int g = std::__gcd(a, std::abs(b));
		// a /= g;
		// b /= g;
		// debug("%d %d\n", a, b);
	}
};
bool operator < (Num x, Num y) {
	// return 1ll * x.a * y.b < 1ll * y.a * x.b;
	return x.a == y.a ? x.b < y.b : x.a < y.a;
}

const int maxn = 100005;
int x[maxn], y[maxn];
std::map<Num, int> map;

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++) {
		x[i] = read;
		y[i] = read;
	}

	x[0] = x[n];
	y[0] = y[n];
	for(int i = 1; i <= n; i ++) {
		int dx = x[i] - x[i - 1];
		int dy = y[i] - y[i - 1];
		++ map[Num(dx, dy)];
		// debug("%d %d\n", dx, dy);
	}

	for(auto p : map)
		if(p.second == 1)
			return puts("No"), 0;
		else if(p.second > 2)
			return 1;
	puts("Yes");
}