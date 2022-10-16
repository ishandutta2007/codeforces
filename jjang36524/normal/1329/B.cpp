#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int N;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		int ans = 1;
		int i;
		int lef = a;
		for (i = 1; lef>0; i *= 2)
		{
			if (lef < i)
				break;
			lef -= i;
			
			ans *= i + 1;
			
			ans %= b;
		}
		ans *= lef + 1;
		ans %= b;
		ans = (ans + b - 1) % b;
		cout << ans << '\n';
	}
}