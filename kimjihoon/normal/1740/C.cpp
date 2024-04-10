#include <iostream>
#include <algorithm>
using namespace std; 

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		int ans = 0;
		for (int i = 3; i <= n; i++)
			ans = max(ans, 2 * a[i] - a[i - 1] - a[1]);
		for (int i = n - 2; i >= 1; i--)
			ans = max(ans, -2 * a[i] + a[i + 1] + a[n]);
		cout << ans << '\n';
	}
	return 0;
}