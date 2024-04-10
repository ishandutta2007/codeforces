#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXS = 1000000;
	int n, m, A[MAXS], V[MAXS], Fa[MAXS], F[MAXS];
	vector<int> G[MAXS];

	int find(int x)
	{
		if (Fa[x] != x)
			Fa[x] = find(Fa[x]);
		return Fa[x];
	}

	inline void add_edge(int u, int v) { G[v].push_back(u); }

	int f(int u)
	{
		int &ans = F[u];
		if (!ans)
		{
			ans = 1;
			for (int v : G[u])
				ans = max(ans, f(v) + 1);
		}
		return ans;
	}

	void work()
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &A[i * m + j]);
		for (int i = 0; i < n * m; i++)
			Fa[i] = i;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				V[j] = j;
			sort(V, V + m, [i](int j1, int j2){ return A[i * m + j1] < A[i * m + j2]; });
			for (int j = 1; j < m; j++)
				if (A[i * m + V[j - 1]] == A[i * m + V[j]])
					Fa[find(i * m + V[j])] = find(i * m + V[j - 1]);
		}
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
				V[i] = i;
			sort(V, V + n, [j](int i1, int i2){ return A[i1 * m + j] < A[i2 * m + j]; });
			for (int i = 1; i < n; i++)
				if (A[V[i - 1] * m + j] == A[V[i] * m + j])
					Fa[find(V[i] * m + j)] = find(V[i - 1] * m + j);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				V[j] = j;
			sort(V, V + m, [i](int j1, int j2){ return A[i * m + j1] < A[i * m + j2]; });
			for (int j = 1; j < m; j++)
				if (A[i * m + V[j - 1]] < A[i * m + V[j]])
					add_edge(find(i * m + V[j - 1]), find(i * m + V[j]));
		}
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
				V[i] = i;
			sort(V, V + n, [j](int i1, int i2){ return A[i1 * m + j] < A[i2 * m + j]; });
			for (int i = 1; i < n; i++)
				if (A[V[i - 1] * m + j] < A[V[i] * m + j])
					add_edge(find(V[i - 1] * m + j), find(V[i] * m + j));
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%d ", f(find(i * m + j)));
			putchar('\n');
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}