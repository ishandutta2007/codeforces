#include <iostream>
#include <algorithm>
using namespace std;

int c[100009], p[100009][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++)
			c[i] = 0;
		for (int i = 0; i < m; i++) {
			int k; cin >> k;
			p[i][0] = p[i][1] = 0;
			cin >> p[i][0];
			if (k == 1) {
				c[p[i][0]]++;
				continue;
			}
			cin >> p[i][1];
			for (int j = 0; j < k - 2; j++)
				cin >> p[i][1];
		}
		bool f = true;
		for (int i = 1; i <= n; i++) {
			if (c[i] > (m + 1) / 2) {
				f = false;
				break;
			}
		}
		if (!f) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			for (int i = 0; i < m; i++) {
				if (!p[i][1]) cout << p[i][0] << " ";
				else if (c[p[i][1]] >= (m + 1) / 2) {
					cout << p[i][0] << " ";
					c[p[i][0]]++;
				}
				else {
					cout << p[i][1] << " ";
					c[p[i][1]]++;
				}
			}
			cout << '\n';
		}
	}
	return 0;
}