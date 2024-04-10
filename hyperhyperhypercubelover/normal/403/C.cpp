#include<cstdio>

int a[2000][2000];
int v[2000];
int c[2000],cn;
int n;

void dfs(int x)
{
	if(v[x])return;
	int i;
	v[x]=1;
	for(i=0;i<n;i++)if(a[x][i])dfs(i);
	c[cn++]=x;
}

void dfs2(int x)
{
	if(!v[x])return;
	int i;
	v[x]=0;
	for(i=0;i<n;i++)if(a[i][x])dfs2(i);
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
	dfs(0);
    for(i=0;i<n;i++)if(!v[i])
	{
		puts("NO");
		return 0;
	}
    dfs2(c[cn-1]);
    for(i=0;i<n;i++)if(v[i])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
}