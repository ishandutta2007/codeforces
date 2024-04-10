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
		int n, k; cin >> n >> k;
		bool f = true;
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			if (i >= 3 && a[i] - a[i - 1] < a[i - 1] - a[i - 2]) f = false;
		}
		if (!f) {
			cout << "NO" << '\n';
			continue;
		}
		if (k == 1) {
			cout << "YES" << '\n';
			continue;
		}
		if (1LL * a[1] - 1LL * (a[2] - a[1]) * (n - k) <= 1LL * (a[2] - a[1])) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}