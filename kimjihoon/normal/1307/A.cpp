#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, d; cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			while (a[i] > 0) {
				if (i - 1 > d) break;
				d -= i - 1; a[i]--; ans++;
			}
			if (i - 1 > d) break;
		}
		cout << ans << '\n';
	}
	return 0;
}