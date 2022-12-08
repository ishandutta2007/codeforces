#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef double db;
const int N=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
int z[N];
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(m);
	fo(i,1,m)
	{
		printf("1\n");
		fflush(stdout);
		read(w);
		if(!w)return 0;
		if(w==1)z[i]=1;
		else z[i]=0;
	}
	int l=1,r=n;
	q=1;
	for(;l<r;)
	{
		int mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		read(w);
		if(!w)return 0;
		if(!z[q])w*=-1;
		if(w==1)l=mid+1;
		else r=mid-1;
		++q;
		if(q==m+1)q=1;
	}
	printf("%d\n",l);
	fflush(stdout);
	read(w);
	return 0;
}