#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;

pair<ld, int> a[200002];

inline ld dist(ld x, ld y) {
	return sqrtl(x * x + y * y);
}

inline ld cal(ld x1, ld y1, ld x2, ld y2, ld x, ld y, ld T) {
	ld rx = (x1 + x2) / 2 + (y1 - y2) * T;
	ld ry = (y1 + y2) / 2 + (x2 - x1) * T;
	return dist(rx - x1, ry - y1) - dist(rx - x, ry - y);
}

inline ld F(ld x1, ld y1, ld x2, ld y2, ld x, ld y, ld r) {
	ld L = -1e12, R = 1e12;
	int Lv = cal(x1, y1, x2, y2, x, y, L) > r;
	int Rv = cal(x1, y1, x2, y2, x, y, R) > r;
	for (int i = 0; i < 100; i++) {
		ld M = (L + R) / 2;
		int Mv = cal(x1, y1, x2, y2, x, y, M) > r;
		if (Lv == Mv) L = M;
		else R = M;
	}
	return L;
}


int main() {
	ld x1, y1, x2, y2;
	int i, j, n;
	scanf("%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		ld x, y, r;
		scanf("%Lf%Lf%Lf", &x, &y, &r);
		ld L = F(x1, y1, x2, y2, x, y, r), R = F(x1, y1, x2, y2, x, y, -r);
		if (L > R) {
			ld T = L;
			L = R;
			R = T;
		}
		a[i].first = L;
		a[i].second = 1;
		a[i + n].first = R;
		a[i + n].second = -1;
	}
	a[n + n].first = 0;
	a[n + n].second = 0;
	sort(a, a + n + n + 1);
	ld R = 1e12;
	for (i = j = 0; i <= n + n; i++) {
		if (!j && fabsl(a[i].first) < R) R = fabsl(a[i].first);
		j += a[i].second;
		if (!j && fabsl(a[i].first) < R) R = fabsl(a[i].first);
	}
	printf("%.12Lf\n", sqrtl(.25 + R * R) * dist(x1 - x2, y1 - y2));
	return 0;
}