#include <bits/stdc++.h>

int n, u, v;
int a[100005];

void solve() {
	std::cin >> n >> u >> v;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	int mx = 0;
	for (int i = 2; i <= n; ++i) {
		mx = std::max(mx, abs(a[i] - a[i - 1]));
	}
	if (mx == 0) {
		std::cout << std::min(u + v, 2 * v) << "\n";
	} else if (mx == 1) {
		std::cout << std::min(u, v) << "\n";
	} else {
		std::cout << 0 << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}