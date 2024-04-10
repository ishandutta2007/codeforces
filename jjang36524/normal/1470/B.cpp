#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#define int long long
using namespace std;
map < set<int>,int>x;
int isp[1001];
vector<int>pl;
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int i;
	for (i = 2; i <= 1000; i++)
	{
		if (!isp[i])
		{
			pl.push_back(i);
			int j;
			for (j = i * i; j <= 1000; j += i)
			{
				isp[j] = 1;
			}
		}
	}
	while (T--)
	{
		x.clear();
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			int j;
			int cura = a;
			set<int>curs;
			for (j = 0; j <pl.size(); j++)
			{
				int cou = 0;
				while (cura % pl[j] == 0)
				{
					cou++;
					cura /= pl[j];
				}
				if (cou % 2)
				{
					curs.insert(pl[j]);
				}
			}
			if (cura != 1)
			{
				curs.insert(cura);
			}
			x[curs]++;
		}
		int ans0 = 0;
		int ans1 = 0;
		for (auto it = x.begin(); it != x.end();it++)
		{
			ans0 = max(ans0, (*it).second);
		}
		set<int>em;
		for (auto it = x.begin(); it != x.end(); it++)
		{
			if ((*it).first.size() == 0)
				continue;
			if ((*it).second % 2 == 0)
			{
				
				x[em] += (*it).second;
			}
		}
		ans1 = max(ans0,x[em]);
		int Q;
		cin >> Q;
		while (Q--)
		{
			int a;
			cin >> a;
			if (a)
			{
				cout << ans1 << '\n';
			}
			else
			{
				cout << ans0 << '\n';
			}
		}
	}
}