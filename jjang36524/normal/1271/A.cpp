#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a, b, c, d, e, f;
signed main()
{
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	int i;
	for (i = 0; i <= min({ a,d }); i++)
	{
		int t = i * e;
		t += f * (min({ b,c,d - i }));
		ans = max(ans, t);
	}
	cout << ans;
}