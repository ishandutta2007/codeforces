#include<cstdio>
#include<algorithm>

int a[30001];
int d[30001][501];

int main()
{
	int r=0;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d",&i);
		a[i]++;
	}
	for(i=0;i<=30000;i++)for(j=0;j<=500;j++)d[i][j]=-1e9;
    d[m][250]=0;
    for(i=0;i<=30000;i++)for(j=0;j<=500;j++)
	{
        d[i][j]+=a[i];
        r=std::max(r,d[i][j]);
        if(m+j-250>0&&i+m+j-250<=30000)d[i+m+j-250][j]=std::max(d[i+m+j-250][j],d[i][j]);
        if(j>0&&m+j-251>0&&i+m+j-251<=30000)d[i+m+j-251][j-1]=std::max(d[i+m+j-251][j-1],d[i][j]);
        if(j<500&&m+j-249>0&&i+m+j-249<=30000)d[i+m+j-249][j+1]=std::max(d[i+m+j-249][j+1],d[i][j]);
	}
	printf("%d",r);
}