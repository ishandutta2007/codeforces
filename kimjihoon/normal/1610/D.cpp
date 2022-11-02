#include <iostream>
#include <algorithm>
using namespace std;

const long long md = 1000000007;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

long long ft[200009], rt[200009], c[31], p2[200009];

long long cb(int n, int k)
{
	if (n < k) return 0LL;
	return (((ft[n] * rt[k]) % md) * rt[n - k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	ft[0] = rt[0] = p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		ft[i] = (ft[i - 1] * i) % md;
		p2[i] = (p2[i - 1] * 2) % md;
	}
	rt[n] = fp(ft[n], md - 2);
	for (int i = n - 1; i >= 1; i--)
		rt[i] = (rt[i + 1] * (i + 1)) % md;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		int tp = 0;
		while (a % 2 == 0) {
			a /= 2;
			tp++;
		}
		c[tp]++;
		ans = (ans * 2) % md;
	}
	ans = (ans - 1LL + md) % md;
	n -= c[0];
	for (int i = 1; i <= 30; i++) {
		n -= c[i];
		for (int j = 1; j <= c[i]; j += 2)
			ans = (ans - ((cb(c[i], j) * p2[n]) % md) + md) % md;
	}
	cout << ans << '\n';
	return 0;
}