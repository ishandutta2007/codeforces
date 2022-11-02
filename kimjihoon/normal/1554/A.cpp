#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i) ans = max(ans, 1LL * a[i] * a[i - 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}