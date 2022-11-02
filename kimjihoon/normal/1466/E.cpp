#include <iostream>
#include <algorithm>
using namespace std;

long long x[500009], sc[109], md = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < 60; i++)
			sc[i] = 0;
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			s = (s + x[i]) % md;
			for (int j = 0; j < 60; j++)
				if ((1LL << j) & x[i])
					sc[j] = (sc[j] + (1LL << j)) % md;
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long a = 0;
			for (int j = 0; j < 60; j++)
				if ((1LL << j) & x[i])
					a = (a + sc[j]) % md;
			long long b = (s - a + (x[i] % md) * (1LL * n)) % md;
			b = (b + md) % md;
			ans = (ans + a * b) % md;
		}
		cout << ans << '\n';
	}
	return 0;
}