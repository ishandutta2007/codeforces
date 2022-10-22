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

const int maxn = 300005;
int a[maxn];

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		read(a[i]);

	/* ll ans = 0; */
	/* int need = 0, nowlen = 0; */
	/* for(int l = 1, r; l <= n; l = r + 1) { */
	/* 	r = l; */
	/* 	while(a[r + 1] == a[l]) ++ r; */
	/* 	int len = r - l + 1; */
	/* 	ans += 1ll * a[l] * len >> 1; */
	/* 	if(!(len & 1) or !(a[l] & 1)) */
	/* 		nowlen += len; */
	/* 	else { */
	/* 		if(need) { */
	/* 			if(!(nowlen & 1)) { */
	/* 				++ ans; */
	/* 				need = 0; */
	/* 			} */
	/* 		} else */
	/* 			need = 1; */
	/* 		nowlen = 0; */
	/* 	} */
	/* } */

	/* printf("%lld\n", ans); */

	ll x = 0, y = 0;
	for(int i = 1; i <= n; i ++) {
		if(i & 1) {
			x += a[i] >> 1;
			y += (a[i] + 1) >> 1;
		} else {
			x += (a[i] + 1) >> 1;
			y += a[i] >> 1;
		}
	}

	printf("%lld\n", std::min(x, y));
}