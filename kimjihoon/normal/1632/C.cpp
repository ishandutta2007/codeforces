#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int a, b; cin >> a >> b;
		if (a >= b) {
			cout << a - b << '\n';
			continue;
		}
		int t = b - a, ans = t;
		for (int i = b; i <= b + t; i++) {
			int pa = a, pb = i;
			for (int j = 22; j >= 0; j--) {
				int pt = (1 << j);
				if (!(pt & pb)) continue;
				if (pb - pt >= pa)
					pb -= pt;
			}
			ans = min(ans, (i - b) + (pb - a) + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}