#if 0
date

(cf573e)
solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100005, maxs = 400, B = 320;
ll tk[maxs], ty[maxs];
ll x[maxs][B], y[maxs][B];
struct Dot {
	ll x, y, id;
} que[maxs][B], tmp[B];
int front[maxs], size[maxs];

ll query(int b) {
	int &p = front[b];
	while(p + 1 < size[b] and que[b][p].y - tk[b] * que[b][p].x <
			que[b][p + 1].y - tk[b] * que[b][p + 1].x)
		++ p;
	// debug("query %d (k=%lld, ty=%lld) -> (%lld, %lld)\n",
			// b, tk[b], ty[b], que[b][p].x, que[b][p].y);
	return ty[b] + que[b][p].y - tk[b] * que[b][p].x;
}

void build(int b) {
	for(int i = 0; i < B; i ++)
		tmp[i] = {x[b][i], y[b][i], i};
	std::sort(tmp, tmp + B, [](Dot a, Dot b) {
				return a.x == b.x ? a.y < b.y : a.x < b.x;
			});

	int &p = size[b];
	p = 0;
	for(int i = 0; i < B; i ++) {
		while(p > 1 and (que[b][p - 2].y - que[b][p - 1].y) *
				(que[b][p - 1].x - tmp[i].x) <=
				(que[b][p - 1].y - tmp[i].y) *
				(que[b][p - 2].x - que[b][p - 1].x))
			-- p;
		que[b][p ++] = tmp[i];
	}

	// debug("build %d\n", b);
	// for(int i = 0; i < p; i ++)
		// debug("%lld %lld\n", que[b][i].x, que[b][i].y);

	front[b] = 0;
}

int main() {
	int n = read;
	for(int i = 0; i < n; i ++)
		x[i / B][i % B] = y[i / B][i % B] = read;
	int s = (n - 1) / B + 1;

	for(int i = 0; i < s; i ++)
		build(i);

	ll ans = 0;
	while(1) {
		int b = 0;
		for(int i = 1; i < s; i ++)
			if(query(i) > query(b))
				b = i;

		if(query(b) <= 0)
			break;
		ans += query(b);

		int p = que[b][front[b]].id;
		ll a = x[b][p];
		x[b][p] = - 1000000000;
		y[b][p] = - 1000000000000000000;

		for(int i = 0; i < p; i ++)
			y[b][i] += a;
		for(int i = p + 1; i < B; i ++)
			y[b][i] += x[b][i];
		build(b);

		for(int i = 0; i < b; i ++)
			ty[i] += a;
		for(int i = b + 1; i < s; i ++)
			-- tk[i];

		// debug("use %d\n", b * B + p + 1);
	}

	printf("%lld\n", ans);
}