/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
   (1, 2) -> (n - 1, m)  (2, 3) -> (n, m - 1) 
 DP 

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 3030, mod = 1000000007;
char s[maxn][maxn];
ll f[maxn][maxn];

ll path (int lx, int ly, int rx, int ry) {
	for (int x = lx - 1; x <= rx; x ++)
		for (int y = ly - 1; y <= ry; y ++)
			f[x][y] = 0;
	f[lx - 1][ly] = 1;
	for (int x = lx; x <= rx; x ++)
		for (int y = ly; y <= ry; y ++)
			f[x][y] = s[x][y] == '#' ? 0 : (f[x - 1][y] + f[x][y - 1]) % mod;
	return f[rx][ry];
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	printf("%lld\n", (path(1, 2, n - 1, m) * path(2, 1, n, m - 1) +
				(mod - path(1, 2, n, m - 1)) * path(2, 1, n - 1, m)) % mod);
}