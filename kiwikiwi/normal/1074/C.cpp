#include <bits/stdc++.h>
using namespace std;

const int maxN = 323456;

int n, ans;
int ord[maxN], x[maxN], y[maxN], q[maxN], bit[maxN];
pair<int, int> p[maxN];
void solve() {
	vector<int> vecY;
	for (int i = 0; i < n; i++) {
		vecY.push_back(y[i]);
		ord[i] = i;
	}
	sort(vecY.begin(), vecY.end());
	vecY.erase(unique(vecY.begin(), vecY.end()), vecY.end());
	int m = vecY.size();
	for (int i = 0; i < n; i++) {
		p[i] = make_pair(x[i], y[i]);
		q[i] = lower_bound(vecY.begin(), vecY.end(), y[i]) - vecY.begin() + 1;
	}
	sort(ord, ord + n, [&](int a, int b) {
		return p[a] < p[b];
	});
	int minY = 2e9;
	for (int i = 1; i <= m; i++) {
		bit[i] = 2e9;
	}
	auto query = [&] (int x) {
		int r = 2e9;
		for (; x; x -= x & -x)
			r = min(r, bit[x]);
		return r;
	};

	auto modify = [&] (int x, int r) {
		for (; x <= m; x += x & -x)
			bit[x] = min(bit[x], r);
	};

	for (int i = 0; i < n; i++) {
		int index = ord[i];
		int x = p[index].first, y = p[index].second, pos = q[index];
		minY = min(minY, y);
		modify(pos, x);
		ans = max(ans, 2 * (x - query(pos)) + 2 * (y - minY));

	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	int minX = 1e9, minY = 1e9, maxX = -1e9, maxY = -1e9;
	for (int i = 0; i < n; i++) {
		minX = min(minX, x[i]);
		minY = min(minY, y[i]);
		maxX = max(maxX, x[i]);
		maxY = max(maxY, y[i]);
	}
	int ans4 = 2 * (maxX + maxY - minX - minY);

	solve();
	for (int i = 0; i < n; i++) {
		y[i] = -y[i];
	}
	solve();
	for (int i = 0; i < n; i++) {
		y[i] = -y[i];
		x[i] = -x[i];
	}
	solve();
	for (int i = 0; i < n; i++) {
		y[i] = -y[i];
	}
	solve();
	printf("%d", ans);
	for (int i = 4; i <= n; i++) {
		printf(" %d", ans4);
	}
	printf("\n");
}