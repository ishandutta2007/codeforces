#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 1000;
	char M[MAXN][MAXN + 1];
	int Fa[MAXN << 1], F[MAXN << 1];
	vector<int> G[MAXN << 1];

	int find(int x)
	{
		if (Fa[x] != x)
			Fa[x] = find(Fa[x]);
		return Fa[x];
	}

	int f(int u)
	{
		int &ans = F[u];
		if (ans == -1)
		{
			puts("No");
			exit(0);
		}
		else if (ans == 0)
		{
			int mx = 0;
			ans = -1;
			for (int v : G[u])
				mx = max(mx, f(v));
			ans = mx + 1;
		}
		return ans;
	}

	void work()
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", M[i]);
		for (int i = 0; i < n + m; i++)
			Fa[i] = i;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] == '=')
					Fa[find(i)] = find(n + j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] == '>')
					G[find(i)].push_back(find(n + j));
				else if (M[i][j] == '<')
					G[find(n + j)].push_back(find(i));
		for (int i = 0; i < n + m; i++)
			if (Fa[i] == i)
				f(i);
		puts("Yes");
		for (int i = 0; i < n; i++)
			printf("%d ", F[find(i)]);
		putchar('\n');
		for (int j = 0; j < m; j++)
			printf("%d ", F[find(n + j)]);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}