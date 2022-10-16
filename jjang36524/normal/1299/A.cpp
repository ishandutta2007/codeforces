#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, T;
vector<pair<int, int>>graph[500100];
vector<int>t[30];
int a[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		int j;
		for (j = 0; j < 30; j++)
		{
			if (a[i] & (1 << j))
				t[j].push_back(i);
		}
	}
	vector < pair<int, int>>fina;
	for (i = 0; i < 30; i++)
	{
		if (t[i].size() == 1)
			fina.push_back({ -i,t[i][0] });
	}
	sort(fina.begin(), fina.end());
	int us = -1;
	if (fina.size() != 0)
	{
		cout << a[fina[0].second] << ' ';
		us = fina[0].second;
	}
	for (i = 0; i < N; i++)
	{
		if (i != us)
			cout << a[i] << ' ';
	}
}