#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int l, r, d, u; cin >> l >> r >> d >> u;
		int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if ((x1 == x2 && l + r > 0) || (y1 == y2 && d + u > 0) || (x + r - l < x1 || x + r - l > x2) || (y + u - d < y1 || y + u - d > y2)) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}