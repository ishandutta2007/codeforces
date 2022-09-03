#include<cstdio>
#include<vector>

int a[201];
std::vector<int> b[201];
int v[201];
int n;

int ended()
{
	int i;
	for(i=1;i<=n;i++)if(!v[i])return 0;
	return 1;
}

int ok(int x)
{
	int i;
	for(i=0;i<b[x].size();i++)if(!v[b[x][i]])return 0;
	return 1;
}

int main()
{
	int ans=2e9;
	int i,j,k,l,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&k);
			b[i].push_back(k);
		}
	}
	for(i=1;i<=3;i++)
	{
		for(k=1;k<=n;k++)v[k]=0;
		for(j=0;!ended();j++)for(l=1;l<=n;l++)for(k=1;k<=n;k++)if(a[k]==(i+j)%3+1&&!v[k]&&ok(k))v[k]=1;
        if(j-1<ans)ans=j-1;
	}
	printf("%d",ans+n);
}