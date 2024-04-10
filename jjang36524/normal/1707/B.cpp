#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int>x;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		int vt = N;
		while (x.size() >1)
		{
			vector<int>y;
			sort(x.begin(), x.end());
			int v = 0;
			for (i = 0; i < x.size()-1; i++)
			{
				if (x[i] != x[i + 1])
				{
					y.push_back(x[i + 1] - x[i]);
				}
				else
					v = 1;
			}
			if (x.size() != vt)
			{
				v = 1;
			}
			vt--;
			if (v)
				y.push_back(0);
			x = y;
		}
		if (x.size() == 1)
			cout << x[0] << '\n';
		else
			cout << 0 << '\n';
	}
}