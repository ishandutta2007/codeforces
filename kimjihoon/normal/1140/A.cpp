#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int mx = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; mx = max(mx, a);
		if (mx == i) ans++;
	}
	cout << ans << '\n';
	return 0;
}