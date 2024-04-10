#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)

typedef long long i64;

const int mxn = 2e5 + 5;
const int mxlg = 18;

int n;
std::vector <int> adj[mxn];

namespace Tree {
	int fa[mxn], dep[mxn], jmp[mxn][mxlg];
	int dfn[mxn], ed[mxn], on[mxn], tim;

	void dfs0(int u, int p) {
		on[tim] = u;
		dfn[u] = tim ++;
		jmp[u][0] = fa[u];
		rep(i, mxlg - 1) jmp[u][i + 1] = jmp[jmp[u][i]][i];
		for (int v : adj[u]) {
			if (v == p) continue;
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs0(v, u);
		}
		ed[u] = tim;
	}

	int lca(int u, int v) {
		if (dep[u] > dep[v]) std::swap(u, v);
		rep(i, mxlg) if ((dep[v] - dep[u]) >> i & 1) v = jmp[v][i];
		if (u == v) return u;
		for (int i = mxlg - 1; ~i; -- i) if (jmp[u][i] != jmp[v][i])
			u = jmp[u][i], v = jmp[v][i];
		return jmp[u][0];
	}

	int dist(int u, int v) {
		int l = lca(u, v);
		return dep[u] + dep[v] - 2 * dep[l];
	}

	void init() {
		tim = 0;
		dfs0(0, -1);
	}

	bool comp_dfn(int a, int b) { return dfn[a] < dfn[b]; }

	void intersect(int a1, int b1, int a2, int b2, int &c1, int &c2) {
		static int vec[15];
		int vsz = 0;
		vec[vsz ++] = a1;
		vec[vsz ++] = b1;
		vec[vsz ++] = a2;
		vec[vsz ++] = b2;
		std::sort(vec, vec + vsz, comp_dfn);
		int osz = vsz;
		rep(i, osz - 1) vec[vsz ++] = lca(vec[i], vec[i + 1]);
		std::sort(vec, vec + vsz, comp_dfn);
		vsz = std::unique(vec, vec + vsz) - vec;
		static int cnt[mxn], nfa[mxn], ndep[mxn];
		static std::vector <int> nadj[mxn];
		rep(i, vsz) {
			int u = vec[i];
			cnt[u] = 0;
			ndep[u] = 0;
			nadj[u].clear();
		}
		static int stk[15];
		int top = 0;
		rep(i, vsz) {
			while (top && !(dfn[stk[top - 1]] <= dfn[vec[i]] && ed[vec[i]] <= ed[stk[top - 1]])) -- top;
			if (top) nadj[stk[top - 1]].push_back(vec[i]), nfa[vec[i]] = stk[top - 1], ndep[vec[i]] = ndep[stk[top - 1]] + 1;
			stk[top ++] = vec[i];
		}
		auto paint = [&] (int u, int v) {
			if (ndep[u] > ndep[v]) std::swap(u, v);
			while (ndep[v] > ndep[u]) {
				++ cnt[v];
				v = nfa[v];
			}
			while (u != v) {
				++ cnt[u];
				++ cnt[v];
				u = nfa[u];
				v = nfa[v];
			}
			++ cnt[u];
		};
		paint(a1, b1);
		paint(a2, b2);
		std::function <void (int)> dfs;
		std::function <void (int, int&)> fnd;
		c1 = c2 = -1;
		fnd = [&] (int u, int &ans) {
			if (cnt[u] == 2) ans = u;
			else return ;
			for (int v : nadj[u]) {
				fnd(v, ans);
			}
		};
		dfs = [&] (int u) {
			if (cnt[u] == 2) {
				for (int v : nadj[u]) {
					if (c1 == -1) fnd(v, c1);
					else fnd(v, c2);
				}
				if (c1 == -1) c1 = u;
				if (c2 == -1) c2 = u;
				return ;
			}
			for (int v : nadj[u]) {
				dfs(v);
			}
		};
		dfs(vec[0]);
	}
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
	if (!b) { x = 1; y = 0; return a; }
	else {
		int d = exgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return d;
	}
}

int inv(int x, int n) {
	int a, b;
	int d = exgcd(x, n, a, b);
	assert(d == 1);
	return (a % n + n) % n;
}

// A + kA dA == B + kB dB
i64 clash(int A, int dA, int B, int dB) {
	// eprintf("%d + kA %d == %d + kB %d\n", A, dA, B, dB);
	if (dA == dB) {
		if (A != B) return 1LL << 60;
		return A;
	}
	if (dA > dB) {
		std::swap(A, B);
		std::swap(dA, dB);
	}
	// k dA == B - A (mod dB)
	int tar = (B + dB - A) % dB;
	int g = gcd(dA, dB);
	if (tar % g != 0) return 1LL << 60;
	int x = inv(dA / g, dB / g);
	int tms = 1LL * (tar / g) * x % (dB / g);
	i64 ans = A + 1LL * tms * dA;
	// eprintf("res: %lld\n", ans);
	return ans;
}

// x + k delta <= len (mod n)
i64 bang(int A, int dA, int x, int delta, int len, int n) {
	// eprintf("%d + k %d <= %d (mod %d)\n", x, delta, len, n);
	if (x <= len) return A;
	if (delta == 0) return 1LL << 60;
	if (delta > n - delta) {
		int ndelta = n - delta;
		// (n - x) % n + k ndelta >= (n - len) % n (mod n)
		int nx = (n - x + n - (n - len)) % n;
		return bang(A, dA, nx, ndelta, len, n);
	}
	int base = (n - x + delta - 1) / delta;
	int nx = (x + 1LL * base * delta) % n;
	if (nx <= len) return A + 1LL * base * dA;
	int tms = (n + delta - 1) / delta;
	int stp = tms * delta - n;
	i64 temp = bang(0, 1, nx, stp, len, delta);
	if (temp >= 1LL << 60) return 1LL << 60;
	i64 real = temp * tms - (nx + temp * stp) / delta;
	i64 ans = A + 1LL * dA * (base + real);
	return ans;
}

// A + kA dA \in [Bl, Br] + kB dB
i64 boom(int A, int dA, int Bl, int Br, int dB) {
	// eprintf("%d + kA %d in [%d, %d] + kB %d\n", A, dA, Bl, Br, dB);
	/*
	i64 ans = 1LL << 60;
	for (int B = Bl; B <= Br; ++ B) {
		i64 P = clash(A, dA, B, dB);
		if (P < 1LL << 60) {
			assert((Br - B) % 2 == 0);
			ans = std::min(ans, P);
		}
	}
	eprintf("res: %lld\n", ans);
	// return ans;
	*/
	int x = (A - Bl + dB) % dB;
	int delta = dA % dB;
	int len = Br - Bl;
	int n = dB;
	i64 real = bang(A, dA, x, delta, len, n);
	// eprintf("real: %lld\n", real);
	return real;
}

i64 drill(int A, int dA, int Bl, int Br, int dB) {
	i64 ovo = boom(A, dA, Bl, Br, dB);
	if (ovo >= 1LL << 60) return 1LL << 60;
	return ovo + (Br - ovo % dB) / 2;
}

i64 Query(int a1, int b1, int a2, int b2) {
	// eprintf("Query %d %d %d %d\n", a1 + 1, b1 + 1, a2 + 1, b2 + 1);
	int c1, c2;
	Tree::intersect(a1, b1, a2, b2, c1, c2);
	// eprintf("intersect: [%d, %d]\n", c1 + 1, c2 + 1);
	if (c1 == -1) return -1;
	int a = std::min(Tree::dist(a1, c1), Tree::dist(a1, c2));
	int b = std::min(Tree::dist(a2, c1), Tree::dist(a2, c2));
	int c = Tree::dist(c1, c2);
	int d = std::min(Tree::dist(b1, c1), Tree::dist(b1, c2));
	int e = std::min(Tree::dist(b2, c1), Tree::dist(b2, c2));
	int A = a + c + d, B = b + c + e;
	assert(A == Tree::dist(a1, b1));
	assert(B == Tree::dist(a2, b2));
	i64 ans = 1LL << 60;
	int aR = Tree::dist(a1, c1) <= Tree::dist(a1, c2) ? a : a + c + 2 * d;
	int aL = Tree::dist(a1, c1) <= Tree::dist(a1, c2) ? a + c + 2 * d : a;
	int bR = Tree::dist(a2, c1) <= Tree::dist(a2, c2) ? b : b + c + 2 * e;
	int bL = Tree::dist(a2, c1) <= Tree::dist(a2, c2) ? b + c + 2 * e : b;
	// eprintf("%d %d %d %d	%d %d\n", aR, aL, bR, bL, A, B);
	ans = std::min(ans, clash(aR, 2 * A, bR, 2 * B));
	ans = std::min(ans, clash(aL, 2 * A, bL, 2 * B));
	if ((aL + bR + c) % 2 == 0) {
		ans = std::min(ans, drill(aL, 2 * A, bR, bR + c, 2 * B));
		ans = std::min(ans, drill(bR, 2 * B, aL, aL + c, 2 * A));
	}
	if ((aR + bL + c) % 2 == 0) {
		ans = std::min(ans, drill(aR, 2 * A, bL, bL + c, 2 * B));
		ans = std::min(ans, drill(bL, 2 * B, aR, aR + c, 2 * A));
	}
	return ans >= 1LL << 60 ? -1 : ans;
}

int main() {
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Tree::init();
	int q;
	scanf("%d", &q);
	while (q --) {
		int a1, b1, a2, b2;
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		-- a1, -- b1, -- a2, -- b2;
		printf("%lld\n", Query(a1, b1, a2, b2));
	}
	return 0;
}