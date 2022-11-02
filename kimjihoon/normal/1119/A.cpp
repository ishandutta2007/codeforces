#include <iostream>
#include <algorithm>
using namespace std;

int c[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] != c[0]) ans = max(ans, i);
		if (c[i] != c[n - 1]) ans = max(ans, n - 1 - i);
	}
	cout << ans << '\n';
	return 0;
}