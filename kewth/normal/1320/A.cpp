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

const int maxn = 200005;
ll sum[maxn << 2];

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++) {
		int a = read;
		sum[maxn + a - i] += a;
	}
	ll ans = 0;
	for(ll x : sum)
		ans = std::max(ans, x);
	printf("%lld\n", ans);
}