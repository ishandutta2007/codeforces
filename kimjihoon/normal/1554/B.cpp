#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		long long ans = 1LL * n * (n - 1) - 1LL * k * (a[n] | a[n - 1]);
		for (int i = n; i >= 1; i--) {
			for (int j = i - 1; j >= 1; j--) {
				long long p = 1LL * i * j;
				if (p <= ans) break;
				p -= 1LL * k * (a[i] | a[j]);
				ans = max(ans, p);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}