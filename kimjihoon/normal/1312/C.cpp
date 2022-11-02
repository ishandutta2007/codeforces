#include <iostream>
#include <algorithm>
using namespace std;

bool vs[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; long long k; cin >> n >> k;
		for (int i = 0; i <= 100; i++)
			vs[i] = false;
		bool f = true;
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			int c = 0;
			while (a) {
				long long t = a % k; a /= k;
				if (t > 1) {
					f = false;
					break;
				}
				else if (t == 1) {
					if (vs[c]) {
						f = false;
						break;
					}
					vs[c] = true;
				}
				c++;
			}
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}