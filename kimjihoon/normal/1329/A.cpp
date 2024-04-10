#include <iostream>
#include <algorithm>
using namespace std;

int r[100009], ans[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> r[i];
	for (int i = 1; i <= m; i++) {
		if (i + r[i] - 1 > n) {
			cout << -1 << '\n';
			return 0;
		}
		ans[i] = i;
	}
	int c = m;
	ans[m + 1] = n + 1;
	while (1 <= c && ans[c] + r[c] < ans[c + 1]) {
		ans[c] += ans[c + 1] - (ans[c] + r[c]);
		c--;
	}
	if (c <= 0) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}