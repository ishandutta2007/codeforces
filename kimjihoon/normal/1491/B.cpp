#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, u, v; cin >> n >> u >> v;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0) mx = max(mx, abs(a[i] - a[i - 1]));
		}
		if (mx >= 2) cout << 0 << '\n';
		else if (mx == 1) cout << min(u, v) << '\n';
		else cout << min(2 * v, u + v) << '\n';
	}
	return 0;
}