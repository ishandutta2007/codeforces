#include <iostream>
#include <algorithm>
using namespace std;

int a[3509];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m, k; cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		k = min(k, m - 1);
		int ans = 0;
		for (int i = 1; i <= k + 1; i++) {
			int mn = 2000000000;
			for (int j = i; j + n - m <= i + n - k - 1; j++)
				mn = min(mn, max(a[j], a[j + n - m]));
			ans = max(ans, mn);
		}
		cout << ans << '\n';
	}
	return 0;
}