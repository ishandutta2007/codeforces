#include <iostream>
#include <algorithm>
using namespace std;

int a[109][3], d[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < 3; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[j][i];
		d[1] = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[i][j] != a[i - 1][d[i - 1]]) {
					d[i] = j;
					break;
				}
			}
		}
		while (a[1][d[1]] == a[n][d[n]] || a[n - 1][d[n - 1]] == a[n][d[n]])
			d[n]++;
		for (int i = 1; i <= n; i++)
			cout << a[i][d[i]] << " ";
		cout << '\n';
	}
	return 0;
}