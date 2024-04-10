#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)

const int mod = 1e9 + 7;

namespace FIO {
	const int mxsz = 1 << 23;
	char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
	char obuf[mxsz], *oend = obuf + mxsz, *opos = obuf;

	char get_char() {
		if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
		return ipos == iend ? EOF : *ipos ++;
	}

	void put_char(char c) {
		if (opos == oend) fwrite(opos = obuf, 1, mxsz, stdout);
		*opos ++ = c;
	}

	int read_int() {
		int x = 0, c = get_char();
		while (c <= 32) c = get_char();
		while (c > 32) x = x * 10 + c - 48, c = get_char();
		return x;
	}

	void read_str(char *S) {
		while ((*S = get_char()) <= 32);
		while ((*++ S = get_char()) > 32);
		*S = 0;
	}

	void write_int(int x) {
		static char stk[20];
		if (x < 0) put_char(45), x *= -1;
		if (x == 0) put_char(48);
		int top = 0;
		while (x) stk[top ++] = x % 10 + 48, x /= 10;
		while (top --) put_char(stk[top]);
		put_char(10);
	}

	void flush() {
		fwrite(obuf, 1, opos - obuf, stdout);
		opos = obuf;
	}
}

using FIO::read_int;
using FIO::read_str;
using FIO::write_int;
using FIO::flush;

const int mxn = 1 << 19;

int n, q;
char expr[mxn];

int jmp[mxn];
int lv[mxn];

std::vector <int> vplus[mxn], vmul[mxn];
std::vector <int> elem;

int L[mxn], R[mxn];

namespace BracketChecker {
	struct Node {
		int a, b;

		Node(): a(), b() {}

		Node(int _a, int _b): a(_a), b(_b) {}
	};

	Node operator + (const Node &a, const Node &b) {
		if (a.b <= b.a) return Node(a.a + b.a - a.b, b.b);
		else return Node(a.a, a.b - b.a + b.b);
	}

	Node t[mxn << 1];

	void init() {
		for (int i = 0; i < n; ++ i) {
			if (expr[i] == '(') t[i + mxn] = Node(0, 1);
			else if (expr[i] == ')') t[i + mxn] = Node(1, 0);
			else t[i + mxn] = Node(0, 0);
		}
		for (int i = n; i < mxn; ++ i) t[i + mxn] = Node(0, 0);
		for (int i = mxn - 1; i; -- i) t[i] = t[i << 1] + t[i << 1 | 1];
	}

	Node query(int l, int r) {
		Node ansl = Node(0, 0);
		Node ansr = Node(0, 0);
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ansl = ansl + t[l ++];
			if (r & 1) ansr = t[-- r] + ansr;
		}
		return ansl + ansr;
	}

	bool check(int l, int r) {
		Node s = query(l, r);
		return s.a == 0 && s.b == 0;
	}
}

int pw10[mxn];

namespace Number {
	int va[mxn << 1], len[mxn << 1];

	void merge(int vl, int ll, int vr, int lr, int &v, int &l) {
		v = (1LL * vl * pw10[lr] + vr) % mod;
		l = ll + lr;
	}

	void init() {
		rep(i, n) if (isdigit(expr[i])) va[i + mxn] = expr[i] - '0', len[i + mxn] = 1;
		else va[i + mxn] = 0, len[i + mxn] = 0;
		for (int i = mxn - 1; i; -- i) merge(va[i << 1], len[i << 1], va[i << 1 | 1], len[i << 1 | 1], va[i], len[i]);
	}

	int query(int l, int r) {
		int vl = 0, ll = 0, vr = 0, lr = 0;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) merge(vl, ll, va[l], len[l], vl, ll), ++ l;
			if (r & 1) -- r, merge(va[r], len[r], vr, lr, vr, lr);
		}
		int ans_va, ans_len;
		merge(vl, ll, vr, lr, ans_va, ans_len);
		return ans_va;
	}
}

int ans[mxn];

namespace Tree {
	const int MUL = 0;
	const int ADD = 1;
	const int CONCAT = 2;
	int tot, rt;
	std::vector <int> adj[mxn << 1];
	int type[mxn << 1];

	int build(int l, int r) {
		// eprintf("[%d, %d)\n", l, r);
		int pl = std::lower_bound(vplus[lv[l]].begin(), vplus[lv[l]].end(), l) - vplus[lv[l]].begin();
		int pr = std::lower_bound(vplus[lv[l]].begin(), vplus[lv[l]].end(), r) - vplus[lv[l]].begin();
		if (pl < pr) {
			int u = tot ++;
			type[u] = ADD;
			int las = l;
			for (int x = pl; x < pr; ++ x) {
				adj[u].push_back(build(las, vplus[lv[l]][x]));
				las = vplus[lv[l]][x] + 1;
			}
			adj[u].push_back(build(las, r));
			return u;
		}
		int ml = std::lower_bound(vmul[lv[l]].begin(), vmul[lv[l]].end(), l) - vmul[lv[l]].begin();
		int mr = std::lower_bound(vmul[lv[l]].begin(), vmul[lv[l]].end(), r) - vmul[lv[l]].begin();
		if (ml < mr) {
			int u = tot ++;
			type[u] = MUL;
			int las = l;
			for (int x = ml; x < mr; ++ x) {
				adj[u].push_back(build(las, vmul[lv[l]][x]));
				las = vmul[lv[l]][x] + 1;
			}
			adj[u].push_back(build(las, r));
			return u;
		}
		if (jmp[l] == r - 1) return build(l + 1, r - 1);
		int u = tot ++;
		type[u] = CONCAT;
		for (int x = l; x < r; ++ x)
			adj[u].push_back(x);
		return u;
	}

	struct Tag {
		int a, b;
	
		Tag(): a(1), b(0) {}
	
		Tag(int _a, int _b): a(_a), b(_b) {}
	};

	Tag operator + (const Tag &a, const Tag &b) { return Tag(1LL * a.a * b.a % mod, (1LL * a.b * b.a + b.b) % mod); }

	struct SegmentTree {
		static const int mxlg = 19;
		Tag ta[mxn << 1];

		void push(int x, Tag t) {
			ta[x] = ta[x] + t;
		}

		void pushdown(int x) {
			if (ta[x].a != 1 || ta[x].b != 0) {
				push(x << 1, ta[x]);
				push(x << 1 | 1, ta[x]);
				ta[x] = Tag();
			}
		}

		void init() {
			for (int i = 1; i < mxn << 1; ++ i) ta[i] = Tag();
		}

		void update(int l, int r, Tag t) {
			l += mxn, r += mxn;
			for (int i = mxlg; i; -- i) {
				if (((l >> i) << i) != l) pushdown(l >> i);
				if (((r >> i) << i) != r) pushdown(r >> i);
			}
			for (; l < r; l >>= 1, r >>= 1) {
				if (l & 1) push(l ++, t);
				if (r & 1) push(-- r, t);
			}
		}

		int query(int x) {
			x += mxn;
			for (int i = mxlg; i; -- i) pushdown(x >> i);
			return ta[x].b;
		}
	} pre, suf;

	const int mxlg = 20;

	int fa[mxn << 1][mxlg];
	int dep[mxn << 1];

	void dfs0(int u) {
		rep(i, mxlg - 1) fa[u][i + 1] = fa[fa[u][i]][i];
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			fa[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs0(v);
		}
	}

	void init() {
		tot = n;
		rt = build(0, n);
		fa[rt][0] = rt;
		dep[rt] = 0;
		dfs0(rt);
	}

	int lca(int u, int v) {
		if (dep[u] > dep[v]) std::swap(u, v);
		rep(i, mxlg) if ((dep[v] - dep[u]) >> i & 1) v = fa[v][i];
		if (u == v) return u;
		for (int i = mxlg - 1; ~i; -- i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	}

	int jmp(int u, int v) {
		for (int i = mxlg - 1; ~i; -- i) {
			if (dep[fa[u][i]] > dep[v]) {
				u = fa[u][i];
			}
		}
		return u;
	}

	struct Query {
		int x1, x2, v1, v2, id;

		Query(int _x1, int _x2, int _v1, int _v2, int _id): x1(_x1), x2(_x2), v1(_v1), v2(_v2), id(_id) {}
	};

	std::vector <Query> qry[mxn << 1];
	int boundl[mxn << 1], boundr[mxn << 1];

	void reg_query(int u, int x1, int x2, int v1, int v2, int id) {
		qry[u].push_back(Query(x1, x2, v1, v2, id));
	}

	int bsearch(int u, int v) {
		int lb = 0, rb = (int) adj[u].size() - 1;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (boundl[adj[u][md]] < boundl[v]) lb = md + 1;
			else rb = md;
		}
		return lb;
	}

	int TYPE;

	int merge(int a, int b) {
		return TYPE == MUL ? 1LL * a * b % mod : (a + b) % mod;
	}

	int sz;
	int seg_mini[mxn << 1];

	void init_mini(int n, const std::vector <int> &vec) {
		sz = 1;
		while (sz < n) sz <<= 1;
		rep(i, n) seg_mini[i + sz] = vec[i];
		for (int i = n; i < sz; ++ i) seg_mini[i + sz] = TYPE == MUL ? 1 : 0;
		for (int i = sz - 1; i; -- i) seg_mini[i] = merge(seg_mini[i << 1], seg_mini[i << 1 | 1]);
	}

	int query_mini(int l, int r) {
		int ansl = TYPE == MUL ? 1 : 0;
		int ansr = TYPE == MUL ? 1 : 0;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ansl = merge(ansl, seg_mini[l ++]);
			if (r & 1) ansr = merge(seg_mini[-- r], ansr);
		}
		return merge(ansl, ansr);
	}

	void dfs1(int u) {
		if (u < n) {
			boundl[u] = u;
			boundr[u] = u;
			return ;
		}
		boundl[u] = 0x3f3f3f3f;
		boundr[u] = -0x3f3f3f3f;
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			dfs1(v);
			boundl[u] = std::min(boundl[u], boundl[v]);
			boundr[u] = std::max(boundr[u], boundr[v]);
		}
		TYPE = type[u];
		std::vector <int> vadj(adj[u].size());
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			vadj[i] = pre.query(boundr[v]);
		}
		init_mini(adj[u].size(), vadj);
		for (Query Q : qry[u]) {
			int x1 = Q.x1;
			int x2 = Q.x2;
			int v1 = Q.v1;
			int v2 = Q.v2;
			int id = Q.id;
			int p1 = bsearch(u, v1);
			int p2 = bsearch(u, v2);
			if (TYPE == CONCAT) {
				ans[id] = Number::query(v1, v2 + 1);
			} else {
				// eprintf("%s %d\n", TYPE == MUL ? "mul" : "add", id + 1);
				ans[id] = merge(merge(suf.query(x1), query_mini(p1 + 1, p2)), pre.query(x2));
			}
		}
		if (TYPE == CONCAT) {
			int now = 0;
			for (int i = 0; i < (int) adj[u].size(); ++ i) {
				int v = adj[u][i];
				now = (10LL * now + expr[v] - '0') % mod;
				pre.update(v, v + 1, Tag(0, now));
			}
			now = 0;
			for (int i = (int) adj[u].size() - 1; ~i; -- i) {
				int v = adj[u][i];
				now = (now + 1LL * pw10[(int) adj[u].size() - 1 - i] * (expr[v] - '0')) % mod;
				suf.update(v, v + 1, Tag(0, now));
			}
		} else {
			Tag now = Tag();
			for (int i = 0; i < (int) adj[u].size(); ++ i) {
				int v = adj[u][i];
				pre.update(boundl[v], boundr[v] + 1, now);
				int x = vadj[i];
				if (TYPE == MUL) now.a = 1LL * now.a * x % mod;
				else now.b = (now.b + x) % mod;
			}
			now = Tag();
			for (int i = (int) adj[u].size() - 1; ~i; -- i) {
				int v = adj[u][i];
				suf.update(boundl[v], boundr[v] + 1, now);
				int x = vadj[i];
				if (TYPE == MUL) now.a = 1LL * now.a * x % mod;
				else now.b = (now.b + x) % mod;
			}
		}
	}

	void proc() {
		pre.init();
		suf.init();
		dfs1(rt);
	}
}

int main() {
	rep(i, mxn) pw10[i] = i ? 10LL * pw10[i - 1] % mod : 1;
	// freopen("calc.in", "r", stdin);
	// freopen("calc.out", "w", stdout);
	// n = read_int();
	read_str(expr);
	n = strlen(expr);
	q = read_int();
	// eprintf("%s\n", expr);
	{
		static int stk[mxn];
		int top = 0;
		rep(i, n) {
			jmp[i] = -1;
			if (expr[i] == '(') {
				stk[top ++] = i;
			} else if (expr[i] == ')') {
				-- top;
				jmp[i] = stk[top];
				jmp[stk[top]] = i;
			}
		}
		rep(i, n) {
			lv[i + 1] = lv[i];
			if (expr[i] == '(') ++ lv[i + 1];
			else if (expr[i] == ')') -- lv[i + 1];
		}
		rep(i, n) {
			if (expr[i] == '+') vplus[lv[i]].push_back(i);
			else if (expr[i] == '*') vmul[lv[i]].push_back(i);
		}
	}
	BracketChecker::init();
	rep(i, n) if (isdigit(expr[i])) elem.push_back(i);
	Tree::init();
	rep(i, q) {
		L[i] = read_int() - 1;
		R[i] = read_int() - 1;
		bool fail = false;
		fail |= !BracketChecker::check(L[i], R[i] + 1);
		fail |= expr[L[i]] == '+' || expr[L[i]] == '*';
		fail |= expr[R[i]] == '+' || expr[R[i]] == '*';
		if (fail) {
			ans[i] = -1;
			continue;
		}
		int u = elem[std::lower_bound(elem.begin(), elem.end(), L[i]) - elem.begin()];
		int v = elem[std::upper_bound(elem.begin(), elem.end(), R[i]) - elem.begin() - 1];
		if (u == v) {
			ans[i] = expr[u] - '0';
			continue;
		}
		int l = Tree::lca(u, v);
		int ju = Tree::jmp(u, l);
		int jv = Tree::jmp(v, l);
		Tree::reg_query(l, u, v, ju, jv, i);
	}
	Number::init();
	Tree::proc();
	rep(i, q) write_int(ans[i]);
	flush();
	return 0;
}