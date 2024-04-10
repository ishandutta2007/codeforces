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
const int N=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;

int main()
{
	int q,w;
	char ch;
	read(n);
	LL l=1,er=(1LL<<(n-2));
	cout<<1<<' '<<10<<endl;
	for(ch=' ';ch<'a'||ch>'z';ch=getchar());
	int L=(ch=='b');fo(II,1,4)ch=getchar();
	if(n==1)return printf("%d %d %d %d\n",0,0,1,1),0;
	LL r;
	for(--n;n;--n)
	{
		// printf("%d %d\n",i,10);
		r=l+er;er>>=1;
		cout<<r<<' '<<10<<endl;
		for(ch=' ';ch<'a'||ch>'z';ch=getchar());
		int R=(ch=='b');fo(II,1,4)ch=getchar();
		if(R!=L)break;
		l=r;
	}
	++l,--r;
	for(--n;n>0;--n)
	{
		int mid=(l+r)>>1;
		cout<<mid<<' '<<10<<endl;
		for(ch=' ';ch<'a'||ch>'z';ch=getchar());
		int nw=(ch=='b');fo(II,1,4)ch=getchar();
		if(nw!=L)r=mid-1;
		else l=mid+1;
	}
	// printf("%d %d %d %d\n",l+1,11,l,9);
	cout<<l<<' '<<11<<' '<<l-1<<' '<<9<<endl;
	return 0;
}