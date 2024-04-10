#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, L;
	std::cin >> n >> m >> L;
	std::vector<std::vector<std::pair<int, int>>> E(n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int v;
			std::cin >> v;
			E[i * m + j].emplace_back(i * m + j + 1, v);
			E[i * m + j + 1].emplace_back(i * m + j, v);
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			int v;
			std::cin >> v;
			E[i * m + j].emplace_back((i + 1) * m + j, v);
			E[(i + 1) * m + j].emplace_back(i * m + j, v);
		}
	}
	if (L & 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << -1 << " ";
			}
			std::cout << "\n";
		}
		return 0;
	}
	std::vector<int> f(n * m);
	for (int k = 0; k < L / 2; ++k) {
		std::vector<int> g(n * m);
		for (int u = 0; u < n * m; ++u) {
			g[u] = INF;
			for (auto p : E[u]) {
				int v = p.first, w = p.second;
				g[u] = std::min(g[u], f[v] + 2 * w);
			}
		}
		f.swap(g);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << f[i * m + j] << " ";
		}
		std::cout << "\n";
	}
}