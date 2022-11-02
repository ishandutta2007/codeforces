#include <iostream>
#include <algorithm>
using namespace std;

long long md = 998244353;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	if (n <= 2) {
		cout << 0 << '\n';
		return 0;
	}
	long long ans = 1;
	for (int i = m - n + 2; i <= m; i++)
		ans = (ans * i) % md;
	long long s = 1;
	for (int i = 2; i < n; i++)
		s = (s * i) % md;
	ans = (ans * fp(s, md - 2)) % md;
	ans = (ans * (n - 2)) % md;
	for (int i = 0; i < n - 3; i++)
		ans = (ans * 2) % md;
	cout << ans << '\n';
	return 0;
}