#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[100009], b[100009], c[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		long long s = 0, ans = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] == b[i]) s = 0;
			if (!s) s += abs(a[i] - b[i]) + 2;
			else s += c[i - 1] - abs(a[i] - b[i]) + 1;
			s = max(s, abs(a[i] - b[i]) + 2);
			ans = max(ans, s + c[i] - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}