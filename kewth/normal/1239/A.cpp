#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005, mod = 1000000007;
ll f[maxn][2];

int main () {
	int n = read, m = read;
	f[1][0] = 2;
	for (int i = 2; i <= n or i <= m; i ++) {
		f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
		f[i][1] = f[i - 1][0];
	}
	printf("%lld\n", (f[n][0] + f[n][1] + f[m][0] + f[m][1] + mod - 2) % mod);
}