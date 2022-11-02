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
		if (n % 2050LL != 0LL) {
			cout << -1 << '\n';
			continue;
		}
		n /= 2050LL;
		long long ans = 0;
		while (n) {
			ans += n % 10LL;
			n /= 10;
		}
		cout << ans << '\n';
	}
	return 0;
}