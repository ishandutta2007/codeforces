#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1234567;

struct rect {
	int x, y;
	i64 a;
} rec[maxN];
int n, h, t;
i64 dp[maxN], answer, xh[maxN], yh[maxN];

void add(i64 x, i64 y) {
	while (h + 2 <= t) {
		i64 px = xh[t - 1] - xh[t - 2], py = yh[t - 1] - yh[t - 2];
		i64 qx = x - xh[t - 2], qy = y - yh[t - 2];
		bool p = 0;
		if (qy / qx != py / px) {
			p = qy / qx > py / px;
		} else {
			qy %= qx; py %= px;
			p = qy * px > py * qx;
		}
		if (p) {
			--t;
		} else {
			break;
		}
	}
	xh[t] = x;
	yh[t] = y;
	++t;
}
i64 query(i64 y) {
	while (h + 1 < t && yh[h] - y * xh[h] < yh[h + 1] - y * xh[h + 1]) ++h;
	return yh[h] - y * xh[h];
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%lld", &rec[i].x, &rec[i].y, &rec[i].a);
	}
	sort(rec, rec + n, [&](const rect & a, const rect & b) {
		return a.x < b.x;
	});
	add(0, 0);
	for (int i = 0; i < n; i++) {
		i64 x = rec[i].x, y = rec[i].y, a = rec[i].a;
		dp[i] = query(y) + x * y - a;
		answer = max(answer, dp[i]);
		add(x, dp[i]);
	}
	printf("%lld\n", answer);
}