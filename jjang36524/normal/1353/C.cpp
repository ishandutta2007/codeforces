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
		cin >> a;
		int ans = 0;
		int i;
		for (i = 3; i <= a; i += 2)
		{
			ans += (i - 1) * 4*((i-1)/2);
		}
		cout << ans << '\n';
	}
}