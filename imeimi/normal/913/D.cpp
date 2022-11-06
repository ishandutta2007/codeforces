#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n, T;

struct times {
	int i, a, t;
	void scan(int idx) {
		i = idx;
		cin >> a >> t;
	}
	bool operator<(const times &x) const {
		return t < x.t;
	}
} ts[200000];

bool check(int x, bool pr = false) {
	vector<int> times;
	int tsum = 0;
	for (int i = 0; i < n; ++i) {
		if (times.size() == x) break;
		if (x <= ts[i].a) {
			times.push_back(i);
			tsum += ts[i].t;
		}
	}
	if (times.size() != x || T < tsum) return false;
	if (pr) {
		printf("%d\n", times.size());
		for (int i : times) {
			printf("%d ", ts[i].i + 1);
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> T;
	for (int i = 0; i < n; ++i) ts[i].scan(i);

	sort(ts, ts + n);
	int s = 0, e = n;
	while (s < e) {
		int m = (s + e + 1) / 2;
		if (check(m)) s = m;
		else e = m - 1;
	}
	printf("%d\n", s);
	check(s, true);

	return 0;
}