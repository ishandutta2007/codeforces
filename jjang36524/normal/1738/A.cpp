#include <bits/stdc++.h>
using namespace std;
#define int long long
int vis[100100];
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
		vector<int>a, b;
		for (i = 0; i < N; i++)
		{
			cin >> vis[i];
		}
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			ans += x;
			if (vis[i])
			{
				b.push_back(x);
			}
			else
			{
				a.push_back(x);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a.size() < b.size())
		{
			for (i = 0; i < a.size(); i++)
			{
				ans += a[i];
			}
			for (i = b.size() - a.size(); i < b.size(); i++)
			{
				ans += b[i];
			}
		}
		else if (a.size() > b.size())
		{
			swap(a, b);
			for (i = 0; i < a.size(); i++)
			{
				ans += a[i];
			}
			for (i = b.size() - a.size(); i < b.size(); i++)
			{
				ans += b[i];
			}
		}
		else
		{
			for (i = 0; i < a.size(); i++)
			{
				ans += a[i];
			}
			for (i = b.size() - a.size(); i < b.size(); i++)
			{
				ans += b[i];
			}
			ans -= min(a[0], b[0]);
		}
		cout << ans << '\n';
	}
}