#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int ans = 10000;
		if (c <= e)
			ans = min(ans, e - c);
		else
			ans = min(ans, a - c + a - e);
		if (d <= f)
			ans = min(ans, f - d);
		else
			ans = min(ans, b - d + b - f);
		cout << ans << '\n';
	}
}