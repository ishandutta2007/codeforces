#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int a[2009], b[2009], c[2009], d[2009], mx[4000009];
pair<int, int> p[4000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			p[i * m + j] = make_pair(max(0, c[j] - a[i] + 1), max(0, d[j] - b[i] + 1));
	sort(p, p + n * m);
	for (int i = n * m - 1; i >= 0; i--)
		mx[i] = max(mx[i + 1], p[i].second);
	int ans = mx[0];
	for (int i = 0; i < n * m; i++) 
		if (i == n * m - 1 || p[i].first != p[i + 1].first)
			ans = min(ans, p[i].first + mx[i + 1]);
	cout << ans << '\n';
	return 0;
}