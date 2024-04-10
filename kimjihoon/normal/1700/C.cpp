#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

long long a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		long long ans = 0, p0 = a[1];
		for (int i = 2; i <= n; i++) {
			long long t = a[i] - a[i - 1];
			if (t > 0) ans += t;
			else if (t < 0) {
				ans -= t;
				p0 += t;
			}
		}
		ans += abs(p0);
		cout << ans << '\n';
	}
	return 0;
}