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
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

int main () {
	int n = read;
	printf("%d\n", 4 + 3 * n);
	printf("%d %d\n", 0, 0);
	printf("%d %d\n", 0, 1);
	for (int i = 1; i <= n; i ++) {
		printf("%d %d\n", i, i);
		printf("%d %d\n", i, i - 1);
		printf("%d %d\n", i, i + 1);
	}
	printf("%d %d\n", n + 1, n);
	printf("%d %d\n", n + 1, n + 1);
}