#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		long long mx = -1, mx1 = -1;
		int mi = 0;
		for (int i = 0; i < n; i++) {
			long long s = 0;
			for (int j = 0; j < m; j++) {
				int t; cin >> t;
				s += 1LL * t * j;
			}
			if (mx <= s) {
				mx1 = mx;
				mx = s;
				mi = i;
			}
			else if (mx1 < s)
				mx1 = s;
		}
		cout << mi + 1 << " " << mx - mx1 << '\n';
	}
	return 0;
}