#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int x, y; cin >> x >> y;
		long long ans = 0;
		for (int i = 2; i * i - 1 <= x && i <= y; i++) {
			long long a = i * i - 1, d = i - 1;
			long long r = min(1LL * x, 1LL * a + 1LL * d * (y - i)) - 1LL * a;
			ans += r / d + 1LL;
		}
		cout << ans << '\n';
	}
	return 0;
}