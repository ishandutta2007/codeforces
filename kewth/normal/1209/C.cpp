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
char s[maxn], t[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i ++) t[i] = '2';
		for (int x = 0, p = 0; x < 10; x ++) {
			bool shit = 0;
			for (int i = 1; i <= p; i ++)
				if (s[i] == '0' + x)
					shit = 1;
			for (int i = p + 1; i <= n; i ++)
				if (s[i] == '0' + x)
					t[i] = '1', p = i;
			if (shit) break;
		}
		char las = '0';
		bool ok = 1;
		for (int i = 1; i <= n; i ++)
			if (t[i] == '2') {
				ok &= s[i] >= las;
				las = s[i];
			}
		t[n + 1] = 0;
		if (ok) puts(t + 1);
		else puts("-");
	}
}