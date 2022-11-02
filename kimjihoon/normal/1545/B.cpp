#include <iostream>
#include <algorithm>
#include <string>
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
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		int c = 0, r = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				c++;
				int t = i + 1;
				if ((r & 1) == (t & 1)) r += 2;
				else r++;
			}
		}
		r = (n - r) / 2;
		c += r;
		long long ans = 1, rq = 1;
		for (int i = c; i > c - r; i--)
			ans = (ans * i) % md;
		for (int i = 1; i <= r; i++)
			rq = (rq * i) % md;
		ans = (ans * fp(rq, md - 2)) % md;
		cout << ans << '\n';
	}
	return 0;
}