#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int p = 0; cin >> p;
		bool f = false;
		for (int n = 3; n <= 360; n++) {
			if ((n * p) % 180 == 0) {
				int t = n - 2 - n * p / 180;
				if (0 <= t && t <= n - 3) {
					cout << n << '\n';
					f = true; break;
				}
			}
		}
		if (!f)
			cout << -1 << '\n';
	}
	return 0;
}