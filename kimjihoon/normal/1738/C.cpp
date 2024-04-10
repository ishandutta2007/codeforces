#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool d[109][109][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	d[0][0][0] = true; d[0][0][1] = false;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++) {
			if (!i && !j) continue;
			for (int k = 0; k < 2; k++) {
				d[i][j][k] = false;
				if (i > 0 && !d[i - 1][j][k ^ ((j + 1) & 1)]) d[i][j][k] = true;
				if (j > 0 && !d[i][j - 1][k ^ ((j + 1) & 1)]) d[i][j][k] = true;
			}
		}
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (abs(a) & 1) c1++;
			else c0++;
		}
		if (d[c0][c1][0]) cout << "Alice" << '\n';
		else cout << "Bob" << '\n';
	}
	return 0;
}