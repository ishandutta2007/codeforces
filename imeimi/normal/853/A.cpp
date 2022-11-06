#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long llong;

int n, k;

struct pp {
	int idx;
	int cost;
	bool operator<(const pp &x) const {
		if (cost == x.cost) return x.idx < idx;
		return x.cost < cost;
	}
};

set<int> s;
pp arr[300000];
int ret[300000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = k + 1; i <= k + n; ++i) {
		s.insert(i);
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].cost;
		arr[i].idx = i + 1;
	}
	llong ans = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		auto j = s.lower_bound(arr[i].idx);
		ans += (llong)(*j - arr[i].idx) * arr[i].cost;
		ret[arr[i].idx - 1] = *j;
		s.erase(j);
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; ++i) {
		printf("%d ", ret[i]);
	}
	return 0;
}