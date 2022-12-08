#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=100500,mo=1e9+7;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
LL ans;
int a[N];
LL d1[N][2],d10;
LL d[N];
int f[N],g[N];
LL b[N];
LL ny[N];
void FJ(LL q)
{
	for(LL i=2;i*i<=q;++i)if(q%i==0)
	{
		d1[++d10][0]=i;
		for(;q%i==0;q/=i)++d1[d10][1];
	}
	if(q)d1[++d10][0]=q,d1[d10][1]=1;
}
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
LL doit(LL n,int m)
{
	fo(i,0,m)f[i]=0;
	f[m]=1;
	fo(I,1,(::m))
	{
		fo(i,0,m)
		{
			LL t=(LL)f[i]*ny[i+1]%mo;
			fo(j,0,i)((g[j]+=t)>=mo?g[j]-=mo:0);
		}
		fo(i,0,m)f[i]=g[i],g[i]=0;
	}
	LL ans=0;
	LL t=1;
	fo(i,0,m)
	{
		ans=(ans+(LL)t*f[i])%mo;
		t=t*n%mo;
	}
	return ans;
}
int main()
{
	int q,w;
	LL t;
	scanf("%lld%d",&t,&m);
	FJ(t);
	fo(i,1,100)ny[i]=ksm(i,mo-2);
	ans=1;
	fo(i,1,d10)
	{
		ans=ans*doit(d1[i][0],d1[i][1])%mo;
	}
	printf("%lld\n",ans);
	return 0;
}