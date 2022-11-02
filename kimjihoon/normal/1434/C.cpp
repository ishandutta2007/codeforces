#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long a, b, c, d; cin >> a >> b >> c >> d;
		if (c < d) {
			if (a > b * c) cout << -1 << '\n';
			else cout << a << '\n';
			continue;
		}
		long long t = (c - 1) / d + 1LL, p = t * d;
		if (c % d != 0LL) p = p - d + (c % d);
		if (p * b < a) {
			cout << -1 << '\n';
			continue;
		}
		long long x = (a - 1LL) / (b * d);
		cout << a * (x + 1) - x * (x + 1) / 2LL * b * d << '\n';
	}
	return 0;
}