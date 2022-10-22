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
} read;

const int maxn = 200005;
int ls[maxn], rs[maxn];
int f[maxn];


inline bool chkmax(int &x, int y) {
	if(y > x) return x = y, 1;
	return 0;
}

inline bool chkmin(int &x, int y) {
	if(y < x) return x = y, 1;
	return 0;
}

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read;
		std::fill(ls, ls + n + 1, 0);
		std::fill(rs, rs + n + 1, 0);
		std::fill(f, f + n + 1, 0);
		for (int i = 1; i <= m; i ++) {
			int u = read, v = read;
			(ls[u] ? rs[u] : ls[u]) = v;
		}
		int tot = 0;
		for (int u = 1; u <= n; u ++)
			if (f[u] < 2) {
				chkmax(f[ls[u]], f[u] + 1);
				chkmax(f[rs[u]], f[u] + 1);
			} else ++ tot;
		printf("%d\n", tot);
		for (int u = 1; u <= n; u ++)
			if (f[u] >= 2)
				printf("%d ", u);
		puts("");
	}
}