	#include <iostream>
	#include <algorithm>
	using namespace std;

	int a[1000009];
	long long md = 1000000007;

	long long fp(long long n, long long k)
	{
		long long s = 1;
		while (k) {
			if (k % 2) s = (s * n) % md;
			k /= 2; n = (n * n) % md;
		}
		return s;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		int tc; cin >> tc;
		for (int ti = 0; ti < tc; ti++) {
			int n, p; cin >> n >> p;
			for (int i = 0; i < n; i++) 
				cin >> a[i];
			if (p == 1) {
				cout << n % 2 << '\n';
				continue;
			}
			sort(a, a + n); reverse(a, a + n);
			long long r = 1, c = 0;
			int pi = -1;
			bool f = false;
			for (int i = 0; i < n; i++) {
				if (c) {
					int at = a[i - 1];
					while (c <= n && at > a[i]) {
						at--; c *= p;
						r--;
					}
					if (c > n) {
						f = true;
						break;
					}
					c--;
					continue;
				}
				if (i < n - 1 && a[i] == a[i + 1]) {
					i++;
					continue;
				}
				c = 1; r = a[i]; pi = i;
			}
			long long ans = 1;
			if (f) {
				ans = fp(p, a[pi]);
				long long t = 1;
				a[n] = 0;
				for (int i = n - 1; i > pi; i--) {
					t = (t * fp(p, a[i] - a[i + 1])) % md;
					ans = (ans - t + md) % md;
				}
			}
			else {
				ans = fp(p, r);
				ans = (ans * c) % md;
			}
			cout << ans << '\n';
		}
		return 0;
	}