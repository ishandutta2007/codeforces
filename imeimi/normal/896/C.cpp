#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long llong;

int n, m, seed, vmax;

int rnd() {
	const int mod = 1e9 + 7;
	int ret = seed;
	seed = (seed * 7ll + 13ll) % mod;
	return ret;
}

struct interval {
	int s, e;
	interval(int s) : s(s) {}
	interval(int s, int e) : s(s), e(e) {}
	bool operator<(const interval &x) const {
		return s < x.s;
	}
	int size() const {
		return e - s;
	}
};

map<interval, llong> arr;
void split(int x) {
	if (x > n) return;
	auto it = --arr.upper_bound(x);
	interval iv = it->first;
	llong val = it->second;
	if (iv.s == x) return;
	arr.erase(it);
	arr[interval(iv.s, x)] = val;
	arr[interval(x, iv.e)] = val;
}

void init() {
	for (int i = 1; i <= n; ++i) arr[interval(i, i + 1)] = rnd() % vmax + 1;
}

int pow(int x, int p, int m) {
	if (p == 0) return 1;
	if (p == 1) return x % m;
	int ret = pow(x, p >> 1, m);
	ret = (llong)ret * ret % m;
	if (p & 1) ret = (llong)ret * x % m;
	return ret;
}

void query() {
	int op = rnd() % 4;
	int l = rnd() % n + 1;
	int r = rnd() % n + 1;
	if (l > r) swap(l, r);

	int x = rnd() % ((op == 2) ? r - l + 1 : vmax) + 1;
	split(l);
	split(r + 1);
	auto it = arr.find(interval(l));
	if (op == 0) {
		for (; it != arr.end() && it->first.s <= r; ++it) it->second += x;
	}
	else if (op == 1) {
		auto it2 = arr.find(interval(r + 1));
		arr.erase(it, it2);
		arr[interval(l, r + 1)] = x;
	}
	else if (op == 2) {
		vector<pair<llong, int>> vt;
		for (; it != arr.end() && it->first.s <= r; ++it)
			vt.emplace_back(it->second, it->first.size());
		sort(vt.begin(), vt.end());
		for (auto i : vt) {
			x -= i.second;
			if (x <= 0) {
				printf("%lld\n", i.first);
				break;
			}
		}
	}
	else {
		int y = rnd() % vmax + 1;
		int ans = 0;
		for (; it != arr.end() && it->first.s <= r; ++it) {
			int val = pow(it->second % y, x, y);
			ans = ((llong)it->first.size() * val + ans) % y;
		}
		printf("%d\n", ans);
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	init();
	while (m--) query();
	return 0;
}