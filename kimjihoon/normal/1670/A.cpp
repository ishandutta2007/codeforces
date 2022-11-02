#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < 0) {
				c++;
				a[i] *= -1;
			}
		}
		for (int i = 1; i <= c; i++)
			a[i] *= -1;
		bool f = true;
		for (int i = 1; i < n; i++)
			if (a[i] > a[i + 1]) {
				f = false;
				break;
			}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}