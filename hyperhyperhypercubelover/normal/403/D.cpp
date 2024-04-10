#include<cstdio>

int c[1051][1051];
int d[2][1001][1001];
int r[1001][1001];

const int mod = 1000000007;

int main()
{
    int i,j,k,n,m,t;
	for(i=1;i<=1050;i++)
	{
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
    for(j=0;j<=1000;j++)d[0][0][j]=1;
    for(k=1;k<50;k++)
	{
		for(i=1;i<=1000;i++)
		{
			for(j=1;j<=1000;j++)
			{
				d[k&1][i][j]=d[k&1][i][j-1];
				if(j<=i)(d[k&1][i][j]+=d[!(k&1)][i-j][j-1])%=mod;
			}
			for(j=i;j<=1000;j++)(r[j][k]+=1LL*d[k&1][i][i]*c[j-i+k][k]%mod)%=mod;
		}
		for(j=0;j<=1000;j++)d[k&1][0][j]=0;
	}
	for(j=1;j<=1000;j++)
	{
		k=1;
		for(i=1;i<50;i++)
		{
			k=1LL*k*i%mod;
            r[j][i]=1LL*r[j][i]*k%mod;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&i,&j);
        printf("%d\n",r[i][j]);
	}
}