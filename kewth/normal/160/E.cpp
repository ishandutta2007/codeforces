#if 0
2020.05.08

   3  log  cdq 
 log 
  




  
  1) 
  2) 
  3) 
   log 

#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	/* inline operator ll () { ll x; return scanf("%lld", &x), x; } */
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 400005;
struct shit {
	int l, r, t, i, o;
} a[maxn << 1];
int ans[maxn];
int tmp[maxn];
par seg[maxn << 2], INF = par(1000000000, 1000000000);
std::set<par> set[maxn];

void insert (int now, int L, int R, int p, par x) {
	if (L == R) {
		set[p].insert(x);
		seg[now] = *set[p].begin();
		return;
	}
	int M = (L + R) >> 1;
	if (p <= M) insert(now << 1, L, M, p, x);
	else insert(now << 1 | 1, M + 1, R, p, x);
	seg[now] = std::min(seg[now << 1], seg[now << 1 | 1]);
}

void pop (int now, int L, int R, int p) {
	if (L == R) {
		set[p].erase(set[p].begin());
		seg[now] = *set[p].begin();
		return;
	}
	int M = (L + R) >> 1;
	if (p <= M) pop(now << 1, L, M, p);
	else pop(now << 1 | 1, M + 1, R, p);
	seg[now] = std::min(seg[now << 1], seg[now << 1 | 1]);
}

par query (int now, int L, int R, int l, int r) {
	if (r < L or l > R) return INF;
	if (l <= L and R <= r) return seg[now];
	int M = (L + R) >> 1;
	return std::min(query(now << 1, L, M, l, r),
			query(now << 1 | 1, M + 1, R, l, r));
}

void build (int now, int L, int R) {
	seg[now] = INF;
	if (L == R)
		return set[L].insert(INF), void();
	int M = (L + R) >> 1;
	build(now << 1, L, M);
	build(now << 1 | 1, M + 1, R);
}

int main () {
	int n = read, m = read, p = 0;
	for (int i = 1; i <= n; i ++) {
		a[++ p].o = 1;
		read(a[p].l, a[p].r, a[p].t);
		a[p].i = p;
	}
	for (int i = 1; i <= m; i ++) {
		a[++ p].o = 2;
		read(a[p].l, a[p].r, a[p].t);
		a[p].i = p;
	}

	int t = 0;
	for (int i = 1; i <= p; i ++) {
		tmp[++ t] = a[i].l;
		tmp[++ t] = a[i].r;
	}

	std::sort(tmp + 1, tmp + t + 1);
	for (int i = 1; i <= p; i ++) {
		a[i].l = int(std::lower_bound(tmp + 1, tmp + t + 1, a[i].l) - tmp);
		a[i].r = int(std::lower_bound(tmp + 1, tmp + t + 1, a[i].r) - tmp);
	}

	std::sort(a + 1, a + p + 1, [] (shit x, shit y) {
				return x.t == y.t ? x.o > y.o : x.t < y.t;
			});

	build(1, 1, t);

	for (int i = 1; i <= p; i ++) {
		if (a[i].o == 1) {
			par x = query(1, 1, t, a[i].l, a[i].r);
			while (x.first <= a[i].r) {
				int j = x.second;
				ans[a[j].i] = a[i].i;
				pop(1, 1, t, a[j].l);
				x = query(1, 1, t, a[i].l, a[i].r);
			}
		}
		if (a[i].o == 2)
			insert(1, 1, t, a[i].l, par(a[i].r, i));
	}

	for (int i = n + 1; i <= n + m; i ++)
		printf("%d ", ans[i] ? ans[i] : -1);
	puts("");
}