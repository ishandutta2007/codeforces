#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, x; cin >> n >> x;
		bool f = false; int mx = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a == x) f = true;
			mx = max(mx, a);
		}
		if (f) {
			cout << 1 << '\n';
			continue;
		}
		cout << max(2, (x + mx - 1) / mx) << '\n';
	}
	return 0;
}