#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int T, a, b, c, d, e, f;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		vector<int>x, y;
		int i;
		int ans = 0;
		for (i = 0; i < a; i++)
		{
			int t;
			cin >> t;
			x.push_back(t);
			ans += t;
		}
		sort(x.begin(), x.end());
		for (i = 0; i < a; i++)
		{
			int t;
			cin >> t;
			y.push_back(-t);
		}
		sort(y.begin(), y.end());
		for (i = 0; i < b; i++)
		{
			if (x[i] + y[i] > 0)
				break;
			ans -= x[i] + y[i];
		}
		cout << ans << '\n';
	}
}