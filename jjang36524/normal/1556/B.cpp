#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
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
		vector<int>y;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a % 2)
				x.push_back(i);
			else
				y.push_back(i);
		}
		if (x.size() > y.size())
			swap(x, y);
		if (x.size() + 1 < y.size())
		{
			cout << -1 << '\n';
		}
		else
		{
			long long ans = 1LL<<60;
			long long cur = 0;
			for (i = 0; i < x.size(); i++)
			{
				cur += abs(x[i] - (i * 2+1));
			}
			for (i = 0; i < y.size(); i++)
			{
				cur += abs(y[i] - (i * 2));
			}
			ans = cur/2;
			if (x.size() == y.size())
			{
				swap(x, y);
				cur = 0;
				for (i = 0; i < x.size(); i++)
				{
					cur += abs(x[i] - (i * 2 + 1));
				}
				for (i = 0; i < y.size(); i++)
				{
					cur += abs(y[i] - (i * 2));
				}
				ans = min(ans,cur/2);
			}
			cout << ans << '\n';
		}
	}
}