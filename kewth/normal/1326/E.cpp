#if 0
date +%Y.%m.%d


 x >= x  < x 
 01  1 
 1 
 1 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 300005;
int a[maxn], b[maxn], pos[maxn];
int seg[maxn << 2], tag[maxn << 2];
#define lt (now << 1)
#define rt (now << 1 | 1)

void add (int now, int L, int R, int r, int x) {
	if (R <= r) return seg[now] += x, tag[now] += x, void();
	int M = (L + R) >> 1;
	seg[lt] += tag[now];
	tag[lt] += tag[now];
	seg[rt] += tag[now];
	tag[rt] += tag[now];
	tag[now] = 0;
	add(lt, L, M, r, x);
	if (r > M) add(rt, M + 1, R, r, x);
	seg[now] = std::max(seg[lt], seg[rt]);
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int i = 1; i <= n; i ++) read(b[i]);
	for (int i = 1; i <= n; i ++) pos[a[i]] = i;

	int ans = n + 1;
	for (int i = 0; i < n; i ++) {
		while (seg[1] <= 0)
			add(1, 1, n, pos[-- ans], 1);
		printf("%d ", ans);
		add(1, 1, n, b[i + 1], -1);
	}
	puts("");
}