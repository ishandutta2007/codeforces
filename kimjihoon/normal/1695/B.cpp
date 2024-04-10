#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1000000009;

int a[59];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int mn[2] = { inf, inf };
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			int t = (i & 1);
			mn[t] = min(mn[t], a[i]);
		}
		if (n & 1) cout << "Mike" << '\n';
		else {
			int c[2] = { 0, 0 };
			for (int i = 1; i <= n; i++) {
				int t = (i & 1);
				if (!c[t] && a[i] == mn[t]) c[t] = i;
			}
			long long r0 = 1LL * mn[0] * (n / 2) + 1LL * (c[0] + 1) / 2;
			long long r1 = 1LL * mn[1] * (n / 2) + 1LL * (c[1] + 1) / 2;
			if (r0 < r1) cout << "Mike" << '\n';
			else cout << "Joe" << '\n';
		}
	}
	return 0;
}