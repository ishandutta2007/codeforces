#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;
typedef size_t si;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 16, maxk = 2048;
int a[maxn], b[maxn];
std::bitset<maxk> f[1 << maxn], g[1 << maxn];

int main () {
	int n = read, k = read;
	for (int i = 0; i < n; i ++) read(a[i]);

	f[0][0] = 1;
	for (int S = 1; S < (1 << n); S ++) {
		for (int i = 0; i < n; i ++)
			if (S >> i & 1)
				f[S] |= f[S ^ (1 << i)] << si(a[i]);
		for (int x = (maxk - 1) / k; x >= 0; x --)
			if (f[S][si(x * k)] and !f[S][si(x)])
				f[S][si(x)] = g[S][si(x)] = 1;
	}

	int S = (1 << n) - 1, x = 1;
	if (!f[S][si(x)]) return puts("NO"), 0;
	puts("YES");

	while (S) {
		while (g[S][si(x)]) {
			x *= k;
			for (int i = 0; i < n; i ++)
				if (S >> i & 1)
					++ b[i];
		}
		for (int i = 0; i < n; i ++)
			if (x >= a[i] and S >> i & 1 and f[S ^ (1 << i)][si(x - a[i])]) {
				S ^= 1 << i;
				x -= a[i];
				break;
			}
	}

	std::priority_queue<par> q;
	for (int i = 0; i < n; i ++) q.push(par(b[i], a[i]));

	while (q.size() > 1) {
		par p1 = q.top(); q.pop();
		par p2 = q.top(); q.pop();
		if (p1.first != p2.first) return 1;
		printf("%d %d\n", p1.second, p2.second);
		p1.second += p2.second;
		while (p1.second % k == 0)
			-- p1.first, p1.second /= k;
		q.push(p1);
	}
}