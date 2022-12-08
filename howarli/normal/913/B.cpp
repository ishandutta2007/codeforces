#include <cstdio>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define NX(q) ((q)&(-(q)))
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
int m,n,m1;
LL ans;
int B[2*N][2],A[N],B0,bv[N];
void link(int q,int w)
{
	B[++B0][0]=A[q];A[q]=B0,B[B0][1]=w,++bv[q];
	B[++B0][0]=A[w];A[w]=B0,B[B0][1]=q,++bv[w];
}
bool OK;
void dfs(int q,int fa)
{
	if(bv[q]==1)return;
	int w=0;
	efo(i,q)if(B[i][1]!=fa&&bv[B[i][1]]==1)++w;
	if(w<3)OK=0;
	efo(i,q)if(B[i][1]!=fa)dfs(B[i][1],q);
}
int main()
{
	// freopen("xmastree1.in","r",stdin);
	// freopen("xmastree1.out","w",stdout);
	int q,w,e,__;
	read(n);
	fo(i,2,n)read(w),link(i,w);
	OK=1;
	dfs(1,0);
	if(OK)printf("Yes\n");
	else printf("No\n");
	return 0;
}