#if 0
date

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

const int maxn = 500005;
struct Tree {
	int val;
	int lti, rti;
} pool[maxn * 30];
int pp;
#define self pool[now]
#define lt pool[self.lti]
#define rt pool[self.rti]

void lain(int &now, int L, int R, int p) {
	if(!now) now = ++ pp;
	++ self.val;
	if(L == R) return;
	int M = (L + R) >> 1;
	if(p <= M) lain(self.lti, L, M, p);
	else lain(self.rti, M + 1, R, p);
}

int query(int now, int L, int R, int l, int r) {
	if(r < L or l > R) return 0;
	if(l <= L and R <= r) return self.val;
	int M = (L + R) >> 1;
	return query(self.lti, L, M, l, r) + query(self.rti, M + 1, R, l, r);
}

int merge(int a, int b) {
	if(!a) return b;
	if(!b) return a;
	int now = ++ pp;
	self = {pool[a].val + pool[b].val,
		merge(pool[a].lti, pool[b].lti),
		merge(pool[a].rti, pool[b].rti)};
	return now;
}

char s[maxn];
int ch[maxn][26], fa[maxn], len[maxn], cp = 1;
int tree[maxn];

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

int pos[maxn];
std::vector<int> G[maxn];

void dfs(int u) {
	for(int v : G[u]) {
		dfs(v);
		tree[u] = merge(tree[u], tree[v]);
	}
}

int main() {
	int n = read, q = read;
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s);
		int now = 1;
		for(int j = 0; s[j]; j ++) {
			now = insert(now, s[j] - 'a');
			lain(tree[now], 1, n, i);
		}
		now = 1;
		for(int j = 0; s[j]; j ++)
			now = ch[now][s[j] - 'a'];
		pos[i] = now;
	}

	for(int i = 2; i <= cp; i ++)
		G[fa[i]].push_back(i);
	dfs(1);

	// for(int i = 1; i <= cp; i ++)
		// debug("%d: l=%d ch=%d,%d f=%d t=%d\n",
				// i, len[i], ch[i][0], ch[i][1], fa[i], pool[tree[i]].val);

	while(q --) {
		int l = read, r = read, k = read;
		printf("%d\n", query(tree[pos[k]], 1, n, l, r));
	}
}