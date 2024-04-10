#include<cstdio>
#include<vector>
#include<algorithm>

int a[2000][2000];
int v[2000][2000];
std::pair<int,std::pair<int,int> > d[2000000];
int dn;

std::vector<std::pair<int,int> > g[2000];

int p[2000];

int f(int x){return p[x]==x?x:p[x]=f(p[x]);}

void dfs(int x,int y,int z)
{
	if(v[x][y])return;
    v[x][y]=1;
    a[x][y]=z;
    int i;
    for(i=0;i<g[y].size();i++)dfs(x,g[y][i].first,z+g[y][i].second);
}

int main()
{
	int i,j,t,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	{
		scanf("%d",&t);
		if(i==j&&t)
		{
			puts("NO");
			return 0;
		}
		if(i!=j&&t==0)
		{
			puts("NO");
			return 0;
		}
        if(i<j)
		{
			d[dn].first=t;
			d[dn].second.first=i;
			d[dn].second.second=j;
			dn++;
		}
	}
	std::sort(d,d+dn);
	for(i=0;i<n;i++)p[i]=i;
	for(i=0;i<dn;i++)if(f(d[i].second.first)!=f(d[i].second.second))
	{
		p[f(d[i].second.first)]=f(d[i].second.second);
        g[d[i].second.first].push_back(std::make_pair(d[i].second.second,d[i].first));
        g[d[i].second.second].push_back(std::make_pair(d[i].second.first,d[i].first));
	}
	for(i=0;i<n;i++)dfs(i,i,0);
    for(i=0;i<dn;i++)if(a[d[i].second.first][d[i].second.second]!=d[i].first)break;
    puts(i<dn?"NO":"YES");
}