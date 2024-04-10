#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int INF = 200000000;

int d[3][1005][1005];
char m[1005][1005];
int r, c, a(INF);

bool inbounds(int x, int y)
{
	return (x >= 0 && x < r && y >= 0 && y < c);
}

void djk(int z)
{
	priority_queue<pair<int, pair<int, int> > > pq;
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
		if (m[i][j] == '1'+z)
			pq.emplace(0, make_pair(i, j));
		else
			d[z][i][j] = INF;
	while (!pq.empty())
	{
		auto u(pq.top()); pq.pop();
		int x = u.second.first, y = u.second.second;
		if (d[z][x][y]+u.first) continue;
		for (int i = 0;i < 4;i++) if (inbounds(x+dx[i], y+dy[i]) && m[x+dx[i]][y+dy[i]] != '#')
		{
			int alt = d[z][x][y];
			if (m[x+dx[i]][y+dy[i]] == '.') alt++;
			if (alt < d[z][x+dx[i]][y+dy[i]])
				pq.emplace(-(d[z][x+dx[i]][y+dy[i]]=alt), make_pair(x+dx[i], y+dy[i]));
		}
	}
}

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++)
		scanf("%s", m[i]);
	for (int i = 0;i < 3;i++)
		djk(i);
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++) if (m[i][j] != '#')
	{
		int alt = d[0][i][j]+d[1][i][j]+d[2][i][j];
		if (m[i][j] == '.') alt -= 2;
		if (alt < a) a = alt;
	}
	if (a != INF)
		printf("%d\n", a);
	else
		printf("-1\n");
	return 0;
}