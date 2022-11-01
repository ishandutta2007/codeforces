#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
	int n;
	std::vector<long long> c;

public:
	BIT(int _n) : n(_n), c(n + 1, -INF) {}

	void add(int x, long long v) {
		for (++x; x; x ^= x & -x) {
			c[x] = std::max(c[x], v);
		}
	}

	long long query(int x) {
		long long s = -INF;
		for (++x; x <= n; x += x & -x) {
			s = std::max(s, c[x]);
		}
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	std::vector<int> l(n), r(n);
	std::vector<int> sta;
	for (int i = 0; i < n; ++i) {
		while (!sta.empty() && a[i] < a[sta.back()]) {
			sta.pop_back();
		}
		l[i] = sta.empty() ? -1 : sta.back();
		sta.push_back(i);
	}
	sta.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!sta.empty() && a[i] < a[sta.back()]) {
			sta.pop_back();
		}
		r[i] = sta.empty() ? n : sta.back();
		sta.push_back(i);
	}

	BIT T(n + 1);
	T.add(0, 0);
	long long ans = -INF;
	for (int i = 0; i < n; ++i) {
		long long f = T.query(l[i] + 1) + b[i];
		T.add(r[i], f);
		if (r[i] == n) {
			ans = std::max(ans, f);
		}
	}
	std::cout << ans << "\n";
}