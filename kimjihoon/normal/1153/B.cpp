#include <iostream>
#include <algorithm>
using namespace std;

int a[109], b[109], p[109][109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, h; cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			if (p[i][j] == 1)
				p[i][j] = min(a[j], b[i]);
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << p[i][j] << " ";
		cout << '\n';
	}
	return 0;
}