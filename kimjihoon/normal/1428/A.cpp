#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int a = abs(x1 - x2), b = abs(y1 - y2);
		if (!a) cout << b << '\n';
		else if (!b) cout << a << '\n';
		else cout << a + b + 2 << '\n';
	}
	return 0;
}