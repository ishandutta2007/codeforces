#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<int>x;
vector<pair<int,int>>p;
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		p.clear();
		x.clear();
		int N;
		cin >> N;
		int s = 0;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.insert(a);
			s += a;
		}
		int ss = s;
		int c = 1;
		p.push_back({ ss,1 });
		int cp = 0;
		while (cp < p.size())
		{
			while (x.count(p[cp].first)&&p[cp].second)
			{
				p[cp].second--;
				x.erase(x.lower_bound(p[cp].first));
			}
			if (p[cp].first == 1)
				goto T;
			if (p[cp].second == 0)
				goto T;
			if (p.back().first == (p[cp].first + 1) / 2)
				p[p.size() - 1].second += p[cp].second;
			else
				p.push_back({ (p[cp].first + 1) / 2 ,p[cp].second });
			if (p.back().first == (p[cp].first) / 2)
				p[p.size() - 1].second += p[cp].second;
			else
				p.push_back({ (p[cp].first) / 2 ,p[cp].second });
			T:
			cp++;
		}
		if (x.size())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}