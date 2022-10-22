#if 0
2020.03.04

woc  A 





#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 300005, maxk = 20;
char s[maxn];
std::vector<int> G[maxn];
int deep[maxn], fa[maxn], top[maxn], son[maxn], size[maxn];
int id[maxn], iid[maxn], ip;

int A, B, C;
struct Hash {
	ll a, b, c;
	Hash(ll x = 0): a(x), b(x), c(x) { }
};

Hash operator * (Hash x, Hash y) {
	(x.a *= y.a) %= A;
	(x.b *= y.b) %= B;
	(x.c *= y.c) %= C;
	return x;
}

Hash operator + (Hash x, Hash y) {
	(x.a += y.a) %= A;
	(x.b += y.b) %= B;
	(x.c += y.c) %= C;
	return x;
}

Hash operator - (Hash x, Hash y) {
	(x.a += A - y.a) %= A;
	(x.b += B - y.b) %= B;
	(x.c += C - y.c) %= C;
	return x;
}

bool operator == (Hash x, Hash y) {
	return x.a == y.a and x.b == y.b and x.c == y.c;
}

Hash pre[maxn << 1], po[maxn << 1], base = 233;

void dfs1(int u) {
	deep[u] = deep[fa[u]] + 1;
	size[u] = 1;
	for(int v : G[u])
		if(v != fa[u]) {
			fa[v] = u;
			dfs1(v);
			size[u] += size[v];
			if(size[v] > size[son[u]])
				son[u] = v;
		}
}

void dfs2(int u) {
	iid[id[u] = ++ ip] = u;
	if(!top[u]) top[u] = u;
	if(son[u]) {
		top[son[u]] = top[u];
		dfs2(son[u]);
		for(int v : G[u])
			if(v != fa[u] and v != son[u])
				dfs2(v);
	}
}

struct Range {
	int l, r;
	int len() { return r - l + 1; }
} que[maxn], tmp[maxn];
int qp;

void divi(int x, int y) {
	int p = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] > deep[top[y]]) {
			que[++ qp] = {ip * 2 - id[x] + 1, ip * 2 - id[top[x]] + 1};
			x = fa[top[x]];
		} else {
			tmp[++ p] = {id[top[y]], id[y]};
			y = fa[top[y]];
		}
	}

	if(deep[x] > deep[y])
		que[++ qp] = {ip * 2 - id[x] + 1, ip * 2 - id[y] + 1};
	else
		tmp[++ p] = {id[x], id[y]};

	while(p)
		que[++ qp] = tmp[p --];
}

Hash get(int l, int r) {
	return pre[r] - pre[l - 1] * po[r - l + 1];
}

int check(int p1, int p2, int r) {
	int l = 0;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(get(p1, p1 + mid - 1) == get(p2, p2 + mid - 1))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int main() {
	srand(19491001);
	A = 1 + rand(), B = 1 + rand(), C = 1 + rand();

	int n = read;
	scanf("%s", s + 1);

	for(int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs1(1);
	dfs2(1);

	po[0] = 1;
	for(int i = 1; i <= n * 2; i ++)
		po[i] = po[i - 1] * base;

	pre[0] = 0;
	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] * base + Hash(s[iid[i]]);
	for(int i = 1; i <= n; i ++)
		pre[n + i] = pre[n + i - 1] * base + Hash(s[iid[n - i + 1]]);

	int q = read;
	while(q --) {
		int a = read, b = read, c = read, d = read;

		qp = 0;
		divi(a, b);
		int l1 = 1, r1 = qp;
		divi(c, d);
		int l2 = r1 + 1, r2 = qp;

		int ans = 0;
		while(l1 <= r1 and l2 <= r2) {
			int len = std::min(que[l1].len(), que[l2].len());
			if(get(que[l1].l, que[l1].l + len - 1) ==
					get(que[l2].l, que[l2].l + len - 1)) {
				ans += len;
				que[l1].l += len;
				que[l2].l += len;
				if(que[l1].len() == 0) ++ l1;
				if(que[l2].len() == 0) ++ l2;
			} else {
				ans += check(que[l1].l, que[l2].l, len);
				break;
			}
		}

		printf("%d\n", ans);
	}
}