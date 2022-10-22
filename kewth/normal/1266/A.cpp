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
#include <cstring>
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

int main () {
	int T = read;
	while (T --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));
		int sum = 0, find = 0;
		for (int i = 1; i <= n; i ++) {
			sum += s[i] - '0';
			if (s[i] == '0')
				find = i;
		}
		((sum *= 40) %= 60);
		bool get = 0;
		for (int i = 1; i <= n; i ++)
			if (find != i and (s[i] + '0') * 30 % 60 == sum)
				get = 1;
		puts(find and get ? "red" : "cyan");
	}
}