#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int modulo=1000000007,MAXN=100000;

vector <int> G[MAXN];
bool black[MAXN];

long long onb[MAXN],nob[MAXN];

void dfs(int u,int fa)
{
	if (black[u])
	{
		onb[u]=1;
		for (int i=G[u].size()-1;i>=0;i--)
		{
			int v=G[u][i];
			if (v==fa) continue;
			dfs(v,u);
			onb[u]=onb[u]*(onb[v]+nob[v])%modulo;
		}
	}
	else 
	{
		nob[u]=1;
		for (int i=G[u].size()-1;i>=0;i--)
		{
			int v=G[u][i];
			if (v==fa) continue;
			dfs(v,u);
			onb[u]=(onb[u]*(nob[v]+onb[v])+nob[u]*onb[v])%modulo;
			nob[u]=nob[u]*(onb[v]+nob[v])%modulo;
		}
	}
}
int main()
{
	int n;
	memset(onb,0,sizeof(onb));
	memset(nob,0,sizeof(nob));
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		G[x].push_back(i);
		G[i].push_back(x);
	}
	for (int i=0;i<n;i++) scanf("%d",&black[i]);
	dfs(0,-1);
	printf("%I64d",onb[0]);
	return 0;
}