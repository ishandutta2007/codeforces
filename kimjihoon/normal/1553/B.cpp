#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool d[1009][509][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s, t; cin >> s >> t;
		int n, m; n = s.length(); m = t.length();
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n + 1; j++) {
				d[i][j][0] = d[i][j][1] = false;
			}
		for (int i = 0; i <= n + 1; i++)
			d[0][i][0] = true;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (s[j - 1] == t[i - 1]) {
					if (d[i - 1][j - 1][0])
						d[i][j][0] = true;
					if (d[i - 1][j + 1][0] || d[i - 1][j + 1][1])
						d[i][j][1] = true;
				}
		bool f = false;
		for (int i = 1; i <= n; i++)
			if (d[m][i][0] || d[m][i][1]) {
				f = true;
				break;
			}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}