#include<cstdio>
#include<vector>

std::vector<int> g[222222];
int d[222222];

int dfs(int x)
{
    if(g[x].empty())return d[x]=1;
    int i;
    for(i=0;i<g[x].size();i++)d[x]+=dfs(g[x][i]);
    return d[x];
}

int dfs1(int x,int y)
{
    if(g[x].empty())return 1;
    int i,r;
    if(y==0)
	{
		r=0;
		for(i=0;i<g[x].size();i++)r=std::max(r,d[x]-d[g[x][i]]+dfs1(g[x][i],1));
		return r;
	}
	r=d[x]+1;
	for(i=0;i<g[x].size();i++)r-=d[g[x][i]]-dfs1(g[x][i],0)+1;
	return r;
}

int dfs2(int x,int y)
{
    if(g[x].empty())return 1;
    int i,r;
    if(y==0)
	{
		r=0;
		for(i=0;i<g[x].size();i++)r+=dfs2(g[x][i],1);
		return r;
	}
	r=987654321;
	for(i=0;i<g[x].size();i++)r=std::min(r,dfs2(g[x][i],0));
	return r;
}

int main()
{
	int a,b;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
	}
	dfs(1);
	printf("%d %d",dfs1(1,0),dfs2(1,0));
}