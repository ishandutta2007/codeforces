#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int a[9], c[100009];
pair<int, int> p[600009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		for (int j = 0; j < 6; j++)
			p[i * 6 + j] = make_pair(b - a[j], i);
	}
	sort(p, p + n * 6);
	int pi = 0, tc = 0, ans = 2000000000;
	for (int i = 0; i < n * 6; i++) {
		if (!c[p[i].second]) tc++;
		c[p[i].second]++;
		while (pi < i && c[p[pi].second] > 1) {
			c[p[pi].second]--;
			pi++;
		}
		if (tc == n) ans = min(ans, p[i].first - p[pi].first);
	}
	cout << ans << '\n';
	return 0;
}