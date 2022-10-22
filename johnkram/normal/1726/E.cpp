#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define P 998244353
int t,n,i,ans,f[MAXN],g[MAXN],h[MAXN],a[MAXN],p[MAXN];
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int main()
{
	scanf("%d",&t);
	for(i=f[0]=h[0]=p[0]=1;i<MAXN;i++)
	{
		f[i]=(ll)f[i-1]*i%P;
		h[i]=(ll)h[i-1]*((i<<1)-1)%P;
		p[i]=p[i-1]<<1;
		if(p[i]>=P)p[i]-=P;
	}
	for(g[MAXN-1]=Pow(f[MAXN-1],P-2),i=MAXN-2;~i;i--)g[i]=(ll)g[i+1]*(i+1)%P;
	for(i=a[0]=a[1]=1;i<MAXN;i++)a[i]=(a[i-1]+(ll)(i-1)*a[i-2])%P;
	while(t--)
	{
		scanf("%d",&n);
		for(i=ans=0;i<<2<=n;i++)ans=(ans+(ll)f[n-(i<<1)]*g[i<<1]%P*g[n-(i<<2)]%P*h[i]%P*a[n-(i<<2)]%P*p[i])%P;
		printf("%d\n",ans);
	}
	return 0;
}