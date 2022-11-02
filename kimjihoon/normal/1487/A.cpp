#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int mn = 1000000000;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mn = min(mn, a[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] != mn)
				ans++;
		cout << ans << '\n';
	}
	return 0;
}