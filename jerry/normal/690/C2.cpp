#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int N, M;
bool seen[100005];
int depth[100005];
int deepest, ind;
void reset()
{
	for(int n=0; n<100005; n++)
	{
		seen[n] =false;
		depth[n] = 0;
	}
	deepest = 0;
	ind = 1;
}
bool dfs(int x, int p)
{
	if(!seen[x])
	{
		depth[x] = depth[p]+1;
		if(deepest< depth[x])
		{
			deepest = depth[x];
			ind = x;
		}
		seen[x] = true;
		for(auto a: adj[x])
		{
			dfs(a, x);
		}
		return true;
	}
	return false;
}
int main()
{
	//freopen("infile.txt", "r", stdin);
	scanf("%d %d", &N, &M);
		for(int m=0; m<M; m++)
		{
			int A, B;
			scanf("%d %d", &A, &B);
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		dfs(1, 0);
		int root = ind;
		reset();
		dfs(root, 0);
		printf("%d\n", deepest-1);
}