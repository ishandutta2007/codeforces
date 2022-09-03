#include<cstdio>

int a[200];
int d[202][202];
int v[202];
int r[202][202];
int s[202][202];
int sn[202];
int snn;

int f(int x)
{
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}

int find(int x)
{
	if(x==201)return 1;
	if(v[x])return 0;
	int i;
	v[x]=1;
	for(i=1;i<=201;i++)if(d[x][i]&&find(i))
	{
		d[x][i]--;
		d[i][x]++;
		return 1;
	}
	return 0;
}

void dfs(int x)
{
    if(v[x])return;
    int i;
    v[x]=1;
    s[snn][sn[snn]++]=x;
	for(i=1;i<=200;i++)if(r[x][i])dfs(i);
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
        if(a[i]%2)d[0][i]=2;
		else d[i][201]=2;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]%2&&a[j]%2==0&&f(a[i]+a[j]))d[i][j]=1;
    for(i=0;find(0);i++)for(j=0;j<=201;j++)v[j]=0;
    if(i<n)
	{
		puts("Impossible");
		return 0;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]%2&&a[j]%2==0&&f(a[i]+a[j])&&!d[i][j])r[i][j]=r[j][i]=1;
	for(i=1;i<=n;i++)v[i]=0;
	for(i=1;i<=n;i++)if(!v[i])
	{
		dfs(i);
		snn++;
	}
	printf("%d\n",snn);
	for(i=0;i<snn;i++)
	{
		printf("%d ",sn[i]);
		for(j=0;j<sn[i];j++)printf("%d ",s[i][j]);
		puts("");
	}
}