#include <bits/stdc++.h>

struct Edge {
	int u, v, w;

	bool operator<(const Edge &rhs) const {
		return w < rhs.w;
	}
};

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}

	int count() {
		int cnt = 0;
		for (int i = 0; i < (int)fa.size(); ++i) {
			if (find(i) == i) {
				++cnt;
			}
		}
		return cnt;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> E(n);
	std::vector<Edge> edge(m);
	int xor_sum = 0;
	for (int i = 0; i < m; ++i) {
		std::cin >> edge[i].u >> edge[i].v >> edge[i].w;
		--edge[i].u, --edge[i].v;
		xor_sum ^= edge[i].w;
		E[edge[i].u].push_back(edge[i].v);
		E[edge[i].v].push_back(edge[i].u);
	}
	std::sort(edge.begin(), edge.end());

	DSU D(n);

	auto join = [&](int u) {
		int p = 0;
		for (int i = 0; i < n; ++i) {
			while (p < (int)E[u].size() && E[u][p] < i) {
				++p;
			}
			if (p < (int)E[u].size() && E[u][p] == i) {
				continue;
			}
			D.merge(u, i);
		}
	};

	int id = -1;
	for (int i = 0; i < n; ++i) {
		std::sort(E[i].begin(), E[i].end());
		if (id == -1 || E[i].size() < E[id].size()) {
			id = i;
		}
	}
	join(id);
	for (int v : E[id]) {
		join(v);
	}

	bool forest = D.count() == n - (1ll * n * (n - 1) / 2 - m);

	DSU T(n);
	long long ans = 0;
	for (auto e : edge) {
		if (D.merge(e.u, e.v)) {
			ans += e.w;
			T.merge(e.u, e.v);
		}
	}
	if (forest) {
		for (auto e : edge) {
			if (T.merge(e.u, e.v)) {
				ans += std::min(e.w, xor_sum);
				break;
			}
		}
	}
	std::cout << ans << "\n";
}