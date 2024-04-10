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
typedef std::pair<ll, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
par p[maxn];
int ax[maxn * 10], ay[maxn * 10];
ll az[maxn * 10];
int ap;

void add (int x, int y, ll z) {
	++ ap;
	ax[ap] = x;
	ay[ap] = y;
	az[ap] = z;
	/* if (z > 1000000000) { */
	/* 	az[ap] = 1000000000; */
	/* 	add(x, y, z - 1000000000); */
	/* } else */
	/* 	az[ap] = int(z); */
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int a = read, b = read, c = read;
		p[a].first += c;
		p[b].first -= c;
	}
	for (int i = 1; i <= n; i ++) p[i].second = i;
	std::sort(p + 1, p + n + 1);
	for (int i = 1, j = n; i < j;) {
		ll s = p[i].first + p[j].first;
		if (s >= 0) {
			if (p[i].first and p[j].first)
				add(p[j].second, p[i].second, - p[i].first);
			p[j].first = s;
			++ i;
		}
		if (s < 0) {
			if (p[i].first and p[j].first)
				add(p[j].second, p[i].second, p[j].first);
			p[i].first = s;
			-- j;
		}
	}
	printf("%d\n", ap);
	for (int i = 1; i <= ap; i ++)
		printf("%d %d %lld\n", ax[i], ay[i], az[i]);
}