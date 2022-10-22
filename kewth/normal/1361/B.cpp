/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

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

const int maxn = 1000005, mod = 1000000007;
int a[maxn];

inline ll power (ll x, int k) {
	if (k < 0) k += mod - 1;
	ll res = 1;
	while (k) {
		if (k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

int main () {
	int T = read;
	while (T --) {
		int n = read, p = read;
		for (int i = 1; i <= n; i ++) read(a[i]);
		std::sort(a + 1, a + n + 1);
		ll ans = 0, d = 0;
		for (int i = n; i; i --) {
			if (i < n and p > 1 and d)
				for (int k = a[i]; k < a[i + 1] and d <= n; k ++)
					d *= p;
			if (d == 0) {
				++ d;
				ans += power(p, a[i]);
			} else {
				-- d;
				ans += mod - power(p, a[i]);
			}
		}
		ans %= mod;
		printf("%lld\n", ans);
	}
}