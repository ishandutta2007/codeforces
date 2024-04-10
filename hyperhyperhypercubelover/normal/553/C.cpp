#include<cstdio>
#include<vector>

std::vector<std::pair<int,int> > g[111111];
int v[111111];

int dfs(int x,int y)
{
	if(v[x])
	{
		if(v[x]!=y)return 1;
		return 0;
	}
	int i;
	v[x]=y;
	for(i=0;i<g[x].size();i++)if(dfs(g[x][i].first,y^g[x][i].second))return 1;
	return 0;
}

int main()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
    while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		g[i].push_back(std::make_pair(j,1-k));
		g[j].push_back(std::make_pair(i,1-k));
	}
	j=500000004;
	for(i=1;i<=n;i++)if(!v[i])
	{
		if(dfs(i,2))j=0;
		else j=2*j%1000000007;
	}
	printf("%d",j);
}