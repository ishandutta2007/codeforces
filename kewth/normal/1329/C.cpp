#if 0
date +%Y.%m.%d

solution will be written here.
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1 << 23;
int a[maxn], h[maxn];
int as[maxn], ap;
#define ls (now << 1)
#define rs (now << 1 | 1)

int find (int now) {
	if (!a[ls] and !a[rs]) return now;
	return a[ls] > a[rs] ? find(ls) : find(rs);
}

void work (int now) {
	if (!a[ls] and !a[rs]) return a[now] = 0, void();
	if (a[ls] > a[rs]) {
		a[now] = a[ls];
		work(ls);
	} else {
		a[now] = a[rs];
		work(rs);
	}
}

void force (int now, int n, int m) {
	if (!a[now]) return;
	while (1) {
		int x = find(now);
		if (h[x] == m) {
			force(ls, n - 1, m);
			force(rs, n - 1, m);
			break;
		}
		// debug("%d %d %d\n", now, x, a[x]);
		as[++ ap] = now;
		work(now);
	}
}

int main() {
	int T = read;
	while (T --) {
		int n = read, m = read;
		for (int i = 1; i < (1 << n); i ++) {
			a[i] = read;
			h[i] = h[i >> 1] + 1;
		}

		ap = 0;
		force(1, n, m);

		ll ans = 0;
		for (int i = 1; i < (1 << m); i ++)
			ans += a[i];

		printf("%lld\n", ans);
		for (int i = 1; i <= ap; i ++)
			printf("%d ", as[i]);
		puts("");

		// FST 
		std::fill(a, a + (1 << n), 0);
	}
}