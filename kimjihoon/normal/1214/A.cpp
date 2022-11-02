#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d, e; cin >> n >> d >> e;
	int ans = n;
	while (n >= 0) {
		ans = min(ans, n % d);
		n -= 5 * e;
	}
	cout << ans << '\n';
	return 0;
}