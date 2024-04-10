#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 150000;
	int Next[MAXN + 1], Fa[MAXN + 1], V[MAXN + 1];

	int find(int x)
	{
		if (Fa[x] != x)
			Fa[x] = find(Fa[x]);
		return Fa[x];
	}

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			Fa[i] = V[i] = i;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x = find(x);
			y = find(y);
			Next[V[x]] = y;
			Fa[y] = x;
			V[x] = V[y];
		}
		for (int x = find(1); x; x = Next[x])
			printf("%d ", x);
		putchar('\n');
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}