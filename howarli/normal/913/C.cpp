#include <cstdio>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define NX(q) ((q)&(-(q)))
using namespace std;
typedef long long LL;
const int N=100;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
LL a[N];
LL ans,Ans;
int main()
{
	// freopen("xmastree1.in","r",stdin);
	// freopen("xmastree1.out","w",stdout);
	int q,w,e,__;
	read(n),read(m);q=1;
	fo(i,1,n)scanf("%I64d",&a[i]),q<<=1;q>>=1;
	fo(i,2,n)a[i]=min(a[i],a[i-1]*2LL);
	fod(i,n-1,1)a[i]=min(a[i],a[i+1]);
	Ans=1e18;
	fod(i,n,1)
	{
		for(;m>q;)
		{
			m-=q;ans+=a[i];
		}
		if(m<=q)Ans=min(Ans,ans+a[i]);
		else m-=q,ans=ans+a[i];
		if(m==0)Ans=min(Ans,ans);
		if(m<=q)Ans=min(Ans,ans+a[i]);
		q>>=1;
	}
	printf("%I64d\n",Ans);
	return 0;
}