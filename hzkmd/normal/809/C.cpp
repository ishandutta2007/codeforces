#include <bits/stdc++.h>

const int P = 1000000007;

int solve(int x, int y, int z) {
	std::vector<std::pair<int, int>> f(8);
	f[7] = std::make_pair(0, 1);
	for (int l = 30; l >= 0; --l) {
		std::vector<std::pair<int, int>> g(8);
		int xl = x >> l & 1, yl = y >> l & 1, zl = z >> l & 1;
		for (int S = 0; S < 8; ++S) {
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					int k = i ^ j;
					if (S & 1 && i > xl) {
						continue;
					}
					if (S & 2 && j > yl) {
						continue;
					}
					if (S & 4 && k > zl) {
						continue;
					}
					int T = S & ((i == xl) | (j == yl) << 1 | (k == zl) << 2);
					g[T].second = (g[T].second + f[S].second) % P;
					g[T].first = (g[T].first + f[S].first + 1ll * (k << l) * f[S].second) % P;
				}
			}
		}
		f.swap(g);
	}
	return (f[0].first + f[0].second) % P;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		int sx, sy, tx, ty, v;
		std::cin >> sx >> sy >> tx >> ty >> v;
		--sx, --sy;
		int ans = (solve(tx, ty, v) - solve(sx, ty, v) - solve(tx, sy, v) + solve(sx, sy, v)) % P;
		std::cout << (ans + P) % P << "\n";
	}
}