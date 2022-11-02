#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, x; cin >> n >> x;
		int mn = 0, mx = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (mn == 0) {
				mn = mx = a;
			}
			else {
				mn = min(mn, a);
				mx = max(mx, a);
			}
			if (mx - mn > 2 * x) {
				mn = mx = a;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}