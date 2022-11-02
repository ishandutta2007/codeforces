#include <iostream>
#include <cmath>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0 && abs(a[i] - a[i - 1]) > 1) ans = i;
		}
		if (ans == -1) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			cout << ans << " " << ans + 1 << '\n';
		}
	}
	return 0;
}