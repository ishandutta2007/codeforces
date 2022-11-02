#include <iostream>
#include <algorithm>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; long long k; cin >> n >> k;
		if (k > 5) k = k % 2 + 4;
		int mx = -1000000009;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		for (int i = 0; i < k; i++) {
			int tmx = -1000000009;
			for (int j = 1; j <= n; j++) {
				a[j] = mx - a[j];
				tmx = max(tmx, a[j]);
			}
			mx = tmx;
		}
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << '\n';
	}
	return 0;
}