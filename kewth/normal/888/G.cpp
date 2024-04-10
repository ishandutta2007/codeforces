#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005, maxk = 32;
int ch[maxn * maxk][2], cp = 1;
int l[maxn * maxk], r[maxn * maxk];
int a[maxn];

int query(int x, int d, int now) {
	if(d < 0)
		return 0;

	if(ch[now][x >> d & 1])
		return query(x, d - 1, ch[now][x >> d & 1]);

	return query(x, d - 1, ch[now][! (x >> d & 1)]) + (1 << d);
}

lolong dfs(int now, int d) {
	if(not now) return 0;

	lolong res = dfs(ch[now][0], d - 1) + dfs(ch[now][1], d - 1);

	/* debug("%d - %d : %d\n", l[now], r[now], now); */

	if(ch[now][0] and ch[now][1]) {
		int min = INT_MAX;
		for(int i = l[ch[now][0]]; i <= r[ch[now][0]]; i ++)
			min = std::min(min, query(a[i], d - 1, ch[now][1]));
		res += min + (1 << d);

		/* debug("get %d\n", min + (1 << d)); */
	}

	return res;
}

int main() {
	int n = input();

	for(int i = 1; i <= n; i ++)
		a[i] = input();

	std::sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; i ++) {
		int now = 1;
		for(int k = maxk - 1; k >= 0; k --) {
			if(not l[now])
				l[now] = i;
			r[now] = i;
			int &to = ch[now][a[i] >> k & 1];
			if(not to)
				to = ++ cp;
			now = to;
		}
	}

	printf("%lld\n", dfs(1, maxk - 1));
}