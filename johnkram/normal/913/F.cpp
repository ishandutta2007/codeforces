#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
int Pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
	return s;
}
int n,i,j,k,a,b,p,f[2005][2005],d[2005],g,h[2005],x[2005],y[2005],z[2005],ans[2005];
int main()
{
	cin>>n>>a>>b;
	p=(ll)a*Pow(b,P-2)%P;
	g=(ll)p*Pow(P+1-p,P-2)%P;
	p=(P+1-p)%P;
	for(h[0]=i=1;i<=n;i++)h[i]=(ll)h[i-1]*g%P;
	for(x[0]=i=1;i<=n;i++)x[i]=(ll)x[i-1]*p%P;
	for(i=0;i<=n;i++)f[0][i]=1;
	for(i=1;i<=n;i++)for(j=i;j<=n;j++)f[i][j]=(f[i][j-1]+(ll)f[i-1][j-1]*h[j])%P;
	for(i=d[0]=y[0]=1;i<=n;i++)
	{
		for(j=d[i]=1,k=x[i];j<i;j++,k=(ll)k*x[i]%P)
		{
			d[i]=(d[i]-(ll)y[j]*k%P*f[j][i]%P+P)%P;
			ans[i]=(ans[i]+(ll)y[j]*k%P*f[j][i]%P*(ans[j]+z[i-j]))%P;
		}
		ans[i]=(ll)(ans[i]+(ll)i*(i-1)/2%P)*Pow(P+1-d[i],P-2)%P;
		z[i]=(ans[i]-(ll)i*(i-1)/2%P+P)%P;
		y[i]=(ll)d[i]*Pow((ll)Pow(p,(ll)i*(i-1)/2%(P-1))*Pow(P+1-p,(ll)i*(i+1)/2%(P-1))%P,P-2)%P;
	}
	cout<<ans[n]<<endl;
	return 0;
}