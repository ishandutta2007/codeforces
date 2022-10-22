#if 0
date +%Y.%m.%d

   y  x 
   y  [ky, ky + y)  cnt 
 y 
   x  y  y * min(x, c)  c 
2  x  y 
   x  a  2x mod y > a mod y 
 x  c  2x mod y <= a mod y  2x 
 a  a >= 2x  a mod y  2x 
 a 
   x  a >= x  a mod y
 x  a mod y 
        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 500005;
int tot[maxn];
int pre[maxn], las[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) ++ tot[read];
	n = 500000;
	while (!tot[n]) -- n;

	for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + tot[i];
	las[0] = -1;
	for (int i = 1; i <= n; i ++) las[i] = tot[i] ? i : las[i - 1];

	ll ans = 0;
	for (int y = 2; y <= n; y ++) {
		ll cnt = 0;
		int lim = 0;
		for (int k = 0; k * y <= n; k ++) {
			int l = k * y, r = std::min(k * y + y - 1, n);
			cnt += 1ll * k * (pre[r] - (l ? pre[l - 1] : 0));
			lim = k;
		}

		/* debug("y = %d (cnt = %lld)\n", y, cnt); */

		int max = -1, semax = -1;
		for (int k = lim; k >= 0; k --) {
			int l = k * y, r = std::min(k * y + y - 1, n);
			int a = -1, b = -1;
			if (las[r] >= l) {
				a = las[r] % y;
				b = tot[las[r]] > 1 ? a :
					(las[las[r] - 1] >= l ? las[las[r] - 1] % y : -1);
				if (a > max) semax = max, max = a;
				else if (a > semax) semax = a;
				semax = std::max(semax, b);
			}
			/* if (y == 3 and k == 0) debug("%d %d\n", semax, max); */
			if (max >= 0) {
				ll x = std::min<ll>((l + max) >> 1, cnt - k);
				if (x >= 2)
					/* debug(" x = %lld (t1)\n", x), */
					ans = std::max(ans, y * x);
			}
			if (max >= 0 and pre[n] - pre[l + max - 1] >= 2) {
				ll x = std::min<ll>(l + max, cnt - k - k - 1);
				if (x >= 2)
					/* debug(" x = %lld (t2)\n", x), */
					ans = std::max(ans, y * x);
			}
			if (semax >= 0) {
				ll x = std::min<ll>(l + semax, cnt - k - k);
				if (x >= 2)
					/* debug(" x = %lld (t3)\n", x), */
					ans = std::max(ans, y * x);
			}
		}
	}

	printf("%lld\n", ans);
}