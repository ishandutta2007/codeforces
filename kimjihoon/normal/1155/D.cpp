#include <iostream>
#include <algorithm>
using namespace std;

long long a[300009], s[300009], l[300009], r[300009], pl[300009], pr[3000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; long long x; cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) 
		l[i] = max(l[i - 1] + a[i], 0LL);
	for (int i = n; i >= 1; i--)
		r[i] = max(r[i + 1] + a[i], 0LL);
	for (int i = 0; i <= n; i++) {
		pl[i] = l[i] - s[i] * x;
		pr[i] = r[i + 1] + s[i] * x;
	}
	long long ans = 0, mx = pl[0];
	for (int i = 0; i <= n; i++) {
		mx = max(mx, pl[i]);
		ans = max(ans, mx + pr[i]);
	}
	cout << ans << '\n';
	return 0;
}