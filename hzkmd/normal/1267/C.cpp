#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> d(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> d[i].first;
		d[i].second = i;
	}

	std::vector<std::pair<int, int>> E;
	while (1) {
		int n = d.size();
		if (!n) {
			break;
		}
		std::sort(d.begin(), d.end());
		if (n == 1 || d[0].first >= 3) {
			std::cout << -1 << "\n";
			return 0;
		}
		if (d[0].first == 1) {
			if (d[n - 1].first == 1) {
				if (n > 2) {
					std::cout << -1 << "\n";
					return 0;
				}
				E.emplace_back(d[0].second, d[1].second);
				d.clear();
			} else {
				int p = n - 1;
				for (int i = n - 1; i > 0; --i) {
					if (d[i].first & 1 && d[i].first > 1) {
						p = i;
						break;
					}
				}
				E.emplace_back(d[0].second, d[p].second);
				--d[p].first;
				d.erase(d.begin());
			}
		} else {
			if (d[n - 1].first == 2) {
				if (n == 2) {
					std::cout << -1 << "\n";
					return 0;
				}
				for (int i = 0; i < n; ++i) {
					E.emplace_back(d[i].second, d[(i + 1) % n].second);
				}
				d.clear();
			} else {
				if (d[1].first > 2) {
					std::cout << -1 << "\n";
					return 0;
				}
				E.emplace_back(d[0].second, d[1].second);
				E.emplace_back(d[n - 1].second, d[0].second);
				E.emplace_back(d[n - 1].second, d[1].second);
				d[n - 1].first -= 2;
				d.erase(d.begin(), d.begin() + 2);
			}
		}
	}
	std::cout << E.size() << "\n";
	for (auto e : E) {
		std::cout << 2 << " " << e.first + 1 << " " << e.second + 1 << "\n";
	}
}