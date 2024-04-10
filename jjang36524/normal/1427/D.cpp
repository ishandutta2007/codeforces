#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
vector<vector<int>>t;
int arr[60];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	int i;
	vector<pair<pair<int, int>,int>>co;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	for (i = 0; i < N; )
	{
		int ta = arr[i];
		int o = i;
		for (; arr[i] == ta; i++)
			ta++;
		co.push_back({ {arr[o],ta},o });
	}
	while (co.size() != 1)
	{
		sort(co.begin(), co.end());
		int j;
		vector<int>ch;
		for (i = 1; i < co.size(); i++)
		{
			if (co[i-1].second > co[i].second)
			{
				if (co[i].second != 0)
					ch.push_back(co[i].second);
				ch.push_back(co[i - 1].second - co[i].second);
				ch.push_back(co[i - 1].first.second - co[i - 1].first.first);
				int e = co[i - 1].first.second - co[i - 1].first.first+co[i-1].second;
				if (e != N)
					ch.push_back(N - e);
				break;
			}
			
		}
		t.push_back(ch);
		vector<int>s;
		for (i = 0; i < ch.size(); i++)
		{
			if (i)
			{
				s.push_back(ch[i - 1] + s[i - 1]);
			}
			else
			{
				s.push_back(0);
			}
		}
		s.push_back(N);
		int narr[53];
		for (i = 0; i < ch.size(); i++)
		{
			int j;
			for (j = 0; j < ch[i]; j++)
			{
				narr[j + N - s[i + 1]] = arr[j + s[i]];
			}
		}
		for (i = 0; i < N; i++)
		{
			arr[i] = narr[i];
		}
		co.clear();
		for (i = 0; i < N; )
		{
			int ta = arr[i];
			int o = i;
			for (; arr[i] == ta; i++)
				ta++;
			co.push_back({ {arr[o],ta},o });
		}
	}
	cout << t.size() << '\n';
	for (i = 0; i < t.size(); i++)
	{
		cout << t[i].size() << ' ';
		int j;
		for (j = 0; j < t[i].size(); j++)
		{
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
}