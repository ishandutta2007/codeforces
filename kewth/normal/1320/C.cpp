#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005, X = 1000000;
ll seg[X << 2], tag[X << 2];
ll cost[X + 1];

void modi(int now, ll x) {
	seg[now] += x;
	tag[now] += x;
}

void modify(int now, int L, int R, int l, int r, int x) {
	if(r < L or l > R) return;
	if(l <= L and R <= r) return modi(now, x), void();
	if(tag[now]) {
		modi(now << 1, tag[now]);
		modi(now << 1 | 1, tag[now]);
		tag[now] = 0;
	}
	int M = (L + R) >> 1;
	modify(now << 1, L, M, l, r, x);
	modify(now << 1 | 1, M + 1, R, l, r, x);
	seg[now] = std::max(seg[now << 1], seg[now << 1 | 1]);
}

void build(int now, int L, int R) {
	if(L == R) return seg[now] = cost[L], void();
	int M = (L + R) >> 1;
	build(now << 1, L, M);
	build(now << 1 | 1, M + 1, R);
	seg[now] = std::max(seg[now << 1], seg[now << 1 | 1]);
}

par w[maxn];
struct T {
	int a, b, c;
} t[maxn];

int main() {
	std::fill(cost, cost + X + 1, - 1000000000000000000);

	int n = read, m = read, p = read;
	for(int i = 1; i <= n; i ++) {
		w[i].first = read;
		w[i].second = read;
	}
	std::sort(w + 1, w + n + 1);

	for(int i = 1; i <= m; i ++) { 
		int x = read, y = read;
		cost[x] = std::max(cost[x], ll(-y));
	}

	build(1, 1, X);

	for(int i = 1; i <= p; i ++) {
		t[i].a = read;
		t[i].b = read;
		t[i].c = read;
	}

	std::sort(t + 1, t + p + 1, [](T a, T b) {
				return a.a < b.a;
			});

	int s = 0;
	ll ans = - 1000000000000000000;
	// debug("qu %lld\n", seg[1]);
	for(int i = 1; i <= n; i ++) {
		while(s < p and t[s + 1].a < w[i].first) {
			++ s;
			// debug("modi %d %d\n", t[s].b, t[s].c);
			modify(1, 1, X, t[s].b + 1, X, t[s].c);
		}
		// debug("qu %lld\n", seg[1]);
		ans = std::max(ans, seg[1] - w[i].second);
	}

	printf("%lld\n", ans);
}