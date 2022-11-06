#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
typedef long long llong;

int n, n1, n2, w, h;
struct dance {
	int idx, p, t;
	bool operator<(const dance &x) const {
		if (p - t == x.p - x.t) return p < x.p;
		return t - p < x.t - x.p;
	}
} lefts[100000];

deque<int> q[200001];

struct pi {
	int idx, p, t;
	bool operator<(const pi &x) const {
		if (p == x.p) return t < x.t;
		return p < x.p;
	}
};

pi down[100000];
pair<int, int> point[100000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, k;
	cin >> n >> w >> h;
	while (n1 + n2 < n) {
		cin >> i >> j >> k;
		if (i == 1) {
			lefts[n1] = { n1 + n2, j, k };
			n1 += 1;
		}
		else {
			down[n2] = { n1 + n2, j, k };
			n2 += 1;
		}
	}
	sort(lefts, lefts + n1);
	sort(down, down + n2);
	for (i = 0; i < n1; ++i) {
		q[lefts[i].t - lefts[i].p + 100000].push_back(lefts[i].idx);
	}
	
	for (i = 0; i < n2; ++i) {
		int xx = down[i].t - down[i].p + 100000;
		if (q[xx].empty()) continue;
		int idx = down[i].idx;
		down[i].idx = q[xx].back();
		q[xx].pop_back();
		q[xx].push_front(idx);
	}

	for (i = 0; i < n1; ++i) {
		point[q[lefts[i].t - lefts[i].p + 100000].front()]
			= { lefts[i].p, h };
		q[lefts[i].t - lefts[i].p + 100000].pop_front();
	}
	for (i = 0; i < n2; ++i) {
		point[down[i].idx] = { w, down[i].p };
	}
	for (i = 0; i < n; ++i) {
		printf("%d %d\n", point[i].first, point[i].second);
	}
	return 0;
}