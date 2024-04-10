#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += s[i] - '0';
	}
	if (cnt & 1 || s[0] != '1' || s[n - 1] != '1') {
		std::cout << "NO\n";
		return;
	}
	int now1 = 0;
	int now0 = 0;
	std::string a, b;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			++now1;
			if (now1 <= cnt / 2) {
				a += "(", b += "(";
			} else {
				a += ")", b += ")";
			}
		} else {
			++now0;
			if (now0 & 1) {
				a += "(", b += ")";
			} else {
				a += ")", b += "(";
			}
		}
	}
	std::cout << "YES\n";
	std::cout << a << "\n";
	std::cout << b << "\n";
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