#include <iostream>
#include <algorithm>
using namespace std;

long long md = 998244353;
int a[300009];

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
	long long s = 1, ds = 1;
	for (int i = 0; i < k; i++) {
		s = (s * (n - i)) % md;
		ds = (ds * (i + 1)) % md;
	}
	return (s * fp(ds, md - 2)) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	long long s = 0;
	for (int i = 0; i < n; i++)
		s -= a[i];
	for (int i = n; i < 2 * n; i++)
		s += a[i];
	s = s % md;
	cout << (s * cb(2 * n - 1, n - 1) * 2) % md << '\n';
	return 0;
}