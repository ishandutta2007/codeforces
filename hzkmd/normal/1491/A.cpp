#include <bits/stdc++.h>

int n, q;
int a[100005];
int sum;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		sum += a[i];
	}

	while (q--) {
		int op, x;
		std::cin >> op >> x;
		if (op == 1) {
			sum -= a[x];
			a[x] ^= 1;
			sum += a[x];
		} else {
			std::cout << (x <= sum) << "\n";
		}
	}
}