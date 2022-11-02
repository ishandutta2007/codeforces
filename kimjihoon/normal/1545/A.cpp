#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], c[100009][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[a[i]][i & 1]++;
		}
		sort(a, a + n);
		bool f = true;
		for (int i = 0; i < n; i++) {
			c[a[i]][i & 1]--;
			if (c[a[i]][i & 1] < 0) {
				f = false;
				break;
			}
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		for (int i = 0; i < n; i++) {
			c[a[i]][0] = c[a[i]][1] = 0;
		}
	}
	return 0;
}