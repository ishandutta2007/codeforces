#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 550005, maxk = 19;
struct Data {
	int max, pos;
};
inline Data operator + (Data l, Data r) {
	return l.max >= r.max ? l : r;
}

struct Tree {
	Data val;
	int lti, rti;
} pool[maxn * 40];
int pp;
#define self pool[now]
#define lt pool[self.lti]
#define rt pool[self.rti]

void lain(int &now, int L, int R, int p) {
	if(!now) now = ++ pp;
	self.val = {1, p};
	if(L == R) return;
	int M = (L + R) >> 1;
	if(p <= M) lain(self.lti, L, M, p);
	else lain(self.rti, M + 1, R, p);
}

Data query(int now, int L, int R, int l, int r) {
	if(r < L or l > R or !now) return {0, l};
	if(l <= L and R <= r) return self.val;
	int M = (L + R) >> 1;
	return query(self.lti, L, M, l, r) + query(self.rti, M + 1, R, l, r);
}

int merge(int a, int b, int L, int R) {
	if(!a) return b;
	if(!b) return a;
	int now = ++ pp;
	if(L == R)
		return self.val = {pool[a].val.max +
			pool[b].val.max, L}, now;
	int M = (L + R) >> 1;
	self.lti = merge(pool[a].lti, pool[b].lti, L, M);
	self.rti = merge(pool[a].rti, pool[b].rti, M + 1, R);
	self.val = lt.val + rt.val;
	return now;
}

int ch[maxn << 1][26], fa[maxn << 1], len[maxn << 1], cp = 1;
int tree[maxn << 1];

int insert(int pre, int x) {
	int now = ++ cp;
	len[now] = len[pre] + 1;

	while(pre and !ch[pre][x]) {
		ch[pre][x] = now;
		pre = fa[pre];
	}

	if(pre) {
		int preto = ch[pre][x];
		if(len[preto] == len[pre] + 1)
			fa[now] = preto;
		else {
			int sp = ++ cp;
			len[sp] = len[pre] + 1;
			for(int k = 0; k < 26; k ++)
				ch[sp][k] = ch[preto][k];
			fa[sp] = fa[preto];

			while(pre and ch[pre][x] == preto) {
				ch[pre][x] = sp;
				pre = fa[pre];
			}

			fa[now] = fa[preto] = sp;
		}
	} else
		fa[now] = 1;
	return now;
}

char s[maxn];
int pos[maxn];
std::vector<int> G[maxn << 1];
int fak[maxn << 1][maxk];

void dfs(int u, int n) {
	for(int k = 1; k < maxk; k ++)
		fak[u][k] = fak[fak[u][k - 1]][k - 1];
	for(int v : G[u]) {
		fak[v][0] = u;
		dfs(v, n);
		tree[u] = merge(tree[u], tree[v], 1, n);
	}
}

int main() {
	scanf("%s", s + 1);
	pos[0] = 1;
	for(int i = 1; s[i]; i ++)
		pos[i] = insert(pos[i - 1], s[i] - 'a');

	int n = read;
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s);
		int now = 1;
		for(int j = 0; s[j]; j ++) {
			now = insert(now, s[j] - 'a');
			lain(tree[now], 1, n, i);
		}
	}

	for(int i = 2; i <= cp; i ++)
		G[fa[i]].push_back(i);
	dfs(1, n);

	int q = read;
	while(q --) {
		int l = read, r = read, lp = read, rp = read;
		int now = pos[rp];
		for(int k = maxk - 1; k >= 0; k --)
			if(len[fak[now][k]] >= rp - lp + 1)
				now = fak[now][k];
		Data ans = query(tree[now], 1, n, l, r);
		printf("%d %d\n", ans.pos, ans.max);
	}
}