#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second;
	}
	std::sort(a.begin(), a.end());

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += a[i].second;
	}
	int mx = a[0].first + a[0].second;
	for (int i = 1; i < n; ++i) {
		ans += std::max(a[i].first - mx, 0);
		mx = std::max(mx, a[i].first + a[i].second);
	}
	std::cout << ans << "\n";
}