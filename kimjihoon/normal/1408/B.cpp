#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && a[i] != a[i - 1]) c++;
		}
		if (k == 1) {
			if (c != 0) cout << -1 << '\n';
			else cout << 1 << '\n';
			continue;
		}
		if (c == 0) cout << 1 << '\n';
		else cout << (c - 1) / (k - 1) + 1 << '\n';
	}
	return 0;
}