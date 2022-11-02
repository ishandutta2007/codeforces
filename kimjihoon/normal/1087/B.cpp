#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	int n, k; cin >> n >> k;
	int ans = n * k + 1;
	for (int i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		int a = i, b = n / i;
		if (b < k) ans = min(ans, a * k + b);
		if (a < k) ans = min(ans, b * k + a);
	}
	cout << ans << '\n';
	return 0;
}