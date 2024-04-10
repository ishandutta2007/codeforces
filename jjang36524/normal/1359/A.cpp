#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int N, M,T, a, b, c, d;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		if (b >= (a/c))
		{
			int g = a / c;
			cout << (g - ((b - a/c+c-2) / (c - 1))) << '\n';
		}
		else
		{
			cout << b << '\n';
		}
	}
}