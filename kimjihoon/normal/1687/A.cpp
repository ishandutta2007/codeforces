#include <iostream>
#include <algorithm>
using namespace std;

long long s[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			s[i] = s[i - 1] + a;
		}
		if (k <= n) {
			long long mx = 0;
			for (int i = k; i <= n; i++)
				mx = max(mx, s[i] - s[i - k]);
			cout << mx + 1LL * k * (k - 1) / 2LL << '\n';
		}
		else {
			cout << s[n] + 1LL * (k - 1) * n - 1LL * n * (n - 1) / 2LL << '\n';
		}
	}
	return 0;
}