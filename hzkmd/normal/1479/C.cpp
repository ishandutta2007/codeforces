#include <bits/stdc++.h>

int L, R, n;

struct Edge {
	int u, v, w;

	Edge() {}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

std::vector<Edge> ans;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> L >> R;
	n = 23;
	for (int i = n - 20; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans.push_back(Edge(i, j, 1 << std::max(0, n - j - 1)));
		}
	}
	int st;
	if (L == 1) {
		st = 1;
	} else {
		st = 2;
		ans.push_back(Edge(1, 2, L - 1));
	}
	ans.push_back(Edge(st, n, 1));
	R -= L;
	for (int i = 19; i >= 0; --i) {
		if (R >> i & 1) {
			R ^= 1 << i;
			ans.push_back(Edge(st, n - i - 1, R + 1));
		}
	}
	std::cout << "YES\n" << n << " " << ans.size() << "\n";
	for (auto e : ans) {
		std::cout << e.u << " " << e.v << " " << e.w << "\n";
	}
}