#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2000];
int N, M;
bool seen[2000];
void dfs(int x)
{
	if(!seen[x])
	{
		seen[x] = true;
		for(auto a: adj[x])
		{
			dfs(a);
		}
	}
}
int main()
{
	//freopen("infile.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	if(M+1==N)
	{
		for(int m=0; m<M; m++)
		{
			int A, B;
			scanf("%d %d", &A, &B);
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		dfs(1);
		for(int n=1; n<N; n++)
		{
			if(!seen[n])
			{
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}