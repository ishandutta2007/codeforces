#if 0
date



 g = gcd(n, m)  g 
 g  g  g 

 n, m 

n  (boy) 
 S  k 
 S -> k % n  k 
 k  k  m 
 (k + m) % n  k -> (k + m) % n  m 

 dis 
 boy  k  dis 



 m  n 
 u -> v 
 u  v  v 
 dis[v] = dis[u] + m  u 
 O(n) 
 u  v 

 u  v 

 x 

 u, v u  v 

#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005;

int tmp1, tmp2;
int exgcd(int a, int b, int &x, int &y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

struct Shit {
	int frombegin, now, buff;
} shi[maxn << 1];
std::set<int> keyn[maxn << 1], keym[maxn << 1];

ll solve(int n, int m, int id) {
	std::map<int, int> dis;
	std::set<int> pos;
	for(int x : keyn[id]) {
		pos.insert(x);
		dis[x] = x;
	}
	for(int x : keym[id]) {
		pos.insert(x % n);
		// XXX: WTF? 
		if(dis.count(x % n))
			dis[x % n] = std::min(dis[x % n], x);
		else
			dis[x % n] = x;
		// dis[x % n] = dis.count(x % n) ? std::min(dis[x % n], x) : x;
	}

	int x;
	exgcd(m, n, x, tmp2);
	x %= n;
	if(x < 0) x += n;

	int p = 0;
	for(int po : pos)
		shi[++ p] = {int(1ll * x * (po - *pos.begin()) % n),
			dis[po], int(keyn[id].count(po))};
	std::sort(shi + 1, shi + p + 1, [](Shit x, Shit y) {
				return x.frombegin < y.frombegin;
			});
	shi[p + 1] = {n, -1, -1};

	ll res = - 10000000000000;
	for(int i = 1; i <= p; i ++)
		if(!shi[i].buff or
				shi[i + 1].frombegin > shi[i].frombegin + 1)
		res = std::max(res, shi[i].now +
				1ll * (shi[i + 1].frombegin - shi[i].frombegin - 1) * m);

#if 0
	debug("fuck solve %d %d\n", n, m);
	for(int i = 1; i <= p + 1; i ++)
		debug("%d, %d, %d\n",
				shi[i].frombegin, shi[i].now, shi[i].buff);
	debug("res = %lld\n", res);
#endif
	return res;
}

int main() {
	int n = read, m = read;
	int g = exgcd(n, m, tmp1, tmp2);

	if(g > 200000) return puts("-1"), 0;

	for(int i = read; i; -- i) {
		int x = read;
		keyn[x % g].insert(x / g);
	}
	for(int i = read; i; -- i) {
		int x = read;
		keym[x % g].insert(x / g);
	}

	ll ans = 0;
	for(int i = 0; i < g; i ++) {
		if(keyn[i].empty() and keym[i].empty()) return puts("-1"), 0;
		ans = std::max(ans, solve(n / g, m / g, i) * g + i);
		std::swap(keyn[i], keym[i]);
		ans = std::max(ans, solve(m / g, n / g, i) * g + i);
	}

	printf("%lld\n", ans);
}