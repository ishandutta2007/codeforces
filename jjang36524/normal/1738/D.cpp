#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[100100];
vector<int> c[100100];
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
		int i;
		int mi=N;
		int k = -1;
		for (i = 0; i < N; i++)
		{
			c[i + 1].clear();
			cin >> arr[i];
			mi = min(mi, arr[i]-1);
			if (mi <= i&&k==-1)
			{
				k = i;
			}
		}
		if (k == -1)
			k = N;
		for (i = 0; i < N; i++)
		{
			c[arr[i]].push_back(i+1);
		}
		vector<int>f;
		for (i = 0; i < N; i++)
		{
			if (arr[i] == N + 1 || arr[i] == 0)
			{
				f.push_back(i+1);
			}
		}
		cout << k << '\n';
		while (f.size())
		{
			for (i = 0; i < f.size(); i++)
			{
				if (!c[f[i]].size())
				{
					cout << f[i] << ' ';
				}
			}
			vector<int>nf;
			for (i = 0; i < f.size(); i++)
			{
				if (c[f[i]].size())
				{
					cout << f[i] << ' ';
					nf = c[f[i]];
				}
			}
			f = nf;
		}
		cout << '\n';
	}
}