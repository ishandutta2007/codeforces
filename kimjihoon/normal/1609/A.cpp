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
		long long ans = 0, c = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			while (a % 2 == 0) {
				a /= 2;
				c++;
			}
			ans += a;
			mx = max(mx, 1LL * a);
		}
		cout << ans + ((1LL << c) - 1LL) * mx << '\n';
	}
	return 0;
}