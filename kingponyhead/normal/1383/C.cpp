// What's the point of it anyway?
#include<bits/stdc++.h>
using namespace std;
const int N = 100005, SGM = 20;
int n, q, M[SGM], Nxt[SGM];
char A[N], B[N];
vector < int > Adj[SGM];
bool dp[1 << SGM];
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
			M[i] = Nxt[i] = 0, Adj[i].clear();
		for (int i = 0; i < n; i ++)
		{
			A[i] -= 'a';
			B[i] -= 'a';
			if (A[i] == B[i])
				continue;
			Nxt[A[i]] |= 1 << B[i];
			Adj[A[i]].push_back(B[i]),
			Adj[B[i]].push_back(A[i]);
		}
		int c = 0;
		for (int i = 0; i < SGM; i ++)
			if (!M[i]) DFS(i), c ++;

		dp[0] = 1;
		int Mx = 0;
		for (int mask = 1; mask < (1 << SGM); mask ++)
		{
			dp[mask] = 0;
			for (int v = 0; v < SGM; v ++)
				if (mask >> v & 1)
					if ((Nxt[v] & mask) == 0)
						dp[mask] |= dp[mask ^ (1 << v)];
			if (dp[mask])
				Mx = max(Mx, __builtin_popcount(mask));
		}
		printf("%d\n", SGM * 2 - c - Mx);
	}
	return 0;
}