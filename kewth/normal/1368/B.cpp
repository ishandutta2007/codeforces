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
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

char s[] = "codeforces";
int main () {
	ll k = read, kk = 1;
	int l = int(std::pow(k, 0.1L)), p = 0;
	for (int i = 0; i < 10; i ++) kk *= l;
	while (kk < k) kk /= l, kk *= l + 1, ++ p;
	for (int i = 0; i < 10; i ++)
		for (int j = 0; j < (i < p ? l + 1 : l); j ++)
			putchar(s[i]);
	puts("");
}