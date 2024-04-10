#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[400009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans += abs(a[i] - a[i - 1]);
		}
		a[n + 1] = 0; ans += a[n];
		for (int i = 1; i <= n; i++)
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
				ans -= a[i] - max(a[i - 1], a[i + 1]);
		cout << ans << '\n';
	}
	return 0;
}