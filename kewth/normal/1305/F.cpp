#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 200005;
ll a[maxn];

ll ans;
void solve (ll x, int n) {
	ll res = 0;
	for (int i = 1; i <= n; i ++) {
		ll y = a[i] % x;
		if (y == a[i]) res += x - y;
		else res += std::min(y, x - y);
	}
	/* debug("%lld : %lld\n", x, res); */
	ans = std::min(ans, res);
}

void test (ll x, int n) {
	for (ll p = 2; p * p <= x; p ++)
		if (x % p == 0) {
			solve(p, n);
			while (x % p == 0)
				x /= p;
		}
	if (x > 1)
		solve(x, n);
}

std::mt19937 rng(unsigned(std::chrono::steady_clock::now().time_since_epoch().count()));

int mrand() {
	return rand() << 15 | rand();
}

int main () {
	char *cp = new char;
	srand((unsigned)(unsigned long long)cp);
	delete cp;

	int n = read;
	for (int i = 1; i <= n; i ++)
		a[i] = read;
	/* std::random_shuffle(a + 1, a + n + 1); */
	ans = n;

	int t = 35;
	while (t --) {
        /* int i = std::uniform_int_distribution<int>(0, n - 1)(rng); */
		int i = 1 + mrand() % n;
		test(a[i] - 1, n);
		test(a[i], n);
		test(a[i] + 1, n);
	}

	printf("%lld\n", ans);
}