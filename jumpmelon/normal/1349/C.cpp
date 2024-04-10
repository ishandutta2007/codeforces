#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	struct pa
	{
		int x, y;
	};

	const int MAXN = 1000, MAXM = 1000;
	const int DC = 4, DX[DC] = {0, 0, -1, 1}, DY[DC] = {-1, 1, 0, 0};
	char M[MAXN][MAXM + 1];
	int n, m, Dis[MAXN][MAXM];
	pa Q[MAXN * MAXM];

	void work()
	{
		int q;
		pa *h = Q, *t = Q;
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", M[i]);
			memset(Dis[i], -1, sizeof(int[m]));
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int d = 0; d < DC; d++)
				{
					int x = i + DX[d], y = j + DY[d];
					if (0 <= x && x < n && 0 <= y && y < m && M[x][y] == M[i][j])
					{
						Dis[i][j] = 0;
						*t++ = {i, j};
						break;
					}
				}
		while (h < t)
		{
			pa u = *h++;
			for (int d = 0; d < DC; d++)
			{
				int x = u.x + DX[d], y = u.y + DY[d];
				if (0 <= x && x < n && 0 <= y && y < m && Dis[x][y] == -1)
				{
					Dis[x][y] = Dis[u.x][u.y] + 1;
					*t++ = {x, y};
				}
			}
		}
		while (q--)
		{
			int i, j;
			big p;
			scanf("%d%d%lld", &i, &j, &p);
			i--;
			j--;
			if (Dis[i][j] == -1 || p < Dis[i][j])
				printf("%d\n", M[i][j] - '0');
			else
				printf("%d\n", (M[i][j] - '0') ^ int((p - Dis[i][j]) & 1));
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}