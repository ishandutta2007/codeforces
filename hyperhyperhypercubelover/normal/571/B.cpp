#include<cstdio>
#include<algorithm>

int a[333333];
long long d[5005][5005];

int main()
{
	int i,j,n,m,t;
	scanf("%d%d",&n,&m);
	t=n/m;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    std::sort(a,a+n);
    for(i=0;i<=m;i++)for(j=0;j<=m;j++)d[i][j]=9e18;
    d[0][0]=0;
    for(i=1;i<=m;i++)for(j=0;j<=m;j++)
	{
		d[i][j]=d[i-1][j]+std::abs(a[t*i+j-1]-a[t*i+j-t]);
		if(j)d[i][j]=std::min(d[i][j],d[i-1][j-1]+std::abs(a[t*i+j-1]-a[t*i+j-t-1]));
	}
	printf("%I64d",d[m][n%m]);
}