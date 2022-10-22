#if 0
2020.03.06

 p 
 [l, r]  p[l]  p[r] 
 r - l = max - min 
 +  max - min - r + l 
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

const int maxn = 300005;
struct Data {
	int min, tim;
} seg[maxn << 2];
int tag[maxn << 2];
#define lt now << 1
#define rt now << 1 | 1

Data operator + (Data a, Data b) {
	if(a.min > b.min) std::swap(a, b);
	if(a.min == b.min) a.tim += b.tim;
	return a;
}

void modi(int now, int x) {
	seg[now].min += x;
	tag[now] += x;
}

inline void push_down(int now) {
	if(tag[now]) {
		modi(lt, tag[now]);
		modi(rt, tag[now]);
		tag[now] = 0;
	}
}

void modify(int now, int L, int R, int l, int r, int x) {
	if(r < L or l > R) return;
	if(l <= L and R <= r) return modi(now, x), void();
	push_down(now);
	int M = (L + R) >> 1;
	modify(lt, L, M, l, r, x);
	modify(rt, M + 1, R, l, r, x);
	seg[now] = seg[lt] + seg[rt];
}

int a[maxn];
int max[maxn], min[maxn], p1, p2;

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++) {
		int x = read, y = read;
		a[x] = y;
	}

	std::fill(seg, seg + (maxn << 2), Data({0, 1}));

	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		while(p1 and a[i] >= a[max[p1]]) {
			modify(1, 1, n, max[p1 - 1] + 1, max[p1], - a[max[p1]]);
			-- p1;
		}
		max[++ p1] = i;
		modify(1, 1, n, max[p1 - 1] + 1, max[p1], a[max[p1]]);

		while(p2 and a[i] <= a[min[p2]]) {
			modify(1, 1, n, min[p2 - 1] + 1, min[p2], a[min[p2]]);
			-- p2;
		}
		min[++ p2] = i;
		modify(1, 1, n, min[p2 - 1] + 1, min[p2], - a[min[p2]]);

		modify(1, 1, n, 1, i, -1);

		ans += seg[1].tim;
	}

	printf("%lld\n", ans);
}