#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#define int long long
using namespace std;
vector<int>arr[200010];
signed main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}
	pair<double, int>ans = { 0,0 };
	for (i = 1; i <= 20; i++)
	{
		vector<double>t;
		int j;
		for (j = 1; j <= 200000; j++)
		{
			double c = 0;
			int k;
			for (k = 0; k < arr[j].size(); k++)
			{
				c += min((double)arr[j][k] / i, 1.0);
			}
			t.push_back(c);
		}
		sort(t.begin(), t.end());
		double an = 0;
		while (t.size() > 200000 - i)
		{
			an += t.back();
			t.pop_back();
		}
		ans = max(ans, { an,i });
	}
	vector<double>t;
	int j;
	for (j = 1; j <= 200000; j++)
	{
		double c = 0;
		int k;
		for (k = 0; k < arr[j].size(); k++)
		{
			c += arr[j][k];
		}
		t.push_back(c);
	}
	sort(t.begin(), t.end());
	double an = 0;
	i = 0;
	while (t.size())
	{
		i++;
		an += t.back();
		if(i>200000)
			ans = max(ans, { an/i,i });
		t.pop_back();
	}
	cout << ans.second << '\n';
	{
		vector<pair<double,int>>t;
		int j;
		for (j = 1; j <= 200000; j++)
		{
			double c = 0;
			int k;
			for (k = 0; k < arr[j].size(); k++)
			{
				c += min((double)arr[j][k]/ans.second,1.0);
			}
			t.push_back({ c,j });
		}
		sort(t.begin(), t.end());
		while (t.size()>200000-ans.second)
		{
			cout << t.back().second << ' ';
			t.pop_back();
		}
	}
	
}