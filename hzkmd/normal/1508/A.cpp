#include <bits/stdc++.h>

void print(std::string a, std::string b, int v, int len) {
	std::string res;
	int i = 0, j = 0;
	while (i < (int)a.size() || j < (int)b.size()) {
		if (i == (int)a.size()) {
			res += b[j++];
		} else if (j == (int)b.size()) {
			res += a[i++];
		} else if (a[i] != '0' + v) {
			res += a[i++];
		} else if (b[j] != '0' + v) {
			res += b[j++];
		} else {
			res += '0' + v;
			++i, ++j;
		}
	}
	while ((int)res.size() < len) {
		res += '0';
	}
	std::cout << res << "\n";
}

void solve() {
	int n;
	std::cin >> n;
	std::string a[3];
	std::cin >> a[0] >> a[1] >> a[2];
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			for (int k = 0; k < 2; ++k) {
				int ci = 0, cj = 0;
				for (int l = 0; l < 2 * n; ++l) {
					ci += a[i][l] - '0' == k;
					cj += a[j][l] - '0' == k;
				}
				if (std::min(ci, cj) >= n) {
					print(a[i], a[j], k, 3 * n);
					return;
				}
			}
		}
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