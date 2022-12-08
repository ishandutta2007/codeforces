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
int m,n,ans;
int a[N];
int B[2*N][2],A[N],B0;
bool z[N];
void link(int q,int w)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	int t=getchar(),t1=getchar();
	fo(i,1,5)
	{
		for(q=getchar();q<'0'||q>'Z';q=getchar());
		w=getchar();
		if(q==t||w==t1)return printf("YES\n"),0;
	}
	printf("NO\n");
	return 0;
}