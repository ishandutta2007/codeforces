#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,x,y,i,j,k,l,b[105][105],a[105][105],d[105],f[105],g[105],h[105],ans[105];
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		b[j][k]=b[k][j]=1;
	}
	for(x=f[0]=1;x<=n;x++)
	{
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(b[i][j])a[i][j]=P-x;
		else a[i][j]=P-1;
		for(i=1;i<=n;i++)for(a[i][i]=0,j=1;j<=n;j++)if(i!=j)if(b[i][j])a[i][i]+=x;
		else a[i][i]++;
		for(i=y=1;i+1<n;i++)
		{
			for(j=i;j<n;j++)if(a[j][i])break;
			if(j!=i)for(y=P-y,k=i;k<n;k++)swap(a[i][k],a[j][k]);
			for(j=i+1,l=Pow(a[i][i],P-2);j<n;j++)for(k=n-1;k>=i;k--)a[j][k]=(a[j][k]-(ll)a[i][k]*a[j][i]%P*l%P+P)%P;
		}
		for(i=1;i<n;i++)y=(ll)y*a[i][i]%P;
		d[x]=y;
		for(i=x;i;i--)f[i]=(f[i-1]+(ll)(P-x)*f[i])%P;
		f[0]=(ll)(P-x)*f[0]%P;
	}
	for(x=1;x<=n;x++)
	{
		for(i=0;i<=n;i++)g[i]=f[i];
		for(i=n-1;~i;i--)
		{
			h[i]=g[i+1];
			g[i]=(g[i]+(ll)x*g[i+1])%P;
		}
		for(i=j=1;i<=n;i++)if(i!=x)j=(ll)j*(x-i+P)%P;
		j=(ll)d[x]*Pow(j,P-2)%P;
		for(i=0;i<n;i++)ans[i]=(ans[i]+(ll)h[i]*j)%P;
	}
	for(i=0;i<n;i++)cout<<ans[i]<<' ';
	return 0;
}