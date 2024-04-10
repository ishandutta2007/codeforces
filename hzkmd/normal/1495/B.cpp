#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	std::vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || i == n - 1 || (a[i - 1] < a[i]) != (a[i] < a[i + 1])) {
			pos.push_back(i);
		}
	}
	int mx = 0;
	for (int i = 1; i < (int)pos.size(); ++i) {
		mx = std::max(mx, pos[i] - pos[i - 1]);
	}
	int cnt = 0;
	for (int i = 1; i < (int)pos.size(); ++i) {
		if (mx == pos[i] - pos[i - 1]) {
			++cnt;
		}
	}
	if (cnt != 2 || mx & 1) {
		std::cout << 0 << "\n";
		return 0;
	}
	for (int i = 1; i < (int)pos.size() - 1; ++i) {
		if (a[pos[i]] > a[pos[i] - 1] && pos[i] - pos[i - 1] == mx && pos[i + 1] - pos[i] == mx) {
			std::cout << 1 << "\n";
			return 0;
		}
	}
	std::cout << 0 << "\n";
}