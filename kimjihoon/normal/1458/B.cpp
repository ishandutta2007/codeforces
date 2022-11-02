#include <iostream>
#include <algorithm>
using namespace std;

int a[109], b[109], d[109][109][10009], ans[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int sb = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		a[i] *= 2; sb += b[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sb; j++)
			d[0][i][j] = -1000000000;
	d[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= sb; k++) {
				if (j < 1 || k < b[i]) d[i][j][k] = d[i - 1][j][k];
				else d[i][j][k] = max(d[i - 1][j][k], d[i - 1][j - 1][k - b[i]] + a[i]);
				ans[j] = max(ans[j], min(k + sb, d[i][j][k]));
			}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] & 1) cout << ans[i] / 2 << ".5 ";
		else cout << ans[i] / 2 << ".0 ";
	}
	cout << '\n';
	return 0;
}