#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], r[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i];
		sort(a, a + m);
		for (int i = 0; i < m; i++) {
			if (i + 1 < m) r[i] = a[i + 1] - a[i] - 1;
			else r[i] = n - a[i] + a[0] - 1;
		}
		sort(r, r + m); reverse(r, r + m);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int t = r[i] - i * 4;
			if (t > 0) ans += max(1, t - 1);
		}
		cout << n - ans << '\n';
	}
	return 0;
}