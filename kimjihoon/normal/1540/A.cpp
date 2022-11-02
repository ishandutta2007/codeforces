#include <iostream>
#include <algorithm>
using namespace std;

int d[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		sort(d + 1, d + n + 1);
		long long ans = d[n], s = 0;
		for (int i = 1; i <= n; i++) {
			ans += s - 1LL * (i - 1) * d[i];
			s += d[i];
		}
		cout << ans << '\n';
	}
	return 0;
}