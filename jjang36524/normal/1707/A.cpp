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
		int N, Q;
		cin >> N >> Q;
		int i;
		vector<int>x;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		if (Q >= N)
		{
			int i;
			for (i = 0; i < N; i++)
			{
				cout << 1;
			}
			cout << '\n';
		}
		else
		{
			vector<int>ans;
			int cr = 0;
			for (i = N - 1; i >= 0; i--)
			{
				if (x[i] > cr)
				{
					if (cr != Q)
					{
						ans.push_back(1);
						cr++;
					}
					else
						ans.push_back(0);
				}
				else
				{
					ans.push_back(1);
				}
			}
			while (ans.size())
			{
				cout << ans.back();
				ans.pop_back();
			}
			cout << '\n';
		}
	}
}