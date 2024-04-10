#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 125000, K = 6;
	int n, m, A[K + 10], Ans[MAXN + 10], Next[MAXN + 10];
	char S[MAXN + 10], T[MAXN + 10];

	void get_next()
	{
		int i = 0, j = -1;
		Next[0] = -1;
		while(i < m)
		{
			while(j != -1 && A[T[i] - 'a'] != A[T[j] - 'a'])
				j = Next[j];
			Next[++i] = ++j;
		}
	}

	void check(int x)
	{
		int i = 0, j = 0;
		get_next();
		while(i < n)
		{
			while(j != -1 && A[S[i] - 'a'] != A[T[j] - 'a'])
				j = Next[j];
			i++;
			if(++j >= m)
			{
				if(x < Ans[i])
					Ans[i] = x;
				j = Next[j];
			}
		}
	}

	void dfs(int i, int t)
	{
		if(i >= K)
			check(K - t);
		else
		{
			for(A[i] = 0; A[i] < t; A[i]++)
				dfs(i + 1, t);
			dfs(i + 1, t + 1);
		}
	}

	void work()
	{
		scanf("%s%s", S, T);
		n = strlen(S);
		m = strlen(T);
		for(int i = m; i <= n; i++)
			Ans[i] = K;
		dfs(0, 0);
		for(int i = m; i <= n; i++)
			printf("%d ", Ans[i]);
		putchar('\n');
	}
}

int main()
{
	program::work();
	return 0;
}