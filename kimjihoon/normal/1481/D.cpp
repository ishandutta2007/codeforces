#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string c[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> c[i];
		if (m & 1) {
			cout << "YES" << '\n';
			for (int i = 0; i < m + 1; i++)
				cout << (i % 2) + 1 << " ";
			cout << '\n';
			continue;
		}
		int a = -1, b = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				if (c[i][j] == c[j][i]) {
					a = i + 1; b = j + 1;
					break;
				}
			if (a != -1) break;
		}
		if (a != -1) {
			cout << "YES" << '\n';
			for (int i = 0; i < m + 1; i++)
				cout << ((i & 1) ? a : b) << " ";
			cout << '\n';
			continue;
		}
		int r = -1;
		for (int i = 0; i < n; i++) {
			int p0 = -1, p1 = -1;
			for (int j = 0; j < n; j++) {
				if (c[i][j] == 'a') p0 = j;
				if (c[i][j] == 'b') p1 = j;
			}
			if (p0 != -1 && p1 != -1) {
				r = i + 1;
				a = p0 + 1; b = p1 + 1;
				break;
			}
		}
		if (r != -1) {
			cout << "YES" << '\n';
			if (m % 4 == 0) cout << r << " ";
			else cout << a << " ";
			for (int i = 0; i < m; i++) {
				if ((m % 4 == 0 && (i & 1)) || (m % 4 != 0 && !(i & 1))) cout << r << " ";
				else if (i < m / 2) cout << a << " ";
				else cout << b << " ";
			}
			cout << '\n';
		}
		else cout << "NO" << '\n';
	}
	return 0;
}