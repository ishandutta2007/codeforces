#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 150000;
struct Data {
	int max[5], tot[5];
	Data() {
		memset(max, 0, sizeof max);
		memset(tot, 0, sizeof tot);
	}
};
struct Tree {
	Data val;
	int tag;
} seg[maxn << 2];
#define lti (now << 1)
#define rti (now << 1 | 1)
int a[maxn];
int P;

Data merge(Data a, Data b) {
	for(int i = 0; i < P; i ++) {
		int min = b.tot[i];
		for(int j = 0; j < P; j ++)
			if(a.max[j] == b.max[i]) {
				a.tot[j] += b.tot[i];
				goto done;
			}

		for(int j = 0; j < P; j ++)
			min = std::min(min, a.tot[j]);
		for(int j = 0; j < P; j ++)
			a.tot[j] -= min;
		b.tot[i] -= min;

		for(int j = 0; j < P; j ++)
			if(!a.tot[j]) {
				a.max[j] = b.max[i];
				a.tot[j] = b.tot[i];
				goto done;
			}
done:;
	}

	return a;
}

void modi(int now, int L, int R, int x) {
	Data d;
	d.max[0] = x;
	d.tot[0] = R - L + 1;
	seg[now] = {d, x};
}

void build(int now, int L, int R) {
	if(L == R) return modi(now, L, R, a[L]);
	int M = (L + R) >> 1;
	build(lti, L, M);
	build(rti, M + 1, R);
	seg[now].val = merge(seg[lti].val, seg[rti].val);
}

inline void push_down(int now, int L, int R) {
	if(seg[now].tag) {
		int M = (L + R) >> 1;
		modi(lti, L, M, seg[now].tag);
		modi(rti, M + 1, R, seg[now].tag);
		seg[now].tag = 0;
	}
}

void modify(int now, int L, int R, int l, int r, int x) {
	if(r < L or l > R) return;
	if(l <= L and R <= r) return modi(now, L, R, x);
	push_down(now, L, R);
	int M = (L + R) >> 1;
	modify(lti, L, M, l, r, x);
	modify(rti, M + 1, R, l, r, x);
	seg[now].val = merge(seg[lti].val, seg[rti].val);
}

Data query(int now, int L, int R, int l, int r) {
	if(r < L or l > R) return Data();
	if(l <= L and R <= r) return seg[now].val;
	push_down(now, L, R);
	int M = (L + R) >> 1;
	return merge(query(lti, L, M, l, r), query(rti, M + 1, R, l, r));
}

int main() {
	int n = read, q = read, p = read;
	P = 100 / p;
	for(int i = 1; i <= n; i ++)
		a[i] = read;
	build(1, 1, n);

	while(q --) {
		int o = read;

		if(o == 1) {
			int l = read, r = read, x = read;
			modify(1, 1, n, l, r, x);
		}

		if(o == 2) {
			int l = read, r = read;
			Data d = query(1, 1, n, l, r);
			printf("%d", P);
			for(int i = 0; i < P; i ++)
				printf(" %d", d.max[i]);
			puts("");
		}
	}
}