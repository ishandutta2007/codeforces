#include <cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=200500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
struct qqww
{
	int a,v,i;
}a[N],b[N];
int ans,Ans;
bool PX(qqww q,qqww w){return q.v<w.v;}
bool OK(int t)
{
	int q=0;
	fo(i,1,n)if(a[i].a>=t)b[++q]=a[i];
	sort(b+1,b+1+q,PX);
	int w=m,ans=q;
	fo(i,1,q)
	{
		if(w<b[i].v){ans=i-1;break;}
		w-=b[i].v;
	}
	return ans>=t;
}
int main()
{
	// freopen("!.in","r",stdin);
	// freopen("xmastree1.out","w",stdout);
	int q,w,e;
	read(n),read(m);
	fo(i,1,n)read(a[i].a),read(a[i].v),a[i].i=i;
	int l=0,r=n;
	for(;l<r;)
	{
		int t=(l+r+1)>>1;
		if(OK(t))l=t;
		else r=t-1;
	}
	printf("%d\n",l);
	printf("%d\n",l);
	q=0;
	fo(i,1,n)if(a[i].a>=l)b[++q]=a[i];
	sort(b+1,b+1+q,PX);
	fo(i,1,l)printf("%d ",b[i].i);
	return 0;
}