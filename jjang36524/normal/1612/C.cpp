#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
vector<int>x,y,n;
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		int s = 1;
		int e = 2 * a-1;
		while (s != e)
		{
			int m = (s + e) / 2;
			int cur = min(m,a) * (min(m,a) + 1) / 2;
			if (m > a)
			{
				cur += (a - 1 + 2 * a - m) * (m-a) / 2;
			}
			if (cur >= b)
				e = m;
			else
				s = m + 1;
		}
		cout << s << '\n';
	}
}