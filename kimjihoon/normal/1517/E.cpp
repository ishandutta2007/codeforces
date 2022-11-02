#include <iostream>
#include <algorithm>
using namespace std;

long long a[200009], s[200009], r[200009], p[200009], md = 998244353;

long long ps(int n, long long k)
{
	if (n < 0) return 0LL;
	long long ans = 0;
	int rp[2] = { n, n };
	rp[1 - (n % 2)]--;
	for (int i = 0; i <= n; i++) {
		int t = i % 2;
		while (rp[t] - 2 >= i && p[i] + r[rp[t] - 2] >= k)
			rp[t] -= 2;
		while (rp[t] < i) rp[t] += 2;
		if (rp[t] <= n && rp[t] >= 0 && p[i] + r[rp[t]] >= k) {
			ans += (n - rp[t]) / 2 + 1;
			ans = ans % md;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		reverse(a + 1, a + n + 1);
		s[0] = r[0] = p[0] = a[0] = 0;
		for (int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + a[i];
			if (i < 2) r[i] = a[i];
			else r[i] = r[i - 2] + a[i];
			p[i] = s[i] - r[i];
		}
		long long k = s[n] / 2LL + 1LL;
		long long ans = ps(n, k) + ps(n - 3, k - a[n]);
		for (int i = 3; i <= n; i++)
			if (s[n] - s[i - 1] >= k) ans++;
		if (n >= 3) {
			if (a[n] >= k) ans = (ans + md - 1) % md;
			k -= a[2] + a[3];
			for (int i = 1; i <= n - 3; i++)
				a[i] = a[i + 3];
			s[0] = r[0] = p[0] = a[0] = 0;
			for (int i = 1; i <= n - 3; i++) {
				s[i] = s[i - 1] + a[i];
				if (i < 2) r[i] = a[i];
				else r[i] = r[i - 2] + a[i];
				p[i] = s[i] - r[i];
			}
			ans += ps(n - 3, k) + ps(n - 6, k - a[n - 3]);
		}
		ans = ans % md;
		cout << ans << '\n';
	}
	return 0;
}