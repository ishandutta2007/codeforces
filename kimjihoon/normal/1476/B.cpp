#include <iostream>
#include <algorithm>
using namespace std;

int p[109];
long long sp[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			if (i > 0) {
				sp[i - 1] = 100LL * p[i];
				if (sp[i - 1] % (1LL * k) == 0) sp[i - 1] /= k;
				else sp[i - 1] = (sp[i - 1] / k) + 1;
			}
		}
		long long ans = 0, s = 0;
		for (int i = 0; i < n - 1; i++) {
			s += p[i];
			if (s < sp[i]) {
				ans += sp[i] - s;
				s = sp[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}