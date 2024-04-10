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
		long long ans = 0;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			ans += 2LL * min(a, b);
			mx = max(mx, max(a, b));
		}
		ans += 2LL * mx;
		cout << ans << '\n';
	}
	return 0;
}