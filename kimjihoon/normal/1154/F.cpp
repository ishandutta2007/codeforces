#include <iostream>
#include <algorithm>
using namespace std;

int a[200009], s[2009], p[2009], d[2009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if (x <= k)
			p[x] = max(p[x], y);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= k; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= k; i++) {
		d[i] = 2000000000;
		for (int j = 1; j <= i; j++)
			d[i] = min(d[i], d[i - j] + s[i] - s[i - j + p[j]]);
	}
	cout << d[k] << '\n';
	return 0;
}