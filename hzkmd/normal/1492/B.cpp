#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		int mx = 0;
		std::vector<bool> ok(n);
		for (int i = 0; i < n; ++i) {
			if (a[i] > mx) {
				ok[i] = true;
				mx = a[i];
			}
		}
		int lst = n;
		for (int i = n - 1; ~i; --i) {
			if (ok[i]) {
				for (int j = i; j < lst; ++j) {
					std::cout << a[j] << " ";
				}
				lst = i;
			}
		}
		std::cout << "\n";
	}
}