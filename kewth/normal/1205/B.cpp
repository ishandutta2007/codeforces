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

const int maxn = 100005, maxk = 60;
int ax[maxk], ay[maxk];
int id[maxn], ip;
int f[maxk << 1][maxk << 1], g[maxk << 1][maxk << 1];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) {
		ll x = read;
		if (x == 0) continue;
		int u = ++ ip;
		for (int k = 0; k < maxk; k ++)
			if (x >> k & 1) {
				if (ay[k]) return puts("3"), 0;
				if (ax[k]) ay[k] = u;
				else ax[k] = u;
			}
	}

	for (int i = 1; i <= ip; i ++)
		for (int j = 1; j <= ip; j ++)
			f[i][j] = g[i][j] = 100000;

	for (int k = 0; k < maxk; k ++)
		if (ax[k] and ay[k]) {
			f[ax[k]][ay[k]] = f[ay[k]][ax[k]] = 1;
			g[ax[k]][ay[k]] = g[ay[k]][ax[k]] = 1;
		}

	int ans = 100000;
	for (int k = 1; k <= ip; k ++) {
		for (int i = 1; i < k; i ++)
			for (int j = 1; j < i; j ++)
				ans = std::min(ans, f[i][j] + g[i][k] + g[k][j]);
		for (int i = 1; i <= ip; i ++)
			for (int j = 1; j <= ip; j ++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	}

	if (ans == 100000) puts("-1");
	else printf("%d\n", ans);
}