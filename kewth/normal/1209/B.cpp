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

const int maxn = 105;
char s[maxn];
int a[maxn], b[maxn];

int main () {
	int n = read;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) read(a[i], b[i]);
	int ans = 0;
	for (int t = 0; t < 100000; t ++) {
		for (int i = 1; i <= n; i ++)
			if (t >= b[i] and (t - b[i]) % a[i] == 0)
				s[i] = '0' + '1' - s[i];
		int now = 0;
		for (int i = 1; i <= n; i ++) now += s[i] == '1';
		ans = std::max(ans, now);
	}
	printf("%d\n", ans);
}