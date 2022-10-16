#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int mi[100100][51];
int vis[100100][51];
vector<pair<int, int>>l[100100];
priority_queue<pair<int, pair<int, int>>>x;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N>>M;
	x.push({ 0,{1,0} });
	int i;
	for (i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		l[a].push_back({ b,c });
		l[b].push_back({ a,c });
	}
	memset(mi, 60, sizeof(mi));
	mi[1][0] = 0;
	while (x.size())
	{
		auto n = x.top();
		x.pop();
		if (vis[n.second.first][n.second.second])
			continue;
		vis[n.second.first][n.second.second] = 1;
		int j;
		for (j = 0; j < l[n.second.first].size(); j++)
		{
			auto nextp = l[n.second.first][j];
			if (n.second.second)
			{
				if (mi[nextp.first][0] >-n.first+ (nextp.second + n.second.second) * (nextp.second + n.second.second))
				{
					mi[nextp.first][0] = -n.first+(nextp.second + n.second.second) * (nextp.second + n.second.second);
					x.push({ -mi[nextp.first][0],{nextp.first,0} });
				}
			}
			else
			{
				if (mi[nextp.first][nextp.second] > -n.first)
				{
					mi[nextp.first][nextp.second] = -n.first;
					x.push({ -mi[nextp.first][nextp.second],{nextp.first,nextp.second} });
				}
			}
		}
	}
	for (i = 1; i <= N; i++)
	{
		cout << (mi[i][0] > 1000000000 ? -1 : mi[i][0])<<' ';
	}
}