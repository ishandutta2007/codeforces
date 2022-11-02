#include <iostream>
#include <algorithm>
using namespace std;

int p[1000009], d[1000009][3][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		p[a]++;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans += p[i] / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			d[2][i][j] = -1000000000;
	d[2][0][0] = 0;
	for (int i = 3; i <= m; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				d[i][j][k] = -1000000000;
				for (int t = 0; t < 3; t++)
					if (p[i] - j >= 0 && p[i - 1] - j - k >= 0 && p[i - 2] - j - k - t >= 0)
						d[i][j][k] = max(d[i][j][k], d[i - 1][k][t] + j + ((p[i] - j) / 3 + (p[i - 1] - j - k) / 3 + (p[i - 2] - j - k - t) / 3) - (p[i] / 3 + (p[i - 1] - k) / 3 + (p[i - 2] - k - t) / 3));
			}
	int mx = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mx = max(mx, d[m][i][j]);
	cout << ans + mx << '\n';
	return 0;
}