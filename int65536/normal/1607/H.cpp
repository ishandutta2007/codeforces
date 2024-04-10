#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	unordered_map<int, vector<pair<pair<int, int>, int>>> dishes;
	cin >> n;
	vector<int> x(n), y(n), w(n);
	for (int i = 0; i < n; ++i) {
		int a, b, m;
		cin >> a >> b >> m;
		int m2 = a + b - m;
		x[i] = a;
		y[i] = b;
		w[i] = m2;
		int s = max(0, m2 - b);
		int t = min(a, m2);
		dishes[m2].push_back({{s, t}, i});
	}
	int ret = 0;
	vector<int> target(n);
	for (auto& w : dishes) {
		auto& a = w.second;
		sort(a.begin(), a.end());
		int last = -1;
		vector<int> ids;
		auto up = [&]() {
			for (int id : ids) {
				target[id] = last;
			}
			ids.clear();
		};
		for (const auto& z : a) {
			if (z.first.first > last) {
				up();
				++ret;
				last = z.first.second;
			} else {
				last = min(last, z.first.second);
			}
			ids.push_back(z.second);
		}
		up();
	}
	printf("%d\n", ret);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", x[i] - target[i], y[i] - (w[i] - target[i]));
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("h.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		solve();
	}
	return 0;
}