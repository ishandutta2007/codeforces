#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, m; cin >> n >> k >> m;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n);
	double ans = 0;
	for (int i = 0; i < min(n, m + 1); i++) {
		long long ts = s + min(1LL * (n - i) * k, (long long)(m - i));
		ans = max(ans, (double)ts / double(n - i));
		s -= a[i];
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << '\n';
	return 0;
}