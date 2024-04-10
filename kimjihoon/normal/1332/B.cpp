#include <iostream>
using namespace std;

int p[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
int a[1009], ans[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans[i] = 0;
		}
		int r = 1, c = 0;
		for (int i = 0; i < 11; i++) {
			bool f = false;
			for (int j = 0; j < n; j++)
				if (ans[j] == 0 && a[j] % p[i] == 0) {
					c++;
					ans[j] = r;
					f = true;
				}
			if (c == n) break;
			if (f) r++;
		}
		cout << r << '\n';
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}