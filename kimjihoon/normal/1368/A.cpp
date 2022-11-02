#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long a, b, n; cin >> a >> b >> n;
		int ans = 0;
		while (a <= n && b <= n) {
			ans++;
			if (a > b) b += a;
			else a += b;
		}
		cout << ans << '\n';
	}
	return 0;
}