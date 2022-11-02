#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int a, b; cin >> a >> b;
		int ans = 1000000000, t = max(2, b);
		for (int j = t; j < t + 100; j++) {
			int s = j - b, ta = a;
			while (ta) {
				s++; ta /= j;
			}
			ans = min(ans, s);
		}
		cout << ans << '\n';
	}
	return 0;
}