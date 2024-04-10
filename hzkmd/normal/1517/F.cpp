#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	int ans = n;
	for (int r = 0; r <= n; ++r) {
		std::vector<std::vector<int>> f(n, std::vector<int>(1));
		std::vector<std::vector<int>> g(n, std::vector<int>(1));
		std::vector<int> h(n);

		std::function<void(int, int)> dfs = [&](int u, int fa) {
			h[u] = 0;
			f[u][0] = g[u][0] = (P + 1) / 2;
			for (int v : E[u]) {
				if (v != fa) {
					dfs(v, u);
					std::vector<int> tf(std::max(h[u], h[v] + 1) + 1);
					std::vector<int> tg(std::max(h[u], h[v] + 1) + 1);
					for (int i = 0; i <= h[u]; ++i) {
						for (int j = 0; j <= h[v]; ++j) {
							tf[std::min(i, j + 1)] = (tf[std::min(i, j + 1)] + 1ll * f[u][i] * f[v][j]) % P;
							tg[std::max(i, j + 1)] = (tg[std::max(i, j + 1)] + 1ll * g[u][i] * g[v][j]) % P;
							if (i + j + 1 <= r) {
								tf[i] = (tf[i] + 1ll * f[u][i] * g[v][j]) % P;
								tf[j + 1] = (tf[j + 1] + 1ll * g[u][i] * f[v][j]) % P;
							} else {
								tg[i] = (tg[i] + 1ll * g[u][i] * f[v][j]) % P;
								tg[j + 1] = (tg[j + 1] + 1ll * f[u][i] * g[v][j]) % P;
							}
						}
					}
					h[u] = std::max(h[u], h[v] + 1);
					f[u].swap(tf);
					g[u].swap(tg);
				}
			}
		};

		dfs(0, -1);
		int sum = std::accumulate(f[0].begin(), f[0].end(), 0, [](int a, int b) {
			return (a + b) % P;
		});
		ans = (ans + P - sum) % P;
	}
	std::cout << ans << "\n";
}