#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
	int& x5, int& y5, int& x6, int& y6)
{
	x5 = max(x1, x3);
	x6 = min(x2, x4);

	y5 = max(y1, y3);
	y6 = min(y2, y4);
}

ll area(int x1, int y1, int x2, int y2) {
	ll z = 1;
	z *= max(0, x2 - x1);
	z *= max(0, y2 - y1);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

	int x7, y7, x8, y8;
	int x9, y9, x10, y10;
	int x11, y11, x12, y12;
	intersect(x1, y1, x2, y2, x3, y3, x4, y4, x7, y7, x8, y8);
	intersect(x1, y1, x2, y2, x5, y5, x6, y6, x9, y9, x10, y10);

	intersect(x7, y7, x8, y8, x9, y9, x10, y10, x11, y11, x12, y12);

	ll a = area(x7, y7, x8, y8) + area(x9, y9, x10, y10) - area(x11, y11, x12, y12);

	cout << ((a == area(x1, y1, x2, y2)) ? "NO\n" : "YES\n");
}