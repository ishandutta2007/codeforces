/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d

 * Solution:
  

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

const int maxn = 100005;
char s[maxn];

int main () {
	int n = read, m = read;
	scanf("%s", s + 1);

	int l0 = 0, l1 = 0, r0 = 0, r1 = 0;
	for (int i = 1; i <= n; i ++)
		if (s[i] == '0') {
			r0 = i;
			if (!l0) l0 = i;
		} else {
			r1 = i;
			if (!l1) l1 = i;
		}
	if (l0 + m > r0 or l1 + m > r1)
		return puts("tokitsukaze"), 0;

	if (m * 2 < n)
		return puts("once again"), 0;

	bool lose = 1;
	for (int i = 1; i <= n - m - 1; i ++)
		lose &= s[i] == s[1];
	lose &= s[n - m] != s[1];
	lose &= s[m + 1] != s[n];
	for (int i = m + 2; i <= n; i ++)
		lose &= s[i] == s[n];

	if (lose)
		return puts("quailty"), 0;

	// FIXME:
	puts("once again");
}