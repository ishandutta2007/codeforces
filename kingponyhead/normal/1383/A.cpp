// What's the point of it anyway?
#include<bits/stdc++.h>
using namespace std;
const int N = 100005, SGM = 20;
int n, q, M[SGM];
char A[N], B[N];
vector < int > Adj[SGM];
void DFS(int v)
{
	M[v] = 1;
	for (int u : Adj[v])
		if (!M[u]) DFS(u);
}
int main()
{
	scanf("%d", &q);
	for (; q; q --)
	{
		scanf("%d%s%s", &n, A, B);
		for (int i = 0; i < SGM; i ++)
			M[i] = 0, Adj[i].clear();
		bool Fail = 0;
		for (int i = 0; i < n; i ++)
		{
			A[i] -= 'a';
			B[i] -= 'a';
			if (A[i] > B[i])
				Fail = 1;
			else
				Adj[A[i]].push_back(B[i]),
				Adj[B[i]].push_back(A[i]);
		}
		if (Fail)
			{printf("-1\n"); continue;}
		int c = 0;
		for (int i = 0; i < SGM; i ++)
			if (!M[i]) DFS(i), c ++;
		printf("%d\n", SGM - c);
	}
	return 0;
}