#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
using namespace std;
typedef long long LL;
const int N=100500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m;
int B[N*2][2],A[N],B0;
void link(int q,int w)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
int Si[N],Six[N];
int dfs(int q,int fa)
{
	Si[q]=1;Six[q]=0;
	efo(i,q)if(B[i][1]!=fa)Si[q]+=dfs(B[i][1],q),Six[q]=max(Six[q],Si[B[i][1]]);
	Six[q]=max(Six[q],n-Si[q]);
	return Si[q];
}
int OK,OK1;
void dfss(int q,int fa)
{
	if(OK)return;
	bool cnt=0;
	efo(i,q)if(B[i][1]!=fa)dfss(B[i][1],q),cnt=1;
	if(!cnt)
	{
		OK=q;OK1=fa;
	}
}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);	
		fo(i,1,n-1)read(q),read(w),link(q,w);
		if(n&1)
		{
			q=B[A[1]][1];
			printf("%d %d\n",1,q);
			printf("%d %d\n",1,q);
			fo(i,1,n)A[i]=0;B0=0;
			continue;
		}
		dfs(1,0);
		q=w=0;
		fo(i,1,n)if(Six[i]*2<=n)
		{
			if(!q)q=i;
			else w=i;
		}
		if(!w)
		{
			q=B[A[1]][1];
			printf("%d %d\n",1,q);
			printf("%d %d\n",1,q);
			fo(i,1,n)A[i]=0;B0=0;
			continue;
		}
		OK=OK1=0;
		dfss(q,w);
		printf("%d %d\n",OK,OK1);
		printf("%d %d\n",OK,w);
		fo(i,1,n)A[i]=0;B0=0;
	}
	return 0;
}/**/