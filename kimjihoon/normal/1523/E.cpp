#include <iostream>
#include <algorithm>
using namespace std;

long long ft[100009], rt[100009], p[100009], md = 1000000007;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

long long cb(int n, int k)
{
	if (n < k) return 0LL;
	long long s = (ft[n] * rt[k]) % md;
	return (s * rt[n - k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	ft[0] = rt[0] = 1;
	for (int i = 1; i <= 100000; i++)
		ft[i] = (ft[i - 1] * i) % md;
	rt[100000] = fp(ft[100000], md - 2);
	for (int i = 100000 - 1; i >= 1; i--)
		rt[i] = (rt[i + 1] * (i + 1)) % md;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			if (1LL * n < 1LL * (k - 1) * (i - 1)) p[i] = 0;
			else p[i] = cb(n - (k - 1) * (i - 1), i);
			p[i] = (p[i] * ft[i]) % md;
		}
		p[n + 1] = 0;
		long long ans = 0;
		for (int i = 2; i <= n; i++) {
			long long s = (p[i - 1] * (n - i + 1) - p[i]) % md;
			s = (s * i) % md;
			s = (s * ((ft[n - i] * rt[n]) % md)) % md;
			ans = (ans + s) % md;
		}
		cout << ans << '\n';
	}
	return 0;
}