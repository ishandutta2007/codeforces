#include <iostream>
#include <algorithm>
using namespace std;

int a[300009], c[2][2000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int m = 0;
	c[0][0]++;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] = (a[i] ^ a[i - 1]);
		c[i % 2][a[i]]++;
		m = max(m, a[i]);
	}
	long long ans = 0;
	for (int i = 0; i <= m; i++) 
		ans += 1LL * c[0][i] * (c[0][i] - 1) / 2LL + 1LL * c[1][i] * (c[1][i] - 1) / 2LL;
	cout << ans << '\n';
	return 0;
}