#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];
long long s[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q, k; cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 2; i < n; i++) {
		s[i] = s[i - 1] + a[i + 1] - a[i - 1] - 2;
	}
	s[n] = s[n - 1];
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		if (l == r) {
			cout << k - 1 << '\n';
			continue;
		}
		long long ans = 0;
		if (l + 1 < r) ans += s[r - 1] - s[l];
		ans += a[l + 1] - 2;
		ans += k - a[r - 1] - 1;
		cout << ans << '\n';
	}
	return 0;
}