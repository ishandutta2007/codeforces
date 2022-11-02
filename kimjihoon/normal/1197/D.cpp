#include <iostream>
#include <algorithm>
using namespace std;

int a[300009];
long long d[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		long long s = 0;
		for (int j = 1; j < m && i - j >= 0; j++) {
			s += a[i - j + 1];
			ans = max(ans, d[i - j] + s - k);
		}
		if (i - m < 0) d[i] = 0;
		else d[i] = max(0LL, d[i - m] + s + a[i - m + 1] - k);
		ans = max(ans, d[i]);
	}
	cout << ans << '\n';
	return 0;
}