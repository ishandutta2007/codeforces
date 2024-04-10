#include <iostream>
#include <algorithm>
using namespace std;

bool c[109][109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c[i][j] = false;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j <= i + n / 2; j++)
				c[i][j % n] = true;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (c[i][j] && c[j][i]) cout << 0 << " ";
				else if (c[i][j]) cout << 1 << " ";
				else cout << -1 << " ";
			}
		cout << '\n';
	}
	return 0;
}