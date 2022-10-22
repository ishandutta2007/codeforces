#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXV = 1000000, INF = 0x3f3f3f3f;
	char S[MAXV + 1];
	int n, m, T0[MAXV], T1[MAXV], Dis[MAXV], *Q0, *Q1, *h0, *t0, *t1;

	void BFS(int *&t, int w, char ch)
	{
		while (h0 < t0)
		{
			int u = *h0++, x = u / m, y = u % m;
			for (int dx = -1; dx <= 1; dx++)
				for (int dy = -1; dy <= 1; dy++)
				{
					int xx = x + dx, yy = y + dy;
					if (0 <= xx && xx < n && 0 <= yy && yy < m && (S[xx * m + yy] == ch || (S[xx * m + yy] != '$' && dx >= 0 && dy <= 0)) && Dis[xx * m + yy] == INF)
						Dis[*t++ = xx * m + yy] = Dis[u] + w;
				}
		}
	}

	void work()
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", S + i * m);
		S[0] = S[n * m - 1] = '$';
		memset(Dis, INF, sizeof(int[n * m]));
		h0 = t0 = Q0 = T0;
		t1 = Q1 = T1;
		for (int i = 1; i < n; i++)
			if (S[i * m] == '#')
				Dis[*t0++ = i * m] = 0;
		for (int i = 1; i < m; i++)
			if (S[(n - 1) * m + i] == '#')
				Dis[*t0++ = (n - 1) * m + i] = 0;
		BFS(t0, 0, '#');
		for (int i = 1; i < n; i++)
			if (S[i * m] == '.')
				Dis[*t1++ = i * m] = 1;
		for (int i = 1; i < m; i++)
			if (S[(n - 1) * m + i] == '.')
				Dis[*t1++ = (n - 1) * m + i] = 1;
		h0 = Q0;
		BFS(t1, 1, '.');
		while (Q1 < t1)
		{
			swap(Q0, Q1);
			h0 = Q0;
			t0 = t1;
			BFS(t0, 0, '#');
			h0 = Q0;
			t1 = Q1;
			BFS(t1, 1, '.');
		}
		int ans = INF;
		for (int i = 1; i < m; i++)
			ans = min(ans, Dis[i]);
		for (int i = 1; i < n; i++)
			ans = min(ans, Dis[i * m + m - 1]);
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}