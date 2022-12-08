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
void ss(int q,int e)
{
	if(ans)return;
	if(q>n)
	{
		if((e%360+360)%360==0)ans=1;
		return;
	}
	ss(q+1,e+a[q]);
	ss(q+1,e-a[q]);
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n);
	fo(i,1,n)read(a[i]);
	ss(1,0);
	if(ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}