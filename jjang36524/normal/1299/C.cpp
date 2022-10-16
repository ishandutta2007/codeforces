#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int N;
vector<pair<int, int>>t;
vector<pair<int, int>>ne;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		t.push_back({ a,1 });
	}
	while (1)
	{
		for (i = 0; i < t.size();)
		{
			int nowaver = t[i].first;
			int sum = t[i].second;
			i++;
			while (i<t.size()&&(t[i].first * sum) <= (nowaver * t[i].second))
			{
				nowaver += t[i].first;
				sum += t[i].second;
				i++;
			}
			ne.push_back({ nowaver,sum });
		}
		if (t == ne)
			break;
		t = ne;
		ne.clear();
	}
	cout.precision(15);
	for (i = 0; i < ne.size(); i++)
	{
		int j;
		for (j = 0; j < ne[i].second; j++)
		{
			cout << (double)ne[i].first / ne[i].second << '\n';
		}
	}
}