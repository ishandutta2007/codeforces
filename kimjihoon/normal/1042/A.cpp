#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a, a + n);
	int s = 0;
	for (int i = 0; i < n; i++)
		s += mx - a[i];
	if (m <= s)
		cout << mx << " ";
	else
		cout << mx + (m - s - 1) / n + 1 << " ";
	cout << a[n - 1] + m << '\n';
	return 0;
}