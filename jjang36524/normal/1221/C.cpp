#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int s = 0;
		int e = 1LL << 30;
		while (s != e)
		{
			int m = (s + e+1) / 2;
			int na = a - m;
			int nb = b - m;
			if (na < 0 || nb < 0 || na + nb + c < m)
				e = m - 1;
			else
				s = m;
		}
		cout << s << '\n';
	}
}