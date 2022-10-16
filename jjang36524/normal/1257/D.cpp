#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int str[200100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int i;
		for (i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		int m;
		cin >> m;
		vector<pair<int, int>>heroes;
		vector<int>pow;
		vector<int>en;
		for (i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			heroes.push_back({ -a,b });
		}
		sort(heroes.begin(), heroes.end());
		for (i = 0; i < m; i++)
		{
			if (i == 0 || en[en.size() - 1] < heroes[i].second)
			{
				pow.push_back(heroes[i].first);
				en.push_back(heroes[i].second);
			}
		}
		int pos = 0;
		int turn = 0;
		while (pos < n)
		{
			int start = 0;
			int ed = pow.size()-1;
			int oldstart = 0;
			int oldend = pow.size() - 1;
			int dayp = 1;
			while (ed>=start)
			{
				oldstart = start;
				oldend = ed;
				int res=upper_bound(pow.begin(), pow.end(), -str[pos+dayp-1]) - pow.begin();
				ed = min(ed, res-1);
				start = max(start, lower_bound(en.begin(), en.end(), dayp)-en.begin());
				dayp++;
			}
			if (dayp == 2)
			{
				cout << -1 << '\n';
				goto t;
			}
			pos += dayp - 2;
			turn++;
		}
		cout << turn << '\n';
	t:
		int d;
	}
}