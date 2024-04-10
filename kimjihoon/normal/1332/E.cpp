#include <iostream>
using namespace std;

long long md = 998244353;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k = (k >> 1);
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m, l, r; cin >> n >> m >> l >> r;
	long long ans = fp(r - l + 1, n * m);
	if ((n & 1) && (m & 1))
		cout << ans << '\n';
	else {
		if ((r - l + 1) & 1) cout << ((ans + 1) * fp(2, md - 2)) % md << '\n';
		else cout << (ans * fp(2, md - 2)) % md << '\n';
	}
	return 0;
}