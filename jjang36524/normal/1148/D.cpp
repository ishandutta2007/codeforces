#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<pair<int,int>, int>>x;
vector<pair<pair<int,int>, int>>y;
signed main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
			continue;
		if (a > b)
			x.push_back({ { b,a },i + 1 });
		else
			y.push_back({ { b,a },i + 1 });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (x.size() > y.size())
	{
		cout << x.size() << '\n';
		int i;
		for (i = 0; i < x.size(); i++)
		{
			cout << x[i].second << ' ';
		}
	}
	else
	{
		cout << y.size() << '\n';
		int i;
		for (i = 0; i < y.size(); i++)
		{
			cout << y[y.size()-1-i].second << ' ';
		}
	}
}