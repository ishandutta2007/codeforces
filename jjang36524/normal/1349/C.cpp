#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
int N,M,T;
int col[1010][1010];
long long tim[1010][1010];
int dx[4] = { 1,0,-1 };
int dy[] = { 0,1,0,-1 };
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M>>T;
	int i, j;
	memset(col, 1, sizeof(col));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			char c;
			cin >> c;
			col[i][j] = c - '0';
		}
	}
	memset(tim, 60, sizeof(tim));
	queue<pair<int, int>>love;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			int k;
			for (k = 0; k < 4; k++)
			{
				if (col[i + dx[k]][j + dy[k]] == col[i][j])
				{
					tim[i][j] = 1;
					love.push({ i,j });
					break;
				}
			}
		}
	}
	while (love.size())
	{
		auto now = love.front();
		love.pop();
		int k;
		i = now.first;
		j = now.second;
		if (i <= 0 || j <= 0 || i > N || j > M)
			continue;
		for (k = 0; k < 4; k++)
		{
			if ((col[i + dx[k]][j + dy[k]] != col[i][j])&&(tim[i + dx[k]][j + dy[k]]>=(1LL<<30)))
			{
				tim[i+dx[k]][j+dy[k]] = tim[i][j]+1;
				love.push({ i+dx[k],j+dy[k] });
			}
		}
	}
	while (T--)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (c < tim[a][b])
		{
			cout << col[a][b] << '\n';
		}
		else
		{
			int ans = (col[a][b]+1 + (c - tim[a][b]) % 2)%2;
			cout << ans << '\n';
		}
	}
}