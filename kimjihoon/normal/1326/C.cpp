#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	long long ans = 0, s = 1, r = 0, md = 998244353;
	bool f = false;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a > n - k) {
			ans += a;
			if (f) s = (s * r) % md;
			r = 0; f = true;
		}
		r++;
	}
	cout << ans << " " << s << '\n';
	return 0;
}