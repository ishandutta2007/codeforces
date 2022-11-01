#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m)), b(a);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> b[i][j];
		}
	}
	if (a == b) {
		std::cout << 0 << "\n";
		return 0;
	}
	
	std::vector<int> deg(m);
	std::vector<std::vector<int>> e(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (b[i][j] > b[i + 1][j]) {
				++deg[j];
				e[i].push_back(j);
			}
		}
	}
	
	std::vector<bool> vis(n);
	vis[n - 1] = true;
	std::vector<int> Q;
	for (int i = 0; i < m; ++i) {
		if (!deg[i]) {
			Q.push_back(i);
		}
	}
	for (int k = 0; k < (int)Q.size(); ++k) {
		int c = Q[k];
		for (int i = 0; i < n - 1; ++i) {
			if (!vis[i] && b[i][c] < b[i + 1][c]) {
				vis[i] = true;
				for (int j : e[i]) {
					--deg[j];
					if (!deg[j]) {
						Q.push_back(j);
					}
				}
			}
		}
	}

	std::reverse(Q.begin(), Q.end());

	std::vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = i;
	}
	for (int c : Q) {
		std::stable_sort(id.begin(), id.end(), [&](int x, int y) {
			return a[x][c] < a[y][c];
		});
	}
	for (int i = 0; i < n; ++i) {
		if (a[id[i]] != b[i]) {
			std::cout << -1 << "\n";
			return 0;
		}
	}
	std::cout << Q.size() << "\n";
	for (int c : Q) {
		std::cout << c + 1 << " ";
	}
	std::cout << "\n";
}