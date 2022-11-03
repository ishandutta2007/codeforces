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
		int n; cin >> n;
		bool f = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && a[i] != a[i - 1])
				f = false;
		}
		if (f) cout << n << '\n';
		else cout << 1 << '\n';
	}
	return 0;
}