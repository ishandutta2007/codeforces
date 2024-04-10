#include <iostream>
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
		if (a < 3)
		{
			cout << (a - 1) * b << '\n';
		}
		else
			cout << 2 * b << '\n';
	}
}