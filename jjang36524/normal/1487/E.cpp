#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string.h>
#define int long long
using namespace std;
vector<int>arr[4];
int siz[4];
vector<int>fo[200100][3];
int cc[200100][2];
signed main()
{
	ios_base::sync_with_stdio(false);
	int i;
	for (i = 0; i < 4; i++)
	{
		cin >> siz[i];
	}
	for (i = 0; i < 4; i++)
	{
		int j;
		for (j = 0; j < siz[i]; j++)
		{
			int x;
			cin >> x;
			arr[i].push_back(x);
		}
	}
	memset(cc, 10, sizeof(cc));
	for (i = 0; i < 3; i++)
	{
		int x;
		cin >> x;
		while (x--)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if (i == 0)
				fo[b][0].push_back(a);
			else if (i == 1)
				fo[a][2].push_back(b);
			else
				fo[a][1].push_back(b);
		}
	}
	set<pair<int,int>>x;
	for (i = 0; i < siz[3]; i++)
	{
		x.insert({ arr[3][i],i });
	}
	for (i = 0; i < siz[2]; i++)
	{
		sort(fo[i][1].begin(), fo[i][1].end());
		auto it = x.begin();
		int c = 0;
		while (it != x.end())
		{
			if (it == x.end())
				break;
			if (upper_bound(fo[i][1].begin(), fo[i][1].end(), (*it).second) == lower_bound(fo[i][1].begin(), fo[i][1].end(), (*it).second))
			{
				c = 1;
				break;
			}
			it++;
			
		}
		if (c)
		{
			cc[i][1] = it->first+arr[2][i];
		}
	}
	x.clear();
	for (i = 0; i < siz[0]; i++)
	{
		x.insert({ arr[0][i],i });
	}
	for (i = 0; i < siz[1]; i++)
	{
		sort(fo[i][0].begin(), fo[i][0].end());
		auto it = x.begin();
		int c = 0;
		while (it != x.end())
		{
			if (it == x.end())
				break;
			if (upper_bound(fo[i][0].begin(), fo[i][0].end(), (*it).second) == lower_bound(fo[i][0].begin(), fo[i][0].end(), (*it).second))
			{
				c = 1;
				break;
			}
			it++;

		}
		if (c)
		{
			cc[i][0] = it->first + arr[1][i];
		}
	}
	x.clear();
	for (i = 0; i < siz[2]; i++)
	{
		x.insert({ cc[i][1],i });
	}
	int ans = 987654321;
	for (i = 0; i < siz[1]; i++)
	{
		sort(fo[i][2].begin(), fo[i][2].end());
		auto it = x.begin();
		int c = 0;
		while (it != x.end())
		{
			if (it == x.end())
				break;
			if (upper_bound(fo[i][2].begin(), fo[i][2].end(), (*it).second) == lower_bound(fo[i][2].begin(), fo[i][2].end(), (*it).second))
			{
				c = 1;
				break;
			}
			it++;

		}
		if (c)
		{
			ans=min(it->first + cc[i][0],ans);
		}
	}
	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;
}