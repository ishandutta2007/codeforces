#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 2e5 + 5, sigma = 26, block = 444;

struct suffix_automaton {
	int tot, rt, go[mxn][sigma], len[mxn], link[mxn];
	inline int new_node(int l) {
		int x = ++ tot;
		memset(go[x], 0, sizeof(go[x]));
		len[x] = l;
		link[x] = 0;
		return x;
	}
	inline void init() {
		tot = 0;
		rt = new_node(0);
	}
	inline int append(int c, int lst) {
		int p = lst, np = new_node(len[p] + 1);
		for (; p && !go[p][c]; p = link[p]) go[p][c] = np;
		if (!p) link[np] = rt;
		else {
			int q = go[p][c];
			if (len[q] == len[p] + 1) link[np] = q;
			else {
				int nq = new_node(len[p] + 1);
				memcpy(go[nq], go[q], sizeof(go[q]));
				link[nq] = link[q]; link[q] = link[np] = nq;
				for (; go[p][c] == q; p = link[p]) go[p][c] = nq;
			}
		}
		return np;
	}
	std::vector <int> adj[mxn];
	int dfn[mxn], ed[mxn], tim;
	inline void predfs(int u) {
		dfn[u] = ++ tim;
		for (int v : adj[u]) predfs(v);
		ed[u] = tim;
	}
	inline void build() {
		for (int i = 1; i <= tot; ++ i) adj[i].clear();
		for (int i = 2; i <= tot; ++ i) adj[link[i]].push_back(i);
		tim = 0;
		predfs(rt);
	}
	int cnt[mxn];
	inline void dfs(int u) {
		for (int v : adj[u]) {
			dfs(v);
			cnt[u] += cnt[v];
		}
	}
} sam;

struct trie_tree {
	int tot, go[mxn][sigma], nd_sam[mxn];
	inline void init() {
		tot = 0;
	}
	inline int new_node() {
		int x = ++ tot;
		memset(go[x], 0, sizeof(go[x]));
		nd_sam[x] = 0;
		return x;
	}
	inline int insert(std::string s) {
		int u = 0;
		for (char c : s) {
			int &v = go[u][c - 'a'];
			if (!v) v = new_node();
			u = v;
		}
		return u;
	}
	inline void build() {
		sam.init();
		nd_sam[0] = sam.rt;
		std::vector <int> que;
		que.push_back(0);
		rep(i, que.size()) {
			int u = que[i];
			rep(c, sigma) if (go[u][c]) {
				nd_sam[go[u][c]] = sam.append(c, nd_sam[u]);
				que.push_back(go[u][c]);
			}
		}
		sam.build();
	}
} trie;

int n, q;
std::string s[mxn];
int nd_trie[mxn];
i64 ans[mxn];
struct Query { int r, k, c, i; } qry[mxn];
std::vector <int> vqry_k[mxn], vqry_r[mxn];

namespace BlockDS {
	int S[mxn], Sb[mxn / block + 1];
	inline void Update(int l, int r, int v) {
		-- l;
		for (; l < r && l % block; ++ l) S[l] += v;
		for (; l + block <= r; l += block) Sb[l / block] += v;
		for (; l < r; ++ l) S[l] += v;
	}
	inline int Query(int p) {
		-- p;
		return S[p] + Sb[p / block];
	}
}
using BlockDS::Update;
using BlockDS::Query;

int main() {
	scanf("%d %d", &n, &q);
	trie.init();
	rep(i, n) {
		static char temp[mxn];
		scanf("%s", temp);
		s[i] = temp;
		nd_trie[i] = trie.insert(s[i]);
	}
	trie.build();
	rep(i, q) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		-- l, -- k;
		qry[i << 1] = {r, k, +1, i};
		qry[i << 1 | 1] = {l, k, -1, i};
	}
	rep(i, q << 1) vqry_k[qry[i].k].push_back(i);
	rep(i, q << 1) vqry_r[qry[i].r].push_back(i);
	rep(i, n) if ((int) s[i].size() >= block) {
		memset(sam.cnt, 0, sizeof(sam.cnt));
		for (int j = 0, u = sam.rt; j < (int) s[i].size(); ++ j)
			u = sam.go[u][s[i][j] - 'a'], ++ sam.cnt[u];
		sam.dfs(sam.rt);
		static i64 sum[mxn];
		rep(j, n) sum[j + 1] = sum[j] + sam.cnt[trie.nd_sam[nd_trie[j]]];
		for (int qi : vqry_k[i]) ans[qry[qi].i] += qry[qi].c * sum[qry[qi].r];
	}
	rep(i, n + 1) {
		for (int qi : vqry_r[i]) {
			if ((int) s[qry[qi].k].size() >= block) continue;
			for (int j = 0, u = sam.rt; j < (int) s[qry[qi].k].size(); ++ j) {
				u = sam.go[u][s[qry[qi].k][j] - 'a'];
				ans[qry[qi].i] += qry[qi].c * Query(sam.dfn[u]);
			}
		}
		if (i < n) {
			int u = trie.nd_sam[nd_trie[i]];
			Update(sam.dfn[u], sam.ed[u], 1);
		}
	}
	rep(i, q) printf("%lld\n", ans[i]);
	return 0;
}