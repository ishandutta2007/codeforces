#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int t0 = (n & (1 << i)), t1 = (m & (1 << i));
			if (t0 && !t1) break;
			if (!t0 && t1)
				ans += (1 << i);
		}
		if ((ans ^ n) == m) {
			for (int i = 0; i <= 30; i++) {
				if (!(m & (1 << i))) {
					ans += (1 << i);
					break;
				}
				if (ans & (1 << i))
					ans -= (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}