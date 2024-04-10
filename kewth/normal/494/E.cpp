#if 0
2020.03.15


 (x, y)  sg  min(lowbit(x), lowbit(y), greatbit(k)) 
 sg 
 sg 
 lowbit, greatbit  O(logV) 

#endif
#include <cstdio>
#include <algorithm>
#include <cassert>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 100005, maxk = 30;
struct	Tree {
	int cover, low[maxk];
} pool[maxn << 2];
#define self pool[now]
#define lt (now << 1)
#define rt (now << 1 | 1)
int pre[maxn][maxk];

void update(int now, int L, int R) {
	if(self.cover)
		for(int k = 0; k < maxk; k ++)
			self.low[k] = pre[R][k] - pre[L - 1][k];
	else if(L == R)
		for(int k = 0; k < maxk; k ++)
			self.low[k] = 0;
	else
		for(int k = 0; k < maxk; k ++)
			self.low[k] = pool[lt].low[k] + pool[rt].low[k];
}

void modify(int now, int L, int R, int l, int r, int x) {
	if(r < L or l > R) return;
	if(l <= L and R <= r) return self.cover += x, update(now, L, R);
	int M = (L + R) >> 1;
	modify(lt, L, M, l, r, x);
	modify(rt, M + 1, R, l, r, x);
	update(now, L, R);
}

int get[maxk];
void getlow(int n) {
	std::fill(get, get + maxk, 0);
	for(int k = maxk - 1; k; k --) {
		get[k - 1] += get[k] << 1;
		if(n >> k & 1)
			++ get[k - 1];
	}
	for(int k = 0; k < maxk; k ++)
		if(n >> k & 1)
			++ get[k];
}

struct Operation {
	int l, r, t, o;
} op[maxn];
int tmp[maxn], tp;

int main() {
	read.operator int();
	int n = 0, m = read, K = read;
	for(int k = 0; k < maxk + 1; k ++)
		if((1 << k) > K) {
			K = 1 << k >> 1;
			break;
		}

	for(int i = 1; i <= m; i ++) {
		int lx = read, ly = read;
		int rx = read, ry = read;
		op[i * 2 - 1] = {ly, ry, lx, 1};
		op[i * 2] = {ly, ry, rx + 1, -1};
		tmp[++ n] = ly - 1;
		tmp[++ n] = ry;
	}

	std::sort(tmp + 1, tmp + n + 1);
	n = int(std::unique(tmp + 1, tmp + n + 1) - tmp - 1);
	for(int i = 1; i <= n; i ++) {
		getlow(tmp[i]);
		std::copy(get, get + maxk, pre[i]);
	}

	std::sort(op + 1, op + m * 2 + 1, [](Operation a, Operation b) {
				return a.t < b.t;
			});

	int sg = 0;
	for(int i = 1; i <= m * 2; i ++) {
		int shit[maxk];
		getlow(op[i].t - 1);
		std::copy(get, get + maxk, shit);
		getlow(op[i - 1].t - 1);
		for(int k = 0; k < maxk; k ++)
			shit[k] -= get[k];
		for(int k1 = 0; k1 < maxk; k1 ++)
			if(shit[k1] & 1)
				for(int k2 = 0; k2 < maxk; k2 ++)
					if(pool[1].low[k2] & 1)
						sg ^= std::min({1 << k1, 1 << k2, K});
		int l = int(std::lower_bound(tmp + 1, tmp + n + 1, op[i].l - 1) - tmp) + 1;
		int r = int(std::lower_bound(tmp + 1, tmp + n + 1, op[i].r) - tmp);
		modify(1, 1, n, l, r, op[i].o);
	}

	if(sg) puts("Hamed");
	else puts("Malek");
}