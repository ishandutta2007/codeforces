#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	long long ans = 1LL * n * (n + 1) / 2LL;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1]) 
			ans += 1LL * (i - 1) * (n - i + 1);
	}
	for (int i = 0; i < q; i++) {
		int p, x; cin >> p >> x;
		if (a[p] != a[p - 1]) ans -= 1LL * (p - 1) * (n - p + 1);
		if (p + 1 <= n && a[p + 1] != a[p]) ans -= 1LL * p * (n - p);
		a[p] = x;
		if (a[p] != a[p - 1]) ans += 1LL * (p - 1) * (n - p + 1);
		if (p + 1 <= n && a[p + 1] != a[p]) ans += 1LL * p * (n - p);
		cout << ans << '\n';
	}
	return 0;
}