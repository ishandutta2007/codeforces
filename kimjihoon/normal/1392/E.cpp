#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long a[29][29];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2) a[i][j] = 0;
			else a[i][j] = (1LL << (i + j - 3));
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		long long k; cin >> k;
		cout << 1 << " " << 1 << endl;
		int x = 1, y = 1;
		for (int i = 0; i < 2 * n - 2; i++) {
			long long t = (k & (1LL << i));
			if (x < n && a[y][x + 1] == t) x++;
			else y++;
			cout << y << " " << x << endl;
		}
	}
	return 0;
}