#if 0
date +%Y.%m.%d


#endif
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

const int maxn = 7007;
par p[maxn];
bool vis[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++)
		read(p[i].first);
	for (int i = 1; i <= n; i ++)
		read(p[i].second);
	std::sort(p + 1, p + n + 1);

	ll ans = 0;
	for (int i = 2; i <= n; i ++)
		if (p[i].first == p[i - 1].first)
			for (int j = 1; j <= i; j ++)
				if (!vis[j] and (p[j].first & p[i].first) == p[j].first) {
					ans += p[j].second;
					vis[j] = 1;
				}

	printf("%lld\n", ans);
}