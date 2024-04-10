#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[100009], b[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int na = 0, nb = 0;
		for (int i = 0; i < 2 * n; i++) {
			int x, y; cin >> x >> y;
			if (x == 0) {
				a[na] = 1LL * y * y; na++;
			}
			else {
				b[nb] = 1LL * x * x; nb++;
			}
		}
		sort(a, a + n); sort(b, b + n);
		double ans = 0;
		for (int i = 0; i < n; i++) 
			ans += sqrt(a[i] + b[i]);
		cout.setf(ios::fixed);
		cout.precision(20);
		cout << ans << '\n';
	}
	return 0;
}