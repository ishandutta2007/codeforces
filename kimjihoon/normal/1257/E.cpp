#include <iostream>
#include <algorithm>
using namespace std;

int a[200009], s[200009][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int k1, k2, k3; cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (i < k1) a[t] = 0;
		else if (i < k1 + k2) a[t] = 1;
		else a[t] = 2;
	}
	int mj = 1000000000, ans = 1000000000;
	for (int i = 1; i <= n + 1; i++) 
		for (int j = 0; j < 3; j++) {
			if (j == a[i] && i != n + 1) s[i][j] = s[i - 1][j] + 1;
			else s[i][j] = s[i - 1][j];
		}
	for (int i = 0; i <= n + 1; i++) {
		ans = min(ans, n - s[n][2] + mj + s[max(i - 1, 0)][2] - s[i][1]);
		mj = min(mj, s[max(i - 1, 0)][1] - s[i][0]);
	}
	cout << ans << '\n';
	return 0;
}