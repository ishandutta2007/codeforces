#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t[100009], x[100009], y[100009], d[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int r, n; cin >> r >> n;
	int pi = 0, mx = -1, ans = 0;
	t[0] = 0; x[0] = 1; y[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> x[i] >> y[i];
		while (t[i] - t[pi] >= 2 * r) {
			mx = max(mx, d[pi] + 1);
			pi++;
		}
		d[i] = mx;
		for (int j = pi; j < i; j++)
			if (d[j] != -1 && t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
				d[i] = max(d[i], d[j] + 1);
		ans = max(ans, d[i]);
	}
	cout << ans << '\n';
	return 0;
}