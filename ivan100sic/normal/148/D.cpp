#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld d[1005][1005][2];
bool s[1005][1005][2];

ld solve(int x, int y, int m) {
	ld& z = d[x][y][m];
	if (s[x][y][m])
		return z;

	s[x][y][m] = 1;

	if (m == 0) {
		if (x == 0 && y == 0)
			z = 0;
		else {
			// izvlaci belog misa
			z = (ld)x / (x+y);
			// izvlaci crnog misa
			if (y > 0)
				z += (ld)y / (x+y) * solve(x, y-1, 1);
		}
	} else {
		if (x+y <= 2)
			z = 0;
		else {
			z = 0;
			// izvlacim crnog misa pa iskace beli
			if (x >= 1 && y >= 1)
				z += (ld)y / (x+y) * (ld)x / (x+y-1) * solve(x-1, y-1, 0);
			// izvlacim crnog misa pa iskace crni
			if (y >= 2)
				z += (ld)y / (x+y) * (ld)(y-1) / (x+y-1) * solve(x, y-2, 0);
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	cout << setprecision(20) << fixed << solve(n, m, 0) << '\n';
}