#if 0
date

(cf538g)
solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005, maxm = 2000005;
ll pos[2][maxn], ti[maxn];
int get[2][maxm];

struct Limit {
	ll p, a, b;
} li[maxn];

void solve(int o, int n, int m) {
	// for(int i = 1; i <= n; i ++)
		// debug(" %lld", pos[o][i]);
	// debug("\n");

	for(int i = 1; i <= n; i ++)
		li[i] = {pos[o][i], ti[i] / m, ti[i] % m};
	std::sort(li + 1, li + n + 1, [](Limit x, Limit y) {
				return x.b < y.b;
			});

	li[0] = {0, 0, 0};
	li[n + 1] = {0, -1, m};
	ll Lx = 0, Rx = 1000000000000000000;
	for(int i = 1; i <= n + 1; i ++) {
		if(i < n) {
			Lx = std::max(Lx, (li[i].p + li[i].a) / (li[i].a + 1));
			if(li[i].a)
				Rx = std::min(Rx, li[i].p / li[i].a);
		}

		ll dp = li[i].p - li[i - 1].p;
		ll da = li[i].a - li[i - 1].a;
		ll L = 0, R = li[i].b - li[i - 1].b;

		if(da < 0) {
			dp = - dp;
			da = - da;
			L = - R;
			R = 0;
		}

		if(da) {
			Lx = std::max(Lx, (dp - R + da - 1) / da);
			Rx = std::min(Rx, (dp - L) / da);
		} else if(dp < L or dp > R)
			puts("NO"), exit(0);
	}

	if(Lx > Rx)
		puts("NO"), exit(0);

	// debug("%lld <= x <= %lld\n", Lx, Rx);

	ll x = Lx;
	for(int i = 1; i <= n + 1; i ++) {
		ll dis = li[i].p - li[i - 1].p - (li[i].a - li[i - 1].a) * x;
		for(int j = li[i].b - dis + 1; j <= li[i].b; j ++)
			get[o][j] = 1;
	}
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= n; i ++) {
		ti[i] = read;
		ll x = read, y = read;
		pos[0][i] = x - y + ti[i];
		pos[1][i] = x + y + ti[i];
		if((pos[0][i] & 1) or (pos[1][i] & 1))
			puts("NO"), exit(0);
		pos[0][i] >>= 1;
		pos[1][i] >>= 1;
	}

	solve(0, n, m);
	solve(1, n, m);

	char s[5] = "LDUR";
	for(int i = 1; i <= m; i ++)
		putchar(s[get[1][i] << 1 | get[0][i]]);
	puts("");
}