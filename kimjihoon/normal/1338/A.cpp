#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int mx = -1000000009, p = mx;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			p = max(p, mx - a);
			mx = max(mx, a);
		}
		int ans = 0;
		while (p > 0) {
			p /= 2;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}