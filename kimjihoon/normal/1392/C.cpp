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
		int p = 0;
		long long ans = 0;
		a[0] = -1;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] >= a[i] && (i == n || a[i] < a[i + 1]))
				ans += p - a[i];
			else if (a[i - 1] < a[i])
				p = a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}