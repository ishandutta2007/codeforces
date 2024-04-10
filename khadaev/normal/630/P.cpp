#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, r;
	cin >> n >> r;
	ld x1 = (n - 1) * M_PI / n;
	ld x2 = 2 * M_PI / n;
	ld x3 = (n + 3) * M_PI / n;
	ld p1x = r, p1y = 0, q1x = r * cos(x1), q1y = r * sin(x1);
	ld p2x = r * cos(x2), p2y = r * sin(x2), q2x = r * cos(x3), q2y =
	r * sin(x3);
	ld a1 = p1y - q1y, b1 = q1x - p1x, c1 = - a1 * p1x - b1 * p1y;
	ld a2 = p2y - q2y, b2 = q2x - p2x, c2 = - a2 * p2x - b2 * p2y;
	ld x = - (c1 * b2 - c2 * b1) / (a1 * b2 - b1 * a2);
	ld y = - (a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2);
	ld dist = sqrt(x * x + y * y);
	//cout << x << ' ' << y << '\n';
	cout << fixed << setprecision(10) << dist * n * r * sin(M_PI / n)
	<< '\n';
}