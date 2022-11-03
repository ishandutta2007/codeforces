#include <iostream>
#include <algorithm>
using namespace std;

long long a[5009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)	
			cin >> a[i];
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			long long t = 0;
			for (int j = 1; j < i; j++)
				if (a[j] > i - j)
					t += a[j] - 1LL * (i - j);
			t = ans - t;
			ans += max(0LL, a[i] - t - 1LL);
		}
		cout << ans << '\n';
	}
	return 0;
}