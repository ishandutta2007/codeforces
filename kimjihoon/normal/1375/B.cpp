#include <iostream>
#include <algorithm>
using namespace std;

int a[309][309], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		bool f = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int c = 4;
				for (int k = 0; k < 4; k++) {
					int tx = j + dx[k], ty = i + dy[k];
					if (tx < 0 || tx >= m || ty < 0 || ty >= n)
						c--;
				}
				if (c < a[i][j])
					f = false;
				a[i][j] = c;
			}
		if (!f) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					cout << a[i][j] << " ";
				cout << '\n';
			}
		}
	}
	return 0;
}