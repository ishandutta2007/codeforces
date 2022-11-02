#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long n; cin >> n;
		n = 2 * n - 1;
		long long s = 1, e = 100000, md = (s + e + 1LL) / 2;
		while (s < e) {
			md = (s + e + 1LL) / 2;
			if (md * md <= n) s = md;
			else e = md - 1;
		}
		md = (s + e + 1LL) / 2;
		cout << (md - 1LL) / 2 << '\n';
	}
	return 0;
}