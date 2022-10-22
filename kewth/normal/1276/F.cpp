#if 0
date +%Y.%m.%d

test
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

// SA {{{
const int maxn = 100005;
char s[maxn];
int sa[maxn], rank[maxn], hi[maxn];
int tmp[maxn], sa2[maxn], t[maxn];

void build (int n, int max) {
	for (int i = 1; i <= n; i ++)
		rank[i] = s[i], sa2[i] = i;
	for (int i = 1; i <= n; i ++) ++ t[rank[i]];
	for (int i = 1; i <= max; i ++) t[i] += t[i - 1];
	for (int i = n; i; i --) sa[t[rank[sa2[i]]] --] = sa2[i];
	std::fill(t + 1, t + max + 1, 0);
	int tot = rank[sa[1]] = 1;
	for (int i = 2; i <= n; i ++)
		rank[sa[i]] = s[sa[i]] == s[sa[i - 1]] ? tot : ++ tot;
	for (int m = 1; tot < n; m <<= 1) {
		int p = 0;
		for (int i = 1; i <= m; i ++) sa2[++ p] = n - m + i;
		for (int i = 1; i <= n; i ++) if (sa[i] > m) sa2[++ p] = sa[i] - m;
		for (int i = 1; i <= n; i ++) ++ t[rank[i]];
		for (int i = 1; i <= tot; i ++) t[i] += t[i - 1];
		for (int i = n; i; i --) sa[t[rank[sa2[i]]] --] = sa2[i];
		std::fill(t + 1, t + tot + 1, 0);
		std::copy(rank, rank + n + 1, tmp);
		rank[sa[1]] = tot = 1;
		for (int i = 2; i <= n; i ++)
			rank[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] and
					tmp[sa[i] + m] == tmp[sa[i - 1] + m]) ? tot : ++ tot;
	}
	for (int i = 1; i <= n; i ++) {
		int &k = hi[rank[i]] = std::max(0, hi[rank[i - 1]] - 1);
		while (s[i + k] == s[sa[rank[i] - 1] + k]) ++ k;
	}
}
// }}}

// SAM {{{
const int maxk = 26;
int ch[maxn << 1][maxk], len[maxn << 1], fa[maxn << 1], cp = 1;
std::vector<int> G[maxn << 1];

int insert (int pre, int x) {
	int now = ++ cp;
	len[now] = len[pre] + 1;
	while (pre and !ch[pre][x]) {
		ch[pre][x] = now;
		pre = fa[pre];
	}
	if (pre) {
		int preto = ch[pre][x];
		if (len[preto] == len[pre] + 1)
			fa[now] = preto;
		else {
			int sp = ++ cp;
			len[sp] = len[pre] + 1;
			fa[sp] = fa[preto];
			for (int i = 0; i < maxk; i ++)
				ch[sp][i] = ch[preto][i];
			while (pre and ch[pre][x] == preto) {
				ch[pre][x] = sp;
				pre = fa[pre];
			}
			fa[now] = fa[preto] = sp;
		}
	} else
		fa[now] = 1;
	return now;
}
// }}}

int st[maxn][20], hb[maxn];
void stinit (int n) {
	for (int i = n; i; i --) {
		st[i][0] = hi[i];
		for (int k = 1; i + (1 << k) - 1 <= n; k ++)
			st[i][k] = std::min(st[i][k - 1], st[i + (1 << k >> 1)][k - 1]);
	}
	for (int i = 2; i <= n; i ++)
		hb[i] = hb[i >> 1] + 1;
}

int stquery (int l, int r) {
	int k = hb[r - l + 1];
	return std::min(st[l][k], st[r - (1 << k) + 1][k]);
}

struct Set {
	std::set<int> set;
	ll val;
	void insert (int k, int n) {
		if (set.count(k)) return;
		int l = *(-- set.lower_bound(k));
		int r = *set.upper_bound(k);
		val += n - sa[k] + 1;
		if (l >= 1) val -= stquery(l + 1, k);
		if (r <= n) val -= stquery(k + 1, r);
		if (l >= 1 and r <= n) val += stquery(l + 1, r);
		set.insert(k);
	}
	void init (int n) { set.insert(0), set.insert(n + 1); }
} set[maxn << 1];

ll ans;
void dfs (int u, int n) {
	for (int v : G[u]) {
		dfs(v, n);
		if (set[v].set.size() > set[u].set.size())
			std::swap(set[u], set[v]);
		for (int k : set[v].set)
			set[u].insert(k, n);
	}
	/* debug("%d : %d |", u, set[u].val); */
	/* for (int k : pool[set[u].id]) */
	/* 	if (k != 0 and k != n + 1) */
	/* 		debug(" %d", k); */
	/* debug("\n"); */
	ans += 1ll * (len[u] - len[fa[u]]) * set[u].val;
}

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	int sam = 1;
	for (int i = 1; i <= n; i ++)
		sam = insert(sam, s[i] - 'a');
	build(n, 256);

	/* for (int i = 1; i <= cp; i ++) */
	/* 	debug("%d: fa=%d len=%d\n", i, fa[i], len[i]); */

	for (int i = 1; i <= cp; i ++)
		set[i].init(n);
	stinit(n);

	sam = 1;
	set[sam].insert(rank[2], n);
	for (int i = 1; i <= n; i ++) {
		sam = ch[sam][s[i] - 'a'];
		if(i + 2 <= n) set[sam].insert(rank[i + 2], n);
	}

	// s
	for (int i = 1; i <= cp; i ++)
		ans += len[i] - len[fa[i]];
	// s*s
	for (int i = 2; i <= cp; i ++)
		G[fa[i]].push_back(i);
	dfs(1, n);
	// s*
	for (int i = 1; i <= cp; i ++)
		if (i != sam)
			ans += len[i] - len[fa[i]];
	ans += set[1].val; // *s
	++ ans; // *
	++ ans; // (empty)

	printf("%lld\n", ans);
}