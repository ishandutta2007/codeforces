#include <iostream>
#include <algorithm>
using namespace std;

long long a[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n / 2; i++)
		ans += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
	cout << ans << '\n';
	return 0;
}