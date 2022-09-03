#include<cstdio>
#include<algorithm>

int a[222][222];
int v[222];

int dfs(int x,int y)
{
    if(x==221)return y;
    if(v[x])return 0;
    int i,t;
    v[x]=1;
    for(i=0;i<222;i++)if(a[x][i])
	{
		t=dfs(i,std::min(y,a[x][i]));
		if(t)
		{
            a[x][i]-=t;
            a[i][x]+=t;
            return t;
		}
	}
	return 0;
}

int main()
{
	int i,j,n,m,r=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[220][i]);
	for(i=0;i<n;i++)scanf("%d",&a[i+n][221]);
	for(i=0;i<n;i++)a[i][i+n]=1e9;
    while(m--)
	{
		scanf("%d%d",&i,&j);
		i--;j--;
        a[i][j+n]=a[j][i+n]=1e9;
	}
    while(dfs(220,1e9))for(i=0;i<222;i++)v[i]=0;
    for(i=0;i<n;i++)if(a[220][i]||a[i+n][221])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)printf("%d ",a[j+n][i]);
		puts("");
	}
}