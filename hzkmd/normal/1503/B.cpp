#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> p0, p1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) & 1) {
				p1.emplace_back(i, j);
			} else {
				p0.emplace_back(i, j);
			}
		}
	}
	auto i0 = p0.begin(), i1 = p1.begin();
	while (i0 != p0.end() || i1 != p1.end()) {
		int a;
		std::cin >> a;
		if ((i0 != p0.end() && a != 1) || i1 == p1.end()) {
			std::cout << (a != 1 ? 1 : 2) << " " << i0->first + 1 << " " << i0->second + 1 << std::endl;
			++i0;
		} else {
			std::cout << (a == 1 ? 3 : a ^ 1) << " " << i1->first + 1 << " " << i1->second + 1 << std::endl;
			++i1;
		}
	}
}