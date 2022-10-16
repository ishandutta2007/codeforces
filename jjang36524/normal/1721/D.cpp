#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<vector<int>>a, b;
		vector<int>ia, ib;
		int i;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			ia.push_back(x);
		}
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			ib.push_back(x);
		}
		a.push_back(ia);
		b.push_back(ib);
		int ans = 0;
		for (i = 29; i >=0; i--)
		{
			int j;
			for (j = 0; j < a.size(); j++)
			{
				int za = 0;
				int k;
				for (k = 0; k < a[j].size(); k++)
				{
					za += !(a[j][k] & (1 << i));
				}
				for (k = 0; k < a[j].size(); k++)
				{
					za += !(b[j][k] & (1 << i));
				}
				if (za != a[j].size())
				{
					break;
				}
			}
			if (j == a.size())
			{
				ans += (1 << i);
				vector<vector<int>>na, nb;
				for (j = 0; j < a.size(); j++)
				{
					vector<int>za, oa, zb, ob;
					int k;
					for (k = 0; k < a[j].size(); k++)
					{
						if (!(a[j][k] & (1 << i)))
							za.push_back(a[j][k]);
						else
							oa.push_back(a[j][k]);
					}
					for (k = 0; k < a[j].size(); k++)
					{
						if (!(b[j][k] & (1 << i)))
							zb.push_back(b[j][k]);
						else
							ob.push_back(b[j][k]);
					}
					if (za.size())
					{
						na.push_back(za);
						nb.push_back(ob);
					}
					if (oa.size())
					{
						na.push_back(oa);
						nb.push_back(zb);
					}
					
				}
				a = na;
				b = nb;
			}
		}
		cout << ans << '\n';
	}
}