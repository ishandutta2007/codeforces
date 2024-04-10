#if 0
2020.05.05

  
   A, B  A  B 
A, B 
 A  B 
   Treap Treap 

  
#endif
#include <cstdio>
#include <algorithm>
#include <bitset>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int X = 1000000007, Y = 998244353;
struct Hash2 {
	 int x, y;
	 static Hash2 base;
};
Hash2 Hash2::base = {300000007, 23456789};
Hash2 operator * (Hash2 a, Hash2 b) { return {int(1ll * a.x * b.x % X), int(1ll * a.y * b.y % Y)}; }
Hash2 operator - (Hash2 a, Hash2 b) { return {(a.x + X - b.x) % X, (a.y + Y - b.y) % Y}; }
Hash2 operator + (Hash2 a, Hash2 b) { return {(a.x + b.x) % X, (a.y + b.y) % Y}; }
bool operator == (Hash2 a, Hash2 b) { return a.x == b.x and a.y == b.y; }
Hash2 make (int v) { return {v, v}; }
typedef Hash2 hash;

const int maxn = 100005, LIM = maxn * 60;
struct Treap {
	int lti, rti, size;
	int weight;
	hash val, sum;
} pool[LIM];
std::bitset<LIM> mark;
int pp;
#define self pool[now]
#define lt pool[self.lti]
#define rt pool[self.rti]

int newnode () {
	while (mark[si(pp + 1)]) ++ pp;
	mark[si(++ pp)] = 1;
	return pp;
}

hash po[maxn];

void update (int now) {
	self.sum = lt.sum * po[rt.size + 1] + self.val * po[rt.size] + rt.sum;
	self.size = lt.size + 1 + rt.size;
}

void split (int now, int k, int &a, int &b) {
	if (!now) return a = b = 0, void();
	pool[newnode()] = self;
	now = pp;
	if (k <= lt.size) {
		split(self.lti, k, a, self.lti);
		b = now;
	} else {
		split(self.rti, k - lt.size - 1, self.rti, b);
		a = now;
	}
	update(now);
}

int merge (int a, int b) {
	if (!a or !b) return a + b;
	int now = newnode();
	if (pool[a].weight > pool[b].weight) {
		self = pool[a];
		self.rti = merge(self.rti, b);
	} else {
		self = pool[b];
		self.lti = merge(a, self.lti);
	}
	update(now);
	return now;
}

int t1[maxn * 4 + 30], t2[maxn * 4 + 30];
bool ok[maxn * 4 + 30];

void Update (int Now, int Lt, int Rt) {
	if (!ok[Lt] or !ok[Rt])
		return ok[Now] = 0, void();
	int lsize = pool[t2[Lt]].size, rsize = pool[t1[Rt]].size, a, b;
	if (lsize >= rsize) {
		split(t2[Lt], lsize - rsize, a, b);
		ok[Now] = pool[b].sum == pool[t1[Rt]].sum;
		if (ok[Now]) {
			t1[Now] = t1[Lt];
			t2[Now] = merge(a, t2[Rt]);
		}
	}
	else {
		split(t1[Rt], rsize - lsize, a, b);
		ok[Now] = pool[t2[Lt]].sum == pool[b].sum;
		if (ok[Now]) {
			t1[Now] = merge(a, t1[Lt]);
			t2[Now] = t2[Rt];
		}
	}
	/* if (Now == 1) { */
	/* 	debug("%d %d %d\n", ok[Now], t1[Now], t2[Now]); */
	/* 	debug("%d %d\n", lsize, rsize); */
	/* 	debug("%d %d\n", pool[t1[Now]].size, pool[t2[Now]].size); */
	/* 	debug("%d %d\n", pool[t1[Now]].sum.x, pool[t2[Now]].sum.x); */
	/* } */
}

void Modify (int Now, int L, int R, int p, int x) {
	if (L == R) {
		int now = newnode();
		self = {0, 0, 1, rand(), make(std::abs(x)), make(std::abs(x))};
		if (x > 0)
			t1[Now] = 0, t2[Now] = now;
		else
			t1[Now] = now, t2[Now] = 0;
		ok[Now] = 1;
		return;
	}
	int M = (L + R) >> 1;
	if (p <= M) Modify(Now << 1, L, M, p, x);
	else Modify(Now << 1 | 1, M + 1, R, p, x);
	Update(Now, Now << 1, Now << 1 | 1);
}

int tid;
int Query (int Now, int L, int R, int l, int r) {
	if (r < L or l > R) return 0;
	if (l <= L and R <= r) return Now;
	int M = (L + R) >> 1;
	int Lt = Query(Now << 1, L, M, l, r);
	int Rt = Query(Now << 1 | 1, M + 1, R, l, r);
	/* debug("get Q %d %d %d %d\n", L, R, l, r); */
	Update(++ tid, Lt, Rt);
	return tid;
}

void remark (int now) {
	if (!now or mark[si(now)]) return;
	mark[si(now)] = 1;
	remark(self.lti);
	remark(self.rti);
}

void remark (int Now, int L, int R) {
	remark(t1[Now]);
	remark(t2[Now]);
	if (L == R) return;
	int M = (L + R) >> 1;
	remark(Now << 1, L, M);
	remark(Now << 1 | 1, M + 1, R);
}

int main () {
	srand(19260817);
	int n = read;
	read.operator int();
	po[0] = make(1);
	for (int i = 1; i <= n; i ++)
		po[i] = po[i - 1] * hash::base;

	for (int i = 1; i <= n; i ++)
		Modify(1, 1, n, i, read);

	ok[0] = 1;
	int q = read;
	for (int i = 1; i <= q; i ++) {
		int o = read;
		if (o == 1) {
			int p = read, x = read;
			Modify(1, 1, n, p, x);
		}
		if (o == 2) {
			int l = read, r = read;
			tid = n * 4;
			int tmp = Query(1, 1, n, l, r);
			puts((ok[tmp] and !t1[tmp] and !t2[tmp]) ? "Yes" : "No");
		}
		if (pp + 1000 >= LIM) {
			mark.reset();
			remark(1, 1, n);
			pp = 0;
		}
	}
}