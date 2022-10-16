#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (abs(a - c) + abs(b - d) <= e||(d-e<=1&&d+e>=b) || (c - e <= 1 && c + e >= a) || (d - e <= 1 && c - e <= 1) || (d + e >= b && c + e >= a))
			cout << -1 << '\n';
		else
		{
			cout << a + b - 2 << '\n';
		}
	}
}