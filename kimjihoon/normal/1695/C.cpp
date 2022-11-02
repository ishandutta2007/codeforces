#include <iostream>
#include <algorithm>
using namespace std;

int a[1009][1009], d[1009][1009][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		if ((n + m - 1) & 1) {
			cout << "NO" << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) {
					d[i][j][0] = d[i][j][1] = 0;
				}
				else if (i == 1) {
					d[i][j][0] = d[i][j - 1][0];
					d[i][j][1] = d[i][j - 1][1];
				}
				else if (j == 1) {
					d[i][j][0] = d[i - 1][j][0];
					d[i][j][1] = d[i - 1][j][1];
				}
				else {
					d[i][j][0] = min(d[i - 1][j][0], d[i][j - 1][0]);
					d[i][j][1] = max(d[i - 1][j][1], d[i][j - 1][1]);
				}
				d[i][j][0] += a[i][j]; d[i][j][1] += a[i][j];
			}
		if (1LL * d[n][m][0] * d[n][m][1] > 0LL) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}