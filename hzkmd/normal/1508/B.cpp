#include <bits/stdc++.h>

bool solve(int n, long long k, int v, std::vector<int> &res) {
	for (int i = 1; i < n; ++i) {
		long long s = (n - i - 1) >= 60 ? k : 1ll << (n - i - 1);
		if (k <= s) {
			for (int j = i - 1; j >= 0; --j) {
				res.push_back(v + j);
			}
			return solve(n - i, k, v + i, res);
		} else {
			k -= s;
		}
	}
	if (k == 1) {
		for (int i = n - 1; i >= 0; --i) {
			res.push_back(v + i);
		}
		return true;
	}
	return false;
}

void solve() {
	int n;
	long long k;
	std::cin >> n >> k;
	std::vector<int> ans;
	if (!solve(n, k, 0, ans)) {
		std::cout << -1 << "\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] + 1 << " \n"[i == n - 1];
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