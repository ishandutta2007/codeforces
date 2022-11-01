#include <bits/stdc++.h>

const int N = 100005;

int n;
int a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}

	std::vector<std::pair<int, int>> seg;
	for (int i = 1; i <= n; ++i) {
		if (seg.empty() || seg.back().first != a[i]) {
			seg.emplace_back(a[i], 1);
		} else {
			++seg.back().second;
		}
	}

	int ans = 0;
	int lst = -1;
	for (int i = 0; i < (int)seg.size(); ++i) {
		if (seg[i].second >= 2) {
			ans += 2;
			if (lst == -1) {
				ans += i;
			} else if (seg[i].first != seg[lst].first) {
				ans += i - lst - 1;
			} else {
				bool flag = true;
				for (int j = lst + 2; j < i; j += 2) {
					flag &= seg[j].first == seg[i].first;
				}
				ans += i - lst - 1 - flag;
			}
			lst = i;
		}
	}

	std::cout << ans + (int)seg.size() - lst - 1 << "\n";
}