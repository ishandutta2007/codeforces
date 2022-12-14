#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100;
const int NLet = 26;

int n, m;
int mat[MaxN + 1][MaxN + 1];

int f[MaxN + 1][MaxN + 1][NLet];

char out[MaxN + 2];

int dfs(int u, int v, int l)
{
	int &cur = f[u][v][l];
	if (cur != -1)
		return cur;

	cur = 0;
	for (int k = 1; k <= n; ++k)
		if (mat[u][k] >= l && !dfs(v, k, mat[u][k]))
		{
			cur = 1;
			break;
		}

	return cur;
}

int main()
{
	cin >> n >> m;

	for (int u = 1; u <= n; ++u)
		for (int v = 1; v <= n; ++v)
			mat[u][v] = -1;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		char w;
		scanf("%d %d %c", &u, &v, &w);

		mat[u][v] = w - 'a';
	}

	for (int u = 1; u <= n; ++u)
		for (int v = 1; v <= n; ++v)
			for (int l = 0; l < NLet; ++l)
				f[u][v][l] = -1;

	for (int u = 1; u <= n; ++u)
	{
		for (int v = 1; v <= n; ++v)
			out[v] = dfs(u, v, 0) ? 'A' : 'B';

		puts(out + 1);
	}

	return 0;
}