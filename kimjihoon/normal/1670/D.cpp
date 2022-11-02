#include <iostream>
#include <algorithm>
using namespace std;

long long bs(long long s, long long e, long long p)
{
	long long md = (s + e) / 2;
	while (s < e) {
		if (md * md * 6 < p) s = md + 1;
		else e = md;
		md = (s + e) / 2;
	}
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long n; cin >> n;
		long long ans = bs(1LL, 100000LL, n) * 3;
		while (ans - 1 > 0) {
			long long s = ans - 1;
			long long a = s / 3, b = a, c = a;
			if (a + b + c < s) a++;
			if (a + b + c < s) b++;
			if (s * s - a * a - b * b - c * c < n) break;
			ans = s;
		}
		cout << ans << '\n';
	}
	return 0;
}