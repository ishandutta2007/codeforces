#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 4e5 + 5;

int n, m;

inline bool check(char c1, char c2, char v1, char v2) {
	return (c1 == v1 && c2 == v2) || (c1 == v2 && c2 == v1);
}

int getid(char c, int p) {
	return c == 'L' ? p : c == 'T' ? p + n : c == 'R' ? p + n + m : p + n * 2 + m;
}

int getdir(char c1, char c2) {
	static const char temp[] = "LTRB";
	int p1 = strchr(temp, c1) - temp;
	int p2 = strchr(temp, c2) - temp;
	return (p1 << 2 | p2) + 5;
}

inline int GG(int x) {
	int a = x >> 2, b = x & 3;
	return b << 2 | a;
}

inline int INV(int x) {
	if (x < 5) return x;
	return GG(x - 5) + 5;
}

const int moda = 1e9 + 7, modb = 1e9 + 9;

struct hashval {
	int a, b;

	hashval(): a(), b() {}
	hashval(int x): a(x), b(x) {}
	hashval(int _a, int _b): a(_a), b(_b) {}

	friend inline hashval operator + (const hashval &a, const hashval &b) { return {(a.a + b.a) % moda, (a.b + b.b) % modb}; }
	friend inline hashval operator - (const hashval &a, const hashval &b) { return {(a.a + moda - b.a) % moda, (a.b + modb - b.b) % modb}; }
	friend inline hashval operator * (const hashval &a, const hashval &b) { return {1LL * a.a * b.a % moda, 1LL * a.b * b.b % modb}; }

	friend inline bool operator < (const hashval &a, const hashval &b) { return a.a != b.a ? a.a < b.a : a.b < b.b; }
	friend inline bool operator == (const hashval &a, const hashval &b) { return a.a == b.a && a.b == b.b; }

	friend std::ostream &operator << (std::ostream &o, const hashval &v) {
		return o << "(" << v.a << ", " << v.b << ")";
	}
};

const hashval mul = {29, 31};

hashval min_repr(std::vector <int> str, std::vector <int> &ids) {
	hashval A = {moda, modb};
	std::vector <int> B;
	rep(TP, 2) {
		std::vector <hashval> pw(str.size() + 1);
		rep(i, str.size() + 1) pw[i] = i ? mul * pw[i - 1] : hashval(1);
		std::vector <hashval> pre(str.size() + 1);
		rep(i, str.size()) pre[i + 1] = pre[i] * mul + hashval(str[i]);
		std::function <hashval(int, int)> gethash = [&] (int l, int r) { return pre[r] - pre[l] * pw[r - l]; };
		hashval min = {moda, modb};
		int mins = -1;
		rep(s, str.size()) {
			hashval gg = gethash(s, str.size()) * pw[s] + gethash(0, s);
			if (gg < min) min = gg, mins = s;
		}
		if (min < A) {
			A = min;
			std::vector <int> rids;
			rep(i, str.size()) rids.push_back(ids[(mins + i) % str.size()]);
			rids.swap(B);
		}
		std::reverse(ids.begin() + 1, ids.end());
		std::reverse(str.begin(), str.end());
		for (int &c : str) c = INV(c);
	}
	ids = B;
	return A;
}

struct graph {
	int tot;
	std::vector <std::pair <int, std::pair <int, int> > > adj[mxn];

	graph() { tot = 0; }

	void build() {
		rep(i, n) {
			adj[getid('L', i)].push_back({getid('R', i), {1, tot}});
			adj[getid('R', i)].push_back({getid('L', i), {1, tot}});
			tot ++;
		}
		rep(j, m) {
			adj[getid('T', j)].push_back({getid('B', j), {2, tot}});
			adj[getid('B', j)].push_back({getid('T', j), {2, tot}});
			tot ++;
		}
	}

	bool vis[mxn], vise[mxn * 2];

	void dfs(int u, std::vector <int> &str, std::vector <int> &ids) {
		vis[u] = true;
		ids.push_back(u);
		rep(i, adj[u].size()) {
			int v = adj[u][i].first, c = adj[u][i].second.first, id = adj[u][i].second.second;
			if (!vise[id]) {
				str.push_back(c);
				vise[id] = true;
				if (!vis[v]) dfs(v, str, ids);
			}
		}
	}

	auto gethash() {
		// rep(u, (n + m) * 2) for (auto [v, c] : adj[u]) if (u < v) eprintf("%d %d %d\n", u, v, c);
		std::vector <std::pair <hashval, std::vector <int> > > gg;
		rep(i, (n + m) * 2) if (!vis[i]) {
			std::vector <int> str, ids;
			dfs(i, str, ids);
			// for (int z : ids) eprintf("%d ", z);
			// eprintf("\n");
			// for (int c : str) eprintf("%d ", c);
			// eprintf("\n");
			// assert(str.size() == ids.size());
			hashval hsh = min_repr(str, ids);
			gg.push_back({hsh, ids});
		}
		std::sort(gg.begin(), gg.end(), [&] (const auto &i, const auto &j) {
			// if (i.first == j.first) return i.second.size() < j.second.size();
			return i.first < j.first;
		});
		return gg;
	}
} G0, G1;

int main() {
	#ifdef DEBUG
	freopen("in", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	bool havelr = false, havetb = false;
	int cntlr = 0, cnttb = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	rep(i, n + m) {
		char s1[5], s2[5];
		int p1, p2;
		scanf("%s %s %d %d", s1, s2, &p1, &p2);
		-- p1, -- p2;
		int i1 = getid(s1[0], p1), i2 = getid(s2[0], p2);
		G0.adj[i1].push_back({i2, {getdir(s1[0], s2[0]), G0.tot}});
		G0.adj[i2].push_back({i1, {getdir(s2[0], s1[0]), G0.tot}});
		G0.tot ++;
		if (check(s1[0], s2[0], 'L', 'R')) havelr = true, ++ cntlr;
		if (check(s1[0], s2[0], 'T', 'B')) havetb = true, ++ cnttb;
		if (check(s1[0], s2[0], 'L', 'T')) {
			G1.adj[getid('L', cnt1)].push_back({getid('T', cnt1), {getdir('L', 'T'), G1.tot}});
			G1.adj[getid('T', cnt1)].push_back({getid('L', cnt1), {getdir('T', 'L'), G1.tot}});
			G1.tot ++;
			++ cnt1;
		}
		if (check(s1[0], s2[0], 'T', 'R')) {
			G1.adj[getid('T', m - 1 - cnt2)].push_back({getid('R', cnt2), {getdir('T', 'R'), G1.tot}});
			G1.adj[getid('R', cnt2)].push_back({getid('T', m - 1 - cnt2), {getdir('R', 'T'), G1.tot}});
			G1.tot ++;
			++ cnt2;
		}
		if (check(s1[0], s2[0], 'R', 'B')) {
			G1.adj[getid('R', n - 1 - cnt3)].push_back({getid('B', m - 1 - cnt3), {getdir('R', 'B'), G1.tot}});
			G1.adj[getid('B', m - 1 - cnt3)].push_back({getid('R', n - 1 - cnt3), {getdir('B', 'R'), G1.tot}});
			G1.tot ++;
			++ cnt3;
		}
		if (check(s1[0], s2[0], 'B', 'L')) {
			G1.adj[getid('B', cnt4)].push_back({getid('L', n - 1 - cnt4), {getdir('B', 'L'), G1.tot}});
			G1.adj[getid('L', n - 1 - cnt4)].push_back({getid('B', cnt4), {getdir('L', 'B'), G1.tot}});
			G1.tot ++;
			++ cnt4;
		}
	}
	for (int i = cnt1, j = cnt2; i < n - cnt4 && j < n - cnt3; ++ i, ++ j) {
		G1.adj[getid('L', i)].push_back({getid('R', j), {getdir('L', 'R'), G1.tot}});
		G1.adj[getid('R', j)].push_back({getid('L', i), {getdir('R', 'L'), G1.tot}});
		G1.tot ++;
	}
	for (int i = cnt1, j = cnt4; i < m - cnt2 && j < m - cnt3; ++ i, ++ j) {
		G1.adj[getid('T', i)].push_back({getid('B', j), {getdir('T', 'B'), G1.tot}});
		G1.adj[getid('B', j)].push_back({getid('T', i), {getdir('B', 'T'), G1.tot}});
		G1.tot ++;
	}
	if (havelr && havetb) {
		puts("No solution");
		return 0;
	}
	G0.build(); G1.build();
	auto qwq0 = G0.gethash();
	auto qwq1 = G1.gethash();
	if (qwq0.size() != qwq1.size()) {
		puts("No solution");
		return 0;
	}
	rep(i, qwq0.size()) {
		// std::cerr << qwq0[i].first << " " << qwq1[i].first << std::endl;
		if (!(qwq0[i].first == qwq1[i].first)) {
			puts("No solution");
			return 0;
		}
		if (!(qwq0[i].second.size() == qwq1[i].second.size())) {
			puts("No solution");
			return 0;
		}
	}
	static int ans[mxn];
	rep(i, qwq0.size()) {
		rep(j, qwq0[i].second.size()) {
			if (qwq0[i].second[j] < n + m) {
				ans[qwq1[i].second[j]] = qwq0[i].second[j];
			}
		}
	}
	rep(i, n) printf("%d ", ans[i] + 1);
	puts("");
	rep(i, m) printf("%d ", ans[i + n] + 1 - n);
	puts("");
	return 0;
}