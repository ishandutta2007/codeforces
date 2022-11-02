#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; long long k, b, s; cin >> n >> k >> b >> s;
		if (b * k > s || b * k + (k - 1LL) * n < s) {
			cout << -1 << '\n';
			continue;
		}
		s -= b * k;
		for (int i = 1; i <= n; i++) {
			long long t = 0;
			if (i == 1) t = b * k;
			if (s >= k - 1LL) {
				cout << t + k - 1LL << " ";
				s -= k - 1LL;
			}
			else {
				cout << t + s << " ";
				s = 0;
			}
		}
		cout << '\n';
	}
	return 0;
}