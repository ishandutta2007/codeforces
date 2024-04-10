#include <iostream>
#include <algorithm>
using namespace std;

int d[409][409][409][3];
long long md = 998244353, s[409][409];
int c[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int p = n / 2 + 1;
	d[1][0][0][0] = 24;
	d[1][1][0][1] = 1;
	d[1][0][1][2] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++) {
				if (i != p) {
					d[i][j][k][0] = (1LL * d[i - 1][j][k][1] * 24 + 1LL * d[i - 1][j][k][2] * 24 + 1LL * d[i - 1][j][k][0] * 23) % md;
					if (j > 0) d[i][j][k][1] = (1LL * d[i - 1][j - 1][k][2] + 1LL * d[i - 1][j - 1][k][0]) % md;
					if (k > 0) d[i][j][k][2] = (1LL * d[i - 1][j][k - 1][1] + 1LL * d[i - 1][j][k - 1][0]) % md;
				}
				else {
					d[i][j][k][0] = (1LL * d[i - 1][j][k][1] * 24 + 1LL * d[i - 1][j][k][2] * 24 + 1LL * d[i - 1][j][k][0] * 24) % md;
					if (j > 0) d[i][j][k][1] = (1LL * d[i - 1][j - 1][k][1] + 1LL * d[i - 1][j - 1][k][2] + 1LL * d[i - 1][j - 1][k][0]) % md;
					if (k > 0) d[i][j][k][2] = (1LL * d[i - 1][j][k - 1][1] + 1LL * d[i - 1][j][k - 1][2] + 1LL * d[i - 1][j][k - 1][0]) % md;
				}
			}
	for (int i = n; i >= 0; i--)
		for (int j = n; j >= 0; j--) {
			s[i][j] = (s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + 1LL * d[n][i][j][0] + 1LL * d[n][i][j][1] + 1LL * d[n][i][j][2]) % md;
			s[i][j] = (s[i][j] + md) % md;
		}
	for (int i = 0; i < 26; i++)
		cin >> c[i];
	long long ans = 26 * 26;
	for (int i = 0; i < n - 2; i++)
		ans = (ans * 25) % md;
	for (int i = 0; i < 26; i++)
		ans = (ans - s[c[i] + 1][0]) % md;
	ans = (ans + md) % md;
	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++)
			ans = (ans + s[c[i] + 1][c[j] + 1]) % md;
	cout << ans << '\n';
	return 0;
}