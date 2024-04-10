#include <iostream>
using namespace std;

long long a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, k; int m; cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int ans = 1;
	long long t = 0, c = 0;
	for (int i = 0; i < m - 1; i++) {
		c++;
		if ((a[i] - 1LL - t) / k != (a[i + 1] - 1LL - t) / k) {
			ans++;
			t += c;
			c = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}