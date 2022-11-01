#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int r = 0;
	while (r + 3 < n) {
		for (int i = 0; i < m; ++i) {
			a[r][i] = 'X';
		}
		bool flag = true;
		for (int i = 0; i < m; ++i) {
			if (a[r + 1][i] == 'X' || a[r + 2][i] == 'X') {
				a[r + 1][i] = a[r + 2][i] = 'X';
				flag = false;
				break;
			}
		}
		if (flag) {
			a[r + 1][0] = a[r + 2][0] = 'X';
		}
		r += 3;
	}
	for (int i = 0; i < m; ++i) {
		a[r][i] = 'X';
	}
	for (int i = 0; i < m; ++i) {
		bool flag = false;
		for (int j = 1; j < n - r; ++j) {
			flag |= a[r + j][i] == 'X';
		}
		if (flag) {
			for (int j = 1; j < n - r; ++j) {
				a[r + j][i] = 'X';
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}