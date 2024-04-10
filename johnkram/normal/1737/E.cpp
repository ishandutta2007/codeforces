#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define P 1000000007
int t,n,i,j,x[MAXN],y[MAXN],f[MAXN],g[MAXN];
int main()
{
	for(i=x[0]=1,j=2;i<MAXN;i++)x[i]=(ll)x[i-1]*j%P;
	for(i=y[0]=1,j=P+1>>1;i<MAXN;i++)y[i]=(ll)y[i-1]*j%P;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(g[n+1]=0,i=n;i<<1>n;i--)
		{
			f[i]=1;
			g[i]=(g[i+1]+(ll)f[i]*y[i])%P;
		}
		for(;i;i--)
		{
			f[i]=((ll)g[i+1]-g[i<<1]+P)*x[i]%P;
			g[i]=(g[i+1]+(ll)f[i]*y[i])%P;
		}
		for(i=1;i<n;i++)printf("%d\n",(ll)y[i+1>>1]*f[i]%P);
		printf("%d\n",y[n-1>>1]);
	}
	return 0;
}