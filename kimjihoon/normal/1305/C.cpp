#include <iostream>
#include <algorithm>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n > m) {
		cout << 0 << '\n';
		return 0;
	}
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			ans = 1LL * (a[i] - a[j]) * ans % m;
		}
	cout << ans << '\n';
	return 0;
}