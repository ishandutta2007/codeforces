#include<cstdio>

int a[111111][33];
int d[111111][33];

int l[111111];
int r[111111];
int x[111111];

int main()
{
	int t;
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&x[i]);
		for(t=0;t<32;t++)if((x[i]>>t)&1)
		{
            a[l[i]][t]++;
            a[r[i]+1][t]--;
		}
	}
	for(i=1;i<=n;i++)for(j=0;j<32;j++)
	{
		a[i][j]+=a[i-1][j];
		d[i][j]+=d[i-1][j];
        if(a[i][j])d[i][j]++;
	}
    for(i=1;i<=m;i++)
	{
		for(t=0;t<32;t++)if(((x[i]>>t)&1)==0&&d[r[i]][t]-d[l[i]-1][t]==r[i]-l[i]+1)break;
		if(t<32)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(i=1;i<=n;i++)
	{
		j=0;
		for(t=0;t<32;t++)if(a[i][t])j|=(1<<t);
		printf("%d ",j);
	}
}