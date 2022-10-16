#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int>rep;
		int now = N;
		while (now)
		{
			rep.push_back(now % 3);
			now /= 3;
		}
		rep.push_back(0);
		int i,c=1;
		int t = -1;
		for (i = 0; i < rep.size()-1; i++)
		{
			if (rep[i] == 2)
			{
				t = i;
			}
		}
		if (t == -1)
			goto T;
		for (i = 0; i < t; i++)
		{
			N -= c * rep[i];
			c *= 3;
		}
		for (i = t; i < rep.size(); i++)
		{
			if (rep[i] == 0)
				break;
			N += c;
			c *= 3;
		}
		T:
		cout << N << '\n';
	}
}