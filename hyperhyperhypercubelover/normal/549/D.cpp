#include<cstdio>

char a[111][111];
int d[111][111];

int main()
{
	int i,j,n,m,r=0;
	scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=n-1;i>=0;i--)for(j=m-1;j>=0;j--)
	{
		d[i][j]+=d[i+1][j]+d[i][j+1]-d[i+1][j+1];
		if(a[i][j]=='W')a[i][j]=1;
		if(a[i][j]=='B')a[i][j]=-1;
		if(d[i][j]!=a[i][j])
		{
			r++;
            d[i][j]=a[i][j];
		}
	}
	printf("%d",r);
}