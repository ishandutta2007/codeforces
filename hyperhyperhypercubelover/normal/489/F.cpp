#include<cstdio>

char a[500][501];
int d[2][503][503];
int t[500];

int main()
{
	int x,y,z;
	int i,j,k,n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<m;i++)
	{
		scanf("%s",a[i]);
        for(j=0;j<n;j++)t[j]+=a[i][j]-'0';
	}
	x=y=z=0;
    for(j=0;j<n;j++)
	{
		if(t[j]>2)
		{
			puts("0");
			return 0;
		}
		if(t[j]==1)x++;
		if(t[j]==2)y++;
	}
	d[m&1][x][y]=1;
	for(i=m;i<n;i++)
	{
		for(j=0;j<=n;j++)for(k=0;k<=n-j;k++)d[!(i&1)][j][k]=0;
        for(j=0;j<=n;j++)for(k=0;k<=n-j;k++)if(d[i&1][j][k])
		{
			(d[!(i&1)][j+2][k]+=1LL*d[i&1][j][k]*(n-j-k)*(n-j-k-1)/2%p)%=p;
			(d[!(i&1)][j][k+1]+=1LL*d[i&1][j][k]*(n-j-k)*j%p)%=p;
			if(j>=2)(d[!(i&1)][j-2][k+2]+=1LL*d[i&1][j][k]*j*(j-1)/2%p)%=p;
		}
	}
	printf("%d",d[n&1][0][n]);
}