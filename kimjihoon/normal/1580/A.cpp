#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[409][409], ss[409][409], rs[2][409][409], inf = 1000000000;
string s[409];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		int ans = inf;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++) {
				d[i][j] = -inf;
				rs[0][i][j] = rs[1][i][j] = 0;
			}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			s[i] = "0" + s[i];
			for (int j = 1; j <= m; j++)
				ss[i][j] = ss[i][j - 1] + (int)(s[i][j] - '0');
			for (int j = 1; j <= m; j++) {
				for (int k = j + 3; k <= m; k++) {
					if (i > 4) {
						rs[0][j][k] = rs[0][j][k] + (ss[i - 4][k - 1] - ss[i - 4][j]) + (int)('1' - s[i - 4][j]) + (int)('1' - s[i - 4][k]);
						d[j][k] = max(d[j][k], rs[0][j][k] - ((k - j - 1) - (ss[i - 4][k - 1] - ss[i - 4][j])));
						ans = min(ans, (k - j - 1) - (ss[i][k - 1] - ss[i][j]) + (rs[1][j][k] - d[j][k]));
					}
					rs[1][j][k] = rs[1][j][k] + (ss[i][k - 1] - ss[i][j]) + (int)('1' - s[i][j]) + (int)('1' - s[i][k]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}