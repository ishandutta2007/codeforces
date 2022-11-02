#include <iostream>
#include <algorithm>
using namespace std;

int a[200009], b[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, ta, tb, k; cin >> n >> m >> ta >> tb >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	if (n <= k || m <= k) {
		cout << -1 << '\n';
		return 0;
	}
	int bi = 0, ans = 0;
	for (int i = 0; i < k + 1; i++) {
		while (bi < m && b[bi] < a[i] + ta) bi++;
		if (bi + k - i >= m) {
			cout << -1 << '\n';
			return 0;
		}
		ans = max(ans, b[bi + k - i] + tb);
	}
	cout << ans << '\n';
	return 0;
}