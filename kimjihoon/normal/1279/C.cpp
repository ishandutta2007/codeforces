#include <iostream>
#include <algorithm>
using namespace std;

int r[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			r[a] = i;
		}
		int mx = 0;
		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			int a; cin >> a;
			if (mx < r[a]) {
				ans += 2 * (r[a] - i) + 1;
				mx = r[a];
			}
			else
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}