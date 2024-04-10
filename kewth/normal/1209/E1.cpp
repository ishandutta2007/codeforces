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

const int maxn = 10, maxm = 200;
int a[maxn][maxm], b[maxn][maxn];
int max[maxm], p[maxm];

int ans = 0;
void force (int x, int n, int m) {
	if (x > m) {
		/* for (int i = 1; i <= n; i ++) { */
		/* 	for (int j = 1; j <= m; j ++) */
		/* 		debug(" %d", b[i][j]); */
		/* 	debug("\n"); */
		/* } */
		/* debug("\n"); */
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			int now = 0;
			for (int j = 1; j <= m; j ++)
				now = std::max(now, b[i][j]);
			sum += now;
		}
		ans = std::max(ans, sum);
		return;
	}
	for (int t = 0; t < n; t ++) {
		int s = b[n][x];
		for (int i = n; i; i --)
			b[i][x] = b[i - 1][x];
		b[1][x] = s;
		force(x + 1, n, m);
	}
}

int main () {
	int T = read;
	while (T --) {
		int n = read, m = read;
		for (int j = 1; j <= m; j ++) max[j] = 0, p[j] = j;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				max[j] = std::max(max[j], a[i][j] = read);
		std::sort(p + 1, p + m + 1, [] (int x, int y) {
					return max[x] > max[y];
				});
		m = std::min(n, m);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				b[i][j] = a[i][p[j]];
		ans = 0;
		force(1, n, m);
		printf("%d\n", ans);
	}
}