#include<cstdio>
#include<vector>

std::vector<int> a[100001];
std::vector<int> b[100001];
int c[100001];
int d[100001],dn;
int r[100001];
int v[100001],vn;

void dfs(int x,int y)
{
	if(v[x])return;
    v[x]=1;
    c[x]=y;
    int i;
    for(i=0;i<b[x].size();i++)dfs(b[x][i],y);
}

void dfs2(int x)
{
	if(!v[x])return;
    v[x]=0;
    int i;
    for(i=0;i<a[x].size();i++)dfs2(a[x][i]);
	d[x]=++dn;
}

int main()
{
	int ans=0;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		a[i].push_back(j);
		b[i].push_back(j);
		b[j].push_back(i);
	}
	ans=n;
	for(i=1;i<=n;i++)if(!v[i])
	{
		ans--;
		dfs(i,i);
	}
    for(i=1;i<=n;i++)dfs2(i);
    for(i=1;i<=n;i++)for(j=0;j<a[i].size();j++)if(d[a[i][j]]>d[i])r[c[i]]=1;
    for(i=1;i<=n;i++)ans+=r[i];
	printf("%d",ans);
}