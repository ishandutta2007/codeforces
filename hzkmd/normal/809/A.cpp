#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	int ans = 0;
	int pw = 1;
	for (int i = 0; i < n; ++i) {
		ans = (ans + 1ll * pw * a[i]) % P;
		pw = 2 * pw % P;
	}
	pw = 1;
	for (int i = n - 1; i >= 0; --i) {
		ans = (ans + 1ll * pw * (P - a[i])) % P;
		pw = 2 * pw % P;
	}
	std::cout << ans << "\n";
}