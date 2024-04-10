#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
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
int m,n,n1,ans;
int a[N];
LL f[N];
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
int main()
{
	int q,w;
	read(n),read(n1);
	fo(i,1,n)read(a[i]);
	m=1;
	f[1]=-1;f[0]=a[1];
	fo(i,2,n)
	{
		++m;
		fod(j,m,1)f[j]=(f[j]*(LL)a[i]-f[j-1])%mo;
		f[0]=f[0]*a[i]%mo;
	}
	ans=0;
	LL t=1;
	fo(i,0,m)
	{
		if(n1-i<0)break;
		ans=(ans+t*ksm(n,n1-i)%mo*f[i])%mo;
		t=t*(LL)(n1-i)%mo;
	}
	ans=ans*ksm(ksm(n,n1),mo-2)%mo;
	t=1;
	fo(i,1,n)t=t*a[i]%mo;
	printf("%I64d\n",(t-ans+mo)%mo);
	return 0;
}