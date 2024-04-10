/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 200005;
int a[maxn], b[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int k = 0; k < 20; k ++) {
		int tot = 0;
		for (int i = 1; i <= n; i ++) tot += a[i] >> k & 1;
		for (int i = 1; i <= tot; i ++) b[i] |= 1 << k;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i ++) ans += 1ll * b[i] * b[i];
	printf("%lld\n", ans);
}