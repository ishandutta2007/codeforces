#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 16, maxm = 5050;
ll a[maxn][maxm];
int m[maxn];
ll s[maxn];
std::map<ll, par> map;
par to[maxn][maxm];
int deg[maxn][maxm];
par stack[maxn * maxm];
int sp;
bool f[1 << maxn];
int g[1 << maxn];
par h[1 << maxn];
int use[maxn], put[maxn];

void getans (int S) {
	if (g[S] == -1) {
		int x = h[S].first, y = h[S].second;
		do {
			par p = to[x][y];
			use[x] = y;
			put[p.first] = x;
			x = p.first;
			y = p.second;
		} while (x != h[S].first or y != h[S].second);
		return;
	}
	int A = g[S], B = S ^ A;
	getans(A);
	getans(B);
}

int main () {
	int n = read;
	ll sum = 0;
	for (int i = 1; i <= n; i ++) {
		read(m[i]);
		for (int j = 1; j <= m[i]; j ++) {
			s[i] += a[i][j] = read;
			map[a[i][j]] = par(i, j);
		}
		sum += s[i];
	}

	if (sum % n) return puts("No"), 0;
	sum /= n;
	for (int i = 1; i <= n; i ++)
		s[i] -= sum;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m[i]; j ++) {
			ll x = a[i][j] - s[i];
			if (map.count(x)) {
				par p = map[x];
				to[i][j] = p;
				/* debug("%d %d -> %d %d\n", i, j, p.first, p.second); */
				++ deg[p.first][p.second];
			}
		}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m[i]; j ++)
			if (!deg[i][j])
				stack[++ sp] = par(i, j);

	while (sp) {
		int i = stack[sp].first, j = stack[sp].second;
		-- sp;
		if (to[i][j] != par(0, 0) and -- deg[to[i][j].first][to[i][j].second] == 0)
			stack[++ sp] = to[i][j];
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m[i]; j ++)
			if (deg[i][j]) {
				int x = i, y = j, S = 0, shit = 0;
				/* debug("circle\n"); */
				do {
					/* debug("%d %d\n", x, y); */
					deg[x][y] = 0;
					shit |= S << 1 >> x & 1;
					S ^= 1 << x >> 1;
					par p = to[x][y];
					x = p.first;
					y = p.second;
				} while (x != i or y != j);
				if (!shit)
					f[S] = 1, g[S] = -1, h[S] = par(i, j);
			}

	for (int S = 0; S < (1 << n); S ++)
		for (int A = S; A >= 0 and !f[S]; A --) {
			A &= S;
			int B = S ^ A;
			if (f[A] and f[B])
				f[S] = 1, g[S] = A;
		}

	if (!f[(1 << n) - 1]) return puts("No"), 0;
	getans((1 << n) - 1);

	puts("Yes");
	for (int i = 1; i <= n; i ++)
		printf("%lld %d\n", a[i][use[i]], put[i]);

	for (int i = 1; i <= n; i ++) {
		s[i] -= a[i][use[i]];
		s[put[i]] += a[i][use[i]];
	}

	for (int i = 1; i <= n; i ++)
		if (s[i])
			return 1;
}