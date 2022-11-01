#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m;
	std::vector<std::vector<long long>> e(n, std::vector<long long>(n, INF));
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		e[u][v] = e[v][u] = w;
	}
	std::vector<std::vector<long long>> dis(e);
	for (int i = 0; i < n; ++i) {
		dis[i][i] = 0;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	std::vector<std::vector<long long>> l(n, std::vector<long long>(n, 0));
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		l[u][v] = l[v][u] = w;
	}

	std::vector<std::vector<long long>> mx(n, std::vector<long long>(n, -INF));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				mx[i][j] = std::max(mx[i][j], l[i][k] - dis[j][k]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (e[i][j] < INF) {
				bool flag = false;
				for (int k = 0; k < n; ++k) {
					if (dis[k][i] + e[i][j] <= mx[k][j]) {
						flag = true;
						break;
					}
				}
				ans += flag;
			}
		}
	}
	std::cout << ans << "\n";
}