#include <bits/stdc++.h>

template<int a, int b, int c>
class __xorshift64 {
	unsigned long long seed;

public:
	__xorshift64() : seed(0x9134f5a57ad2d42bull) {}
	__xorshift64(unsigned long long _seed) : seed(_seed) {}

	unsigned long long operator()() {
		seed ^= seed << a;
		seed ^= seed >> b;
		seed ^= seed << c;
		return seed + 0x4a35b29ef0189b15ull;
	}
};

typedef __xorshift64<13, 7, 17> xorshift64;

xorshift64 rnd(time(0));

const int N = 300000;

class Treap {
	int cnt, rt, ls[N], rs[N];
	int val[N];
	unsigned key[N];
	int sz[N];
	
	int tag[N];

	int new_node(int v) {
		int u = cnt++;
		ls[u] = rs[u] = -1;
		val[u] = v;
		key[u] = rnd();
		sz[u] = 1;
		tag[u] = 0;
		return u;
	}

	void up(int u) {
		sz[u] = 1;
		if (ls[u] != -1) {
			sz[u] += sz[ls[u]];
		}
		if (rs[u] != -1) {
			sz[u] += sz[rs[u]];
		}
	}

	void add(int u, int v) {
		tag[u] += v;
		val[u] += v;
	}

	void down(int u) {
		if (tag[u]) {
			if (ls[u] != -1) {
				add(ls[u], tag[u]);
			}
			if (rs[u] != -1) {
				add(rs[u], tag[u]);
			}
			tag[u] = 0;
		}
	}

	void split_sz(int u, int k, int &x, int &y) {
		if (u == -1) {
			x = y = -1;
			return;
		}
		down(u);
		if (k <= sz[ls[u]]) {
			split_sz(ls[u], k, x, ls[u]);
			y = u;
		} else {
			split_sz(rs[u], k - sz[ls[u]] - 1, rs[u], y);
			x = u;
		}
		up(u);
	}

	void split_v(int u, int v, int &x, int &y) {
		if (u == -1) {
			x = y = -1;
			return;
		}
		down(u);
		if (v <= val[u]) {
			split_v(ls[u], v, x, ls[u]);
			y = u;
		} else {
			split_v(rs[u], v, rs[u], y);
			x = u;
		}
		up(u);
	}

	int merge(int u, int v) {
		if (u == -1 || v == -1) {
			return u == -1 ? v : u;
		}
		down(u), down(v);
		if (key[u] < key[v]) {
			rs[u] = merge(rs[u], v);
			up(u);
			return u;
		} else {
			ls[v] = merge(u, ls[v]);
			up(v);
			return v;
		}
	}

public:
	Treap() : cnt(0), rt(-1) {}

	void work(int l, int r) {
		int a, b, c, d;
		split_v(rt, l, a, b);
		split_v(b, r, b, c);
		split_sz(c, 1, c, d);
		add(b, 1);
		rt = merge(merge(merge(a, new_node(l)), b), d);
	}

	int getans() {
		return rt == -1 ? 0 : sz[rt];
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r;
		std::cin >> l >> r;
		T.work(l, r);
	}
	std::cout << T.getans() << "\n";
}