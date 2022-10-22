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
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 1000005;
int min[maxn], tmax[maxn];

int main() {
	int n = read;

	for(int i = 1; i <= n; i ++) {
		int l = read;
		int nmin = 1000000000, nmax = 0;
		while(l --) {
			int x = read;
			if(x > nmin) nmin = -1, nmax = 1000001;
			else nmin = std::min(nmin, x), nmax = std::max(nmax, x);
		}
		min[i] = nmin;
		++ tmax[nmax];
	}

	for(int x = 1000001; x >= 0; x --)
		tmax[x] += tmax[x + 1];

	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += tmax[min[i] + 1];
	printf("%lld\n", ans);
}