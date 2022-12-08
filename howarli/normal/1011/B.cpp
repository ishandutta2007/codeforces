#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans,m1;
int a[N],b[N],b1[N];
bool OK(int q)
{
	int w=m;
	fo(i,1,m)b1[i]=b[i];
	fo(i,1,n)
	{
		for(;w&&b1[w]<q;--w);
		if(b1[w]>=q)
		{
			b1[w]-=q;
		}else return 0;
	}
	return 1;
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(m1);
	fo(i,1,m1)read(a[i]);
	sort(a+1,a+1+m1);
	a[0]=-113;
	m=0;
	fo(i,1,m1)
	{
		if(a[i]!=a[i-1])
		{
			b[++m]=1;
		}else
		{
			++b[m];
		}
	}
	int l=0,r=m1;
	for(;l<r;)
	{
		int mid=(l+r+1)>>1;
		if(OK(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}