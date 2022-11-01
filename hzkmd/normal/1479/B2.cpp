#include <bits/stdc++.h>

const int N = 100005;

int n;
int a[N];
std::deque<int> p[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		p[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		p[a[i]].push_back(n + 1);
	}

	int x = 0, y = 0, ans = n;
	for (int i = 1; i <= n; ++i) {
		if (x == 0 || x == a[i] || (y && y != a[i] && p[x].front() >= p[y].front())) {
			ans -= (x == a[i]);
			x = a[i];
		} else {
			ans -= (y == a[i]);
			y = a[i];
		}
		p[a[i]].pop_front();
	}
	std::cout << ans << "\n";
}