#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	cout.setf(ios::fixed);
	cout.precision(15);
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		sort(a, a + n); reverse(a, a + n);
		double ans = 0;
		long long ps = 0;
		for (int i = 1; i <= n / 2; i++) {
			ps += a[i - 1];
			double t = (double)ps / i + (double)(s - ps) / (n - i);
			if (i == 1) ans = t;
			else ans = max(ans, t);
		}
		cout << ans << '\n';
	}
	return 0;
}