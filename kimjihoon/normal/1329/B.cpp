#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long n, m; cin >> n >> m;
		long long t = 2, ans = 0;
		while (t <= n) {
			ans = (ans + 1LL * (t / 2) * (ans + 1)) % m;
			t *= 2;
		}
		t /= 2;
		ans = (ans + 1LL * (n - t + 1) * (ans + 1)) % m;
		cout << ans << '\n';
	}
	return 0;
}