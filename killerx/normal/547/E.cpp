#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 1e6 + 5;
const int sigma = 26;

struct suffix_automaton {
	int tot, lst, go[mxn][sigma], len[mxn], link[mxn];

	inline void init() {
		tot = 0;
		lst = new_node(0);
	}

	inline int new_node(int l) {
		int x = ++ tot;
		memset(go[x], 0, sizeof(go[x]));
		len[x] = l;
		link[x] = 0;
		return x;
	}

	inline void append(int c) {
		int p = lst, np = lst = new_node(len[p] + 1);
		for (; p && !go[p][c]; p = link[p]) go[p][c] = np;
		if (!p) link[np] = 1;
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
	}

	std::vector <int> adj[mxn];
	int dfn[mxn], ed[mxn], tim;

	inline void dfs(int u) {
		dfn[u] = tim ++;
		for (int v : adj[u]) {
			dfs(v);
		}
		ed[u] = tim;
	}

	inline void build() {
		for (int i = 2; i <= tot; ++ i) adj[link[i]].push_back(i);
		dfs(1);
	}
} sam;

struct fenwick_tree {
	i64 s[mxn];

	inline void update(int x, i64 v) { for (++ x; x < mxn; x += x & -x) s[x] += v; }

	inline i64 query(int x) { i64 ans = 0; for (++ x; x; x -= x & -x) ans += s[x]; return ans; }

	inline i64 query(int l, int r) { return query(r - 1) - query(l - 1); }
} bit;

struct query {
	int i, x, c;
};

int n, q;
std::string s[mxn];
int nd[mxn];
std::vector <query> qry[mxn];

i64 ans[mxn];

int main() {
	scanf("%d %d", &n, &q);
	sam.init();
	rep(i, n) {
		static char temp[mxn];
		scanf("%s", temp);
		s[i] = temp;
		sam.lst = 1;
		for (char c : s[i]) sam.append(c - 'a');
	}
	sam.build();
	rep(i, n) {
		int u = 1;
		for (char c : s[i]) u = sam.go[u][c - 'a'];
		nd[i] = u;
	}
	rep(i, q) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		-- l, -- k;
		qry[l].push_back({i, nd[k], -1});
		qry[r].push_back({i, nd[k], +1});
	}
	rep(i, n + 1) {
		for (auto Q : qry[i]) {
			// eprintf("%d: ? [%d, %d)\n", Q.i, sam.dfn[Q.x], sam.ed[Q.x]);
			ans[Q.i] += Q.c * bit.query(sam.dfn[Q.x], sam.ed[Q.x]);
		}
		if (i < n) {
			int u = 1;
			for (char c : s[i]) {
				u = sam.go[u][c - 'a'];
				// eprintf("+ %d\n", sam.dfn[u]);
				bit.update(sam.dfn[u], +1);
			}
		}
	}
	rep(i, q) printf("%lld\n", ans[i]);
	return 0;
}