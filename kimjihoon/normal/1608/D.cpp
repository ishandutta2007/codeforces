#include <iostream>
#include <algorithm>
using namespace std;

long long md = 998244353;
long long ft[100009], rt[100009];

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
	if (n < k) return 0;
	return (((ft[n] * rt[k]) % md) * rt[n - k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n; cin >> n;
	ft[0] = rt[0] = 1;
	for (int i = 1; i <= n; i++)
		ft[i] = (ft[i - 1] * i) % md;
	rt[n] = fp(ft[n], md - 2);
	for (int i = n - 1; i >= 1; i--)
		rt[i] = (rt[i + 1] * (i + 1)) % md;

	int r = 0, c1 = 0, c2 = 0;
	bool f = false, fw = false, fb = false;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s[1] == 'W') s[1] = 'B';
		else if (s[1] == 'B') s[1] = 'W';
		if (s[0] == '?' && s[1] == '?') c2++;
		else if (s[0] != '?' && s[1] != '?') {
			if (s[0] != s[1]) {
				f = true;
				if (s[0] == 'W') r++;
				else r--;
			}
		}
		else {
			c1++;
			if (s == "B?" || s == "?W") r--;
		}
		if (s[0] == 'W' || s[1] == 'W') fw = true;
		if (s[0] == 'B' || s[1] == 'B') fb = true;
	}
	long long ans = 0;
	for (int i = 0; i <= c2; i++) {
		long long ss = 0;
		int tr = -(r - i), tc = c1 + c2;
		if (tr < 0 || tr > tc) continue;
		ans = (ans + cb(c2, i) * cb(tc, tr)) % md;
	}
	if (!f) {
		long long t = 1;
		for (int i = 0; i < c2; i++)
			t = (t * 2) % md;
		ans = (ans + md - t) % md;
		if (!fw) ans = (ans + 1LL) % md;
		if (!fb) ans = (ans + 1LL) % md;
	}
	cout << ans << '\n';
	return 0;
}