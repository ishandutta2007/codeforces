#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}
	std::vector<std::vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(i + 1);
	}
	for (int k = 0; k < n; ++k) {
		for (int i = k; i < n; ++i) {
			a[i][i - k] = p[i - k];
		}
		p.erase(std::find(p.begin(), p.end(), k + 1));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}