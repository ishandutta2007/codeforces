#include<cstdio>

const int mod = 1000000007;

int a[1111];
int c[1111][1111];
int d[1111];


int main()
{
	int i,j,n,s=0,t,r=1;
	for(i=0;i<1111;i++)
	{
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	d[0]=1;
	for(i=1;i<=n;i++)
	{
        s+=a[i];
        d[i]=1LL*d[i-1]*c[s-1][a[i]-1]%mod;
	}
	printf("%d",d[n]);
}