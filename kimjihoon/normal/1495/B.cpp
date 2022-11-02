#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int p[100009], l[100009], r[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int mx = -1, mxc = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i - 1] > p[i]) l[i] = 0;
		else l[i] = l[i - 1] + 1;

		if (mx == l[i]) mxc++;
		else if (mx < l[i]) {
			mx = l[i]; mxc = 1;
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (p[i + 1] > p[i]) r[i] = 0;
		else r[i] = r[i + 1] + 1;

		if (mx == r[i]) mxc++;
		else if (mx < r[i]) {
			mx = r[i]; mxc = 1;
		}
	}
	if (mxc > 2) {
		cout << 0 << '\n';
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!l[i] || !r[i]) continue;
		if (l[i] == r[i] && r[i] % 2 == 0 && l[i] == mx) ans++;
	}
	cout << ans << '\n';
	return 0;
}