#include<cstdio> 
#include<cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define iff() if(B[i][1]!=fa)
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
int n;
int B[N][2],A[N],B0;
int b[N],b1[N];
db ans[N];
void link(int q,int w){B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;}
int dfs1(int q,int fa)
{
	b[q]=1;
	efo(i,q)iff()b[q]+=dfs1(B[i][1],q),b1[q]++;
	return b[q];
}
void dfs2(int q,db s,int fa)
{
	ans[q]=++s;db s1=0.5;
	efo(i,q)iff()dfs2(B[i][1],s+(b[q]-b[B[i][1]]-1)*s1,q);
}
int main()
{
//	freopen("!.in","r",stdin);
	int q,w;
	read(n);
	fo(i,2,n)read(q),link(q,i);
	dfs1(1,0);
	dfs2(1,0,0);
	fo(i,1,n)printf("%.1lf ",ans[i]);
	printf("\n");
	return 0;
}