#include <iostream>
#include <algorithm>
using namespace std;
int N, T, a, b, c, d;;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		if (a == b&&b>=c || b== c&&c>=a || c == a&&a>=b)
		{
			cout << "YES" << '\n';
			if (b == c)
			{
				cout << b << ' ' << a << ' ' << 1 << '\n';
			}
			else
			{
				cout << a << ' ' << ((b > c) ? c : b) << ' ' << 1 << '\n';
			}
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}