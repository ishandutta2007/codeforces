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

const int maxn = 200005;
int a[maxn], R[maxn], tot[maxn];

int main () {
	int n = read, q = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int i = 1; i <= n; i ++) R[a[i]] = i;
	for (int i = 1; i <= n; i ++) ++ tot[a[i]];
	/* int w = 200000; */
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = R[a[l]];
		int max = tot[a[l]];
		tot[a[l]] = 0;
		for (int i = l; i <= r; i ++)
			if (tot[a[i]]) {
				r = std::max(r, R[a[i]]);
				max = std::max(max, tot[a[i]]);
			}
		ans += r - l + 1 - max;
	}
	printf("%d\n", ans);
}