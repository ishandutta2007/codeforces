#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;

struct BT {
	int *pos, old;
} bt[22222222];
int top;

inline void reg(int *p) { bt[top ++] = {p, *p}; }

inline void backtrack(int ntop) { while (top > ntop) *bt[top - 1].pos = bt[top - 1].old, -- top; }

struct UF {
	int fa[mxn];
	int sz[mxn];
	int xval[mxn];

	UF() { rep(i, mxn) fa[i] = i, sz[i] = 1, xval[i] = 0; }

	inline int find(int x) {
		while (x != fa[x]) x = fa[x];
		return x;
	}

	inline int getval(int x) {
		int ans = 0;
		while (x != fa[x]) ans ^= xval[x], x = fa[x];
		return ans;
	}

	bool merge(int u, int v, int w) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) std::swap(u, v);
		reg(&fa[u]);
		reg(&sz[v]);
		reg(&xval[u]);
		fa[u] = v;
		sz[v] += sz[u];
		xval[u] = w;
		return true;
	}
} uf;

struct LB {
	int v[30];

	bool insert(int x) {
		for (int i = 30 - 1; ~i; -- i) {
			if (x >> i & 1) {
				if (v[i]) x ^= v[i];
				else {
					reg(&v[i]);
					v[i] = x;
					return true;
				}
			}
		}
		return false;
	}

	int query(int x) {
		for (int i = 30 - 1; ~i; -- i) {
			if (x >> i & 1) {
				if (v[i]) {
					x ^= v[i];
				}
			}
		}
		return x;
	}
} lb;

int n, m;
int q;
int qry[mxn << 1][4];
int ans[mxn << 1];

struct SegmentTree {
	static const int mxn = 1 << 19;

	std::vector <int> ops[mxn << 1];

	void update(int l, int r, int v) {
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ops[l ++].push_back(v);
			if (r & 1) ops[-- r].push_back(v);
		}
	}

	void traverse(int i = 1, int a = 0, int b = mxn) {
		int otop = top;
		for (auto x : ops[i]) {
			int u = qry[x][1], v = qry[x][2], w = qry[x][3];
			w ^= uf.getval(u) ^ uf.getval(v);
			if (!uf.merge(u, v, w)) lb.insert(w);
		}
		if (a + 1 == b) {
			if (qry[a][0] == 3) {
				int u = qry[a][1], v = qry[a][2];
				ans[a] = uf.getval(u) ^ uf.getval(v);
				ans[a] = lb.query(ans[a]);
			}
			return ;
		} else {
			int m = (a + b) >> 1;
			traverse(i << 1, a, m);
			traverse(i << 1 | 1, m, b);
		}
		backtrack(otop);
	}
} seg;

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		qry[i][0] = 1;
		scanf("%d %d %d", &qry[i][1], &qry[i][2], &qry[i][3]);
		-- qry[i][1], -- qry[i][2];
	}
	scanf("%d", &q);
	for (int i = m; i < m + q; ++ i) {
		scanf("%d %d %d", &qry[i][0], &qry[i][1], &qry[i][2]);
		-- qry[i][1], -- qry[i][2];
		if (qry[i][0] == 1) scanf("%d", &qry[i][3]);
	}
	std::map <long long, int> id;
	rep(i, m + q) {
		if (qry[i][0] == 1) {
			id[1LL * qry[i][1] * n + qry[i][2]] = i;
		} else if (qry[i][0] == 2) {
			seg.update(id[1LL * qry[i][1] * n + qry[i][2]], i, id[1LL * qry[i][1] * n + qry[i][2]]);
			id.erase(1LL * qry[i][1] * n + qry[i][2]);
		}
	}
	for (auto pr : id) {
		int i = pr.second;
		seg.update(i, m + q, i);
	}
	seg.traverse();
	rep(i, m + q) {
		if (qry[i][0] == 3) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}