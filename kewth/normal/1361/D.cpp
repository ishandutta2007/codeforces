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
#include <cmath>
#include <queue>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef double ld;
typedef std::pair<ld, ll> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 500005;
par p[maxn];
ld s[maxn];
bool use[maxn];

int gcd (int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main () {
	int n = read, m = read, L = 1000000000;
	/* std::priority_queue<par> q; */
	std::map<ll, int> map, tot;
	std::map<ll, ld> shit;
	for (int i = 1; i <= n; i ++) {
		int x = read, y = read;
		ld d = std::sqrt(1ll * x * x + 1ll * y * y);
		if (x == 0 and y != 0)
			y = y > 0 ? 1 : -1;
		if (x != 0 and y == 0)
			x = x > 0 ? 1 : -1;
		if (x and y) {
			int g = gcd(std::abs(x), std::abs(y));
			x /= g;
			y /= g;
		}
		ll c = ll(L + x) * (L + L) + (L + y);
		/* q.push(par(d * (m - 1), c)); */
		p[i] = par(d, c);
		/* ++ tot[c]; */
		/* debug("%d %d\n", x, y); */
	}

	std::sort(p + 1, p + n + 1);
	for (int i = n; i; i --) {
		int &k = map[p[i].second];
		if (k * 2 < m - 1) {
			use[i] = 1;
			s[i] = p[i].first * (m - 1) - k * 2 * p[i].first;
			++ k;
		}
		/* ++ map[p[i].second]; */
		/* debug("%lld %lld %lf\n", */
		/* 		p[i].second / (L + L) - L, p[i].second % (L + L) - L, s[i]); */
	}

	for (int i = 1; i <= n; i ++)
		if (!use[i]) {
			int k = map[p[i].second];
			s[i] = p[i].first * (m - 1) - k * 2 * p[i].first - shit[p[i].second];
			shit[p[i].second] += p[i].first * 2;
		}

	std::sort(s + 1, s + n + 1);
	ld ans = 0;
	for (int i = 0; i < m; i ++)
		ans += s[n - i];
	printf("%.8lf\n", ans);
}