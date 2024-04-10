#include <iostream>
#include <algorithm>
using namespace std;

long long md = 1000000007;
long long pp[200009], ft[200009], rp[200009];
const int N = 200001;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

long long cb(long long n, long long k)
{
	return (((ft[n] * rp[k]) % md) * rp[n - k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	ft[0] = rp[0] = 1;
	for (int i = 1; i <= N; i++)
		ft[i] = (ft[i - 1] * i) % md;
	rp[N] = fp(ft[N], md - 2);
	for (int i = N - 1; i >= 1; i--)
		rp[i] = (rp[i + 1] * (i + 1)) % md;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		pp[0] = 1;
		long long tr = 1;
		for (int i = 1; i <= n; i++)
			tr = (tr * 2) % md;
		for (int i = 1; i <= k; i++)
			pp[i] = (pp[i - 1] * tr) % md;
		long long ans = 0, s = 1, c = 0;
		for (int i = 0; i < n; i += 2)
			c = (c + cb(n, i)) % md;
		if (n & 1) c = (c + 1) % md;
		for (int i = 0; i < k; i++) {
			if (!(n & 1)) ans = (ans + s * pp[k - i - 1]) % md;
			s = (s * c) % md;
		}
		ans = (ans + s) % md;
		cout << ans << '\n';
	}
	return 0;
}